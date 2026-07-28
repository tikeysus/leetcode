/*
Problem: rotated binary search
Link:
Difficulty:
Topic(s):
Pattern:

Description:
There is an integer array nums sorted in ascending order (with distinct values).
Prior to being passed to your function, nums is possibly left rotated at an unknown index k (1 <= k < nums.length) such that the resulting array is [nums[k], nums[k+1], ..., nums[n-1], nums[0], nums[1], ..., nums[k-1]] (0-indexed). For example, [0,1,2,4,5,6,7] might be left rotated by 3 indices and become [4,5,6,7,0,1,2].
Given the array nums after the possible rotation and an integer target, return the index of target if it is in nums, or -1 if it is not in nums.
You must write an algorithm with O(log n) runtime complexity.

Constraints:

Initial idea:
Try to enforce the nature of a sorted array by checking the elements around mid. Let's see...
Here's an observation: after the rotation we are left with two sorted arrays, but these don't always center around mid...

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

int search_recursive(int* nums, int left, int right, int target){
	int mid; 
	while (left <= right){
		mid = left + (right-left)/2; 
		if (nums[mid] == target) { return mid; }
		else{
			return search_recursive(nums, left, mid - 1, target) + search_recursive(nums, mid + 1, right, target) + 1; 
		}
	}
	return -1; 		
}


int search(int* nums, int numsSize, int target) {
	return search_recursive(nums, 0, numsSize - 1, target);
}

int main(){
	int nums[] = {7,0,1,2,4,5,6}; 
	int numsSize = 7; 
	int target = 12;
	int res = search(nums, numsSize, target); 
	printf("%d\n", res); 
	return 0; 
}