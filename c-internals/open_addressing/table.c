#include <stdlib.h>
#include <string.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>

#include "table.h"
#include "hash.h"

#define TABLE_MAX_LOAD 0.75
#define GROW_CAPACITY(cap) (((cap) < 8) ? 8 : ((cap) * 2))

size_t key_length(char* key){
	size_t count = 0; 
	int i = 0; 
	while(key[i] != '\0'){ count++; i++; }
	return count;
}

void init_table(Table* table) {
	table->count = 0;
	table->capacity = 0;
	table->entries = NULL;
}

void free_table(Table* table) {
	free(table->entries);
	init_table(table); 
}

static Entry* find_entry(Entry* entries, int capacity, char* key) {
	uint32_t index = hash_string(key, key_length(key)) % capacity;
	Entry* tombstone = NULL;

	for (;;){
		Entry* entry = &entries[index];
		if (entry->key == NULL) {
			if (entry->is_tombstone) {
				// We found a tombstone.
				if (tombstone == NULL) tombstone = entry;
			} 
			else {
				// Empty entry.
				if (tombstone != NULL) return tombstone; 
				return entry; 
			}
		} 
		else if (strcmp(entry->key, key) == 0) {
			return entry;
		}

		index = (index + 1) % capacity;
	}
}

void adjust_capacity(Table* table, int capacity) {
	Entry* entries = malloc(capacity * sizeof(Entry)); 
	if (entries == NULL){
		fprintf(stderr, "Allocation failed!\n"); 
		return; 
	}
	for (int i = 0; i < capacity; i++) {
		entries[i].key = NULL;
		entries[i].is_tombstone = false;
	}

 	table->count = 0;
	for (int i = 0; i < table->capacity; i++) {
		Entry* entry = &table->entries[i];
		if (entry->key == NULL) continue;

		Entry* dest = find_entry(entries, capacity, entry->key);
		dest->key = entry->key;
		dest->value = entry->value;
		table->count++; 
  	}
	free(table->entries);

	table->entries = entries;
	table->capacity = capacity;
}

bool table_set(Table* table, char* key, int value){
	if (table->count + 1 > table->capacity * TABLE_MAX_LOAD){
		int capacity = GROW_CAPACITY(table->capacity); 
		adjust_capacity(table, capacity); 
	}

	Entry* entry = find_entry(table->entries, table->capacity, key);

	bool is_new_key = false;
	if (entry->key == NULL) { is_new_key = true; }
  	if (is_new_key && !entry->is_tombstone) table->count++;

  	entry->key = key;
  	entry->value = value;
  	return is_new_key;
}

bool table_get(Table* table, char* key, int* value) {
	if (table->count == 0) return false;

	Entry* entry = find_entry(table->entries, table->capacity, key);
	if (entry->key == NULL) return false;

	*value = entry->value;
	return true;
}

bool table_delete(Table* table, char* key) {
	if (table->count == 0) return false;

	// Find the entry.
	Entry* entry = find_entry(table->entries, table->capacity, key);
	if (entry->key == NULL) return false;

	// Place a tombstone in the entry.
	entry->key = NULL;
	entry->is_tombstone = true; 
	return true;
}