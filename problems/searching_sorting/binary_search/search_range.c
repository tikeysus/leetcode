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

#include <stdio.h>
#include <stdlib.h>

int* searchRange(int* nums, int numsSize, int target, int* returnSize) {
	*returnSize = 2; 
	int* res = malloc(2 * sizeof(int)); 
	res[0] = -1; res[1] = -1;
	
	int leftmost = 0; int rightmost = numsSize - 1; 
	int left = 0; int right = numsSize - 1; int mid; 
	while (left <= right){
		mid = left + (right - left)/2; 
		if (nums[mid] < target){
			left = mid + 1; 
		}
		else if (nums[mid] > target){
			right = mid - 1; 
		}
		else if (nums[mid] == target){ //let's see
			left = mid + 1; 
			if (nums[leftmost] < target) {leftmost++;}
			if (nums[rightmost] > target) {rightmost--;}
		}
	}
	res[0] = leftmost; 
	res[1] = rightmost; 
	return res; 
}

int main(){
	int nums[] = {5,7,7,8,8,10}; 
	int numsSize = 6; 
	int target = 8; 
	int returnSize;
	int* res = searchRange(nums, numsSize, target, &returnSize); 
	printf("%d, %d\n", res[0], res[1]); 
	free(res); 

	return 0; 
}