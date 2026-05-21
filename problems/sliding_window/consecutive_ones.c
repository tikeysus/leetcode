/*
Problem: consecutive ones
Link:
Difficulty:
Topic(s):
Pattern: Sliding Window

Description:
Given a binary array nums, return the maximum number of consecutive 1's in the array.

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

int findMaxConsecutiveOnes(int* nums, int numsSize) {
    int max_window = 0; 
	int current_window = 0; 
	for (int i = 0; i < numsSize; i++){
		if (nums[i] == 1){
			current_window++; 
		}
		else{
			current_window = 0; 
		}
		if (current_window > max_window){
			max_window = current_window; 
		}
	}
	return max_window; 
}

int main(){
	int nums[] = {1,0,1,1,0,1}; 
	int numsSize = 6; 
	int res = findMaxConsecutiveOnes(nums, numsSize); 
	printf("%d\n", res);
	return 0; 
}