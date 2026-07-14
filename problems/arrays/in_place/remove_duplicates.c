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
	int i = 1; 
	int curr_num = nums[0]; 
	int curr_num_index = 0; 

	while (i < numsSize){
		if (nums[i] > curr_num){
			k++; 
			curr_num = nums[i]; 
			curr_num_index = i; 
			i++; 
			continue; 
		}
		while (i < numsSize && nums[i] <= curr_num){
			i++; 
		}
		if (i == numsSize && nums[i - 1] <= curr_num){ break; }
		k++; 

		int temp = nums[i]; 
		nums[curr_num_index + 1] = temp; 
		nums[i] = curr_num; 

		curr_num = nums[curr_num_index + 1]; 
		curr_num_index++; 
		i = curr_num_index; 
	}

	return k; 
}

int main(){
	int nums[] = {1,2}; 
	int numsSize = 2; 
	int res = removeDuplicates(nums, numsSize); 
	// for (int i = 0; i < numsSize; i++){
	// 	printf("%d,", nums[i]); 
	// }
	printf("%d\n", res); 

	return 0; 
}