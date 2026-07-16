/*
Problem: merge sorted lists
Link:
Difficulty:
Topic(s):
Pattern:

Description:
You are given the heads of two sorted linked lists list1 and list2.
Merge the two lists into one sorted list. The list should be made by splicing together the nodes of the first two lists.
Return the head of the merged linked list.

Constraints:

Initial idea:
After a brief recap of structs, let's work some recursion with this. 

Final approach:

Complexity:
Time:
Space:

Mistakes / difficulties:

Key lesson:

Review:
- Solved on:
- Revisit:
*/

/**
 * Definition for singly-linked list.
 */

#include <stdio.h>
#include <stdlib.h>

struct ListNode {
	int val;
	struct ListNode *next;
};

struct ListNode* mergeTwoListsRecursive(struct ListNode* list1, struct ListNode* list2, struct ListNode* acc) {
	int list1_finished = 0; 
	int list2_finished = 0; 
	if (list1 == NULL){ list1_finished = 1; }
	if (list2 == NULL){ list2_finished = 1; }
	
	if (list1_finished && list2_finished) { 
		return acc; 
	}
	else if (list1_finished && !list2_finished) { 
		acc->val = list2->val;
		acc->next = list2->next; 
		return acc;
	}
	else if (!list1_finished && list2_finished) { 
		acc->val = list1->val;
		acc->next = list1->next;
		return acc; 
	}

	if (list1->val <= list2->val){
		acc->val = list1->val;
		struct ListNode *new_node = malloc(sizeof(struct ListNode));
		new_node->next = NULL;
		acc->next = new_node;
		return mergeTwoListsRecursive(list1->next, list2, new_node); 
	}
	else{
		acc->val = list2->val;
		struct ListNode *new_node = malloc(sizeof(struct ListNode));
		new_node->next = NULL;
		acc->next = new_node;
		return mergeTwoListsRecursive(list1, list2->next, new_node); 
	}
}

struct ListNode* mergeTwoLists(struct ListNode* list1, struct ListNode* list2) {
	if (list1 == NULL){
		return list2; 
	}
	else if (list2 == NULL){
		return list1; 
	}
	
	struct ListNode *acc = malloc(sizeof(struct ListNode)); 
	acc->next = NULL;
	struct ListNode *head = acc; 
	mergeTwoListsRecursive(list1, list2, acc); 
	return head; 
}