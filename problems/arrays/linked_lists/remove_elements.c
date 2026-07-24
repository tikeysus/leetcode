/*
Problem: remove elements
Link:
Difficulty:
Topic(s):
Pattern:

Description:
Given the head of a linked list and an integer val, remove all the nodes of the linked list that has Node.val == val, and return the new head.

Constraints:

Initial idea:
Let's try and use a dummy list at the start.

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

#include <stdlib.h>

struct ListNode {
	int val;
	struct ListNode *next;
};

struct ListNode* removeElements(struct ListNode* head, int val) {
    if (head == NULL){ return NULL; }
	struct ListNode* fast = head; 
	struct ListNode* slow = head; 
	while (head != NULL && head->val == val){
		struct ListNode* temp = head; 
		head = head->next; 
		slow = head; 
		fast = head; 
		free(temp); 
	}
    if (head == NULL){ return NULL; }
	if (head->next == NULL){
		if (head->val == val){ return NULL; }
		else{ return head; }
	}
	fast = fast->next; 
	while (fast->next != NULL){
		if (fast->val != val){
			slow = slow->next; 
			fast = fast->next; 
		}
		else{
			struct ListNode* temp = fast; 
			slow->next = fast->next; 
			fast = fast->next; 
			free(temp); 
		}
	}
	if (fast->val == val){
		struct ListNode* temp = fast; 
		slow->next = NULL; 
		free(temp); 
	}
	return head; 
}