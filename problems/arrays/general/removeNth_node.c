/*
Problem: removeNth node
Link:
Difficulty:
Topic(s):
Pattern:

Description:
Given the head of a linked list, remove the nth node from the end of the list and return its head.

Constraints:

Initial idea:

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

int node_len(struct ListNode* head){
	int sz = 0; 
	for (int i = 0; (head->next) != NULL; i++){
		head = head->next; 
		sz++; 
	}
	return sz; 
}

struct ListNode* removeNthFromEnd(struct ListNode* head, int n) {
    int sz = node_len(head);
    
    if (n == sz) {
        struct ListNode* temp = head->next;
        free(head);
        return temp;
    }
    
    struct ListNode* current = head;
    for (int i = 0; i < (sz - n - 1); i++) {
        current = current->next;
    }
    
    current->next = current->next->next;
    free(current->next);  
    
    return head;
}