/*
Problem: search range
Link:
Difficulty:
Topic(s):
Pattern:

Description:

Constraints:

Initial idea:
Given an array of integers nums sorted in non-decreasing order, find the starting and ending position of a given target value.
If target is not found in the array, return [-1, -1].
You must write an algorithm with O(log n) runtime complexity.

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

int* searchRange(int* nums, int numsSize, int target, int* returnSize) {
	int* res = malloc(2 * sizeof(int)); 
	res[0] = -1; res[1] = -1;
	
	int left = 0; int right = numsSize - 1; int mid; 
	while (left <= right){
		mid = left + (right - left)/2; 
		if (nums[mid] == target){
			if (res[0] != -1) { res[1] = mid; }
			else if (res[1] != -1) { res[0] = mid; }
			else if (res[0] == -1 && res[1] == -1) {  }
			else { break; }
		}
	}
}