/*
Problem: remove duplicates
Link:
Difficulty:
Topic(s):
Pattern:

Description:
Given an integer array nums sorted in non-decreasing order, remove the duplicates in-place such that each unique element appears only once. The relative order of the elements should be kept the same.
Consider the number of unique elements in nums to be k​​​​​​​​​​​​​​. After removing duplicates, return the number of unique elements k.
The first k elements of nums should contain the unique numbers in sorted order. The remaining elements beyond index k - 1 can be ignored.

Constraints:

Initial idea:
The swap is the hardest step, it's a thinker. 

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

int removeDuplicates(int* nums, int numsSize) {
	int k = 1; 
	int left = 0; 
	int right = 0; 
	while 
}

int main(){
	int nums[] = {1,1,2,2,3}; 
	int numsSize = 5; 
	moveZeroes(nums, numsSize); 
	for (int i = 0; i < numsSize; i++){
		printf("%d,", nums[i]); 
	}
	printf("\n"); 

	return 0; 
}