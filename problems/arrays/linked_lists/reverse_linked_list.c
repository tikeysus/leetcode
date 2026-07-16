/*
Problem: reverse linked list
Link:
Difficulty:
Topic(s):
Pattern:

Description:
Given the head of a singly linked list, reverse the list, and return the reversed list.

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

struct ListNode* reverseList(struct ListNode* head) {
    struct ListNode *current = head;
    struct ListNode *following = head;	
    struct ListNode *previous = NULL;

    while (current != NULL){
        following = following->next;
        current->next = previous; 
        previous = current; 
        current = following;
    }

    return previous; 
}