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

#include <stdlib.h>

void moveZeroes(int* nums, int numsSize) {
    int left_edge = 0; 
	int i = 0; 
	while (left_edge < numsSize - 1){
		if (nums[i] == 0){
			int old = nums[i]; 
			int new = nums[i + 1]; 
			nums[i] = new; 
			nums[i + 1] = old; 
		}
	}
}

int main(){
	int nums[] = {0,1,0,3,12}; 
	int numsSize = 5; 
	moveZeroes(nums, numsSize); 
	for (int i = 0; i < numsSize; i++){
		printf("%d,", nums[i]); 
	}
	printf("\n"); 

	return 0; 
}