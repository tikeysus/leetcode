/*
Problem: rotate array
Link:
Difficulty:
Topic(s):
Pattern:

Description:
Given an integer array nums, rotate the array to the right by k steps, where k is non-negative.

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

#include <stdio.h>

void rotate(int* nums, int numsSize, int k) {
    if (numsSize == 1) { return; }
	int res[numsSize]; 

    if (k >= numsSize) { k = k % numsSize; }
	for (int i = numsSize - k, j = 0; i < numsSize; i++, j++){
		res[j] = nums[i]; 
	}
	for (int i = 0, j = k; i < numsSize - k; i++, j++){
		res[j] = nums[i]; 
	}
	for (int i = 0; i < numsSize; i++){
		nums[i] = res[i]; 
	}
}
