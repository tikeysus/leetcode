/*
Problem: move zeros
Link:
Difficulty:
Topic(s):
Pattern:

Description:
Given an integer array nums, move all 0's to the end of it while maintaining the relative order of the non-zero elements.
Note that you must do this in-place without making a copy of the array.

Constraints:

Initial idea:
Some way of identifying the index of the current element (i) and the index of the outer bound of the array (this moves back each time we move a zero). 

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

void moveZeroes(int* nums, int numsSize) {
	int left = 0; 
	while (left < numsSize - 1){
		if (nums[left] == 0){
			int old_index = left; 
			while (left <= numsSize - 1 && nums[left] == 0){
				left++; 
			}
			if (left == numsSize && nums[left - 1] == 0){ break; }
			int temp = nums[left]; 
			nums[old_index] = temp; 
			nums[left] = 0; 
			left = old_index + 1; 
		}
		else{
			left++; 
		}
	}
}

int main(){
	int nums[] = {31,2,0,0,2,1,3}; 
	int numsSize = 7; 
	moveZeroes(nums, numsSize); 
	for (int i = 0; i < numsSize; i++){
		printf("%d,", nums[i]); 
	}
	printf("\n"); 

	return 0; 
}