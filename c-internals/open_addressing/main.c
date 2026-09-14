#include <stdio.h>
#include <string.h>

#include "table.h"

static int checks_run = 0;
static int checks_failed = 0;

#define CHECK(cond) do { \
	checks_run++; \
	if (!(cond)) { \
		checks_failed++; \
		printf("FAIL: %s (line %d)\n", #cond, __LINE__); \
	} \
} while (0)

int main(void) {
	Table table;
	init_table(&table);

	int value = 0;

	// Get on an empty table.
	CHECK(table_get(&table, "missing", &value) == false);

	// Basic set/get.
	CHECK(table_set(&table, "one", 1) == true);
	CHECK(table_set(&table, "two", 2) == true);
	CHECK(table_set(&table, "three", 3) == true);
	CHECK(table.count == 3);

	CHECK(table_get(&table, "one", &value) == true && value == 1);
	CHECK(table_get(&table, "two", &value) == true && value == 2);
	CHECK(table_get(&table, "three", &value) == true && value == 3);
	CHECK(table_get(&table, "four", &value) == false);

	// Overwriting an existing key returns false and updates the value.
	CHECK(table_set(&table, "one", 100) == false);
	CHECK(table.count == 3);
	CHECK(table_get(&table, "one", &value) == true && value == 100);

	// Delete, then confirm it's gone but the count-free-slot still probes correctly.
	CHECK(table_delete(&table, "two") == true);
	CHECK(table_get(&table, "two", &value) == false);
	CHECK(table_delete(&table, "two") == false);
	CHECK(table_get(&table, "three", &value) == true && value == 3);

	// Re-inserting a deleted key should reuse the tombstone slot.
	CHECK(table_set(&table, "two", 22) == true);
	CHECK(table_get(&table, "two", &value) == true && value == 22);

	// Force growth past the 0.75 load factor threshold and confirm everything
	// is still reachable afterward.
	char key_buf[16];
	for (int i = 0; i < 50; i++) {
		snprintf(key_buf, sizeof(key_buf), "key%d", i);
		table_set(&table, key_buf, i);
	}
	for (int i = 0; i < 50; i++) {
		snprintf(key_buf, sizeof(key_buf), "key%d", i);
		CHECK(table_get(&table, key_buf, &value) == true && value == i);
	}
	CHECK(table_get(&table, "one", &value) == true && value == 100);
	CHECK(table_get(&table, "three", &value) == true && value == 3);

	free_table(&table);
	CHECK(table.count == 0);
	CHECK(table.capacity == 0);

	printf("%d/%d checks passed\n", checks_run - checks_failed, checks_run);
	return checks_failed == 0 ? 0 : 1;
}
