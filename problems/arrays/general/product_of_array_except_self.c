/*
Problem: Product of Array Except Self
Link:
Difficulty: Medium 
Topic(s):
Pattern: Except Self

Description:
Given an integer array nums, return an array answer such that answer[i] is equal to the product of all the elements of nums except nums[i].
The product of any prefix or suffix of nums is guaranteed to fit in a 32-bit integer.
You must write an algorithm that runs in O(n) time and without using the division operation.

Constraints:
2 <= nums.length <= 105
-30 <= nums[i] <= 30
The input is generated such that answer[i] is guaranteed to fit in a 32-bit integer.

Initial idea:
Initial idea was to calculate the cumulative product at the start and then fake division through subtraction. But this can't work because 
if there is a zero in the array that needs special consideration. 

Final approach:
Got a little hint from GPT. These problems that follow the pattern "except self" require separate consideration of suffixes and prefixes. Noted for next time. 

Complexity:
Time:
Space:

Mistakes / difficulties:
I did not consider negative numbers

Key lesson:

Review:
- Solved on: April 28th. 
- Revisit:
*/

#include <stdio.h>
#include <stdlib.h>

int* prefix_arr(int* nums, int numsSize, int* returnSize){
	int* prefix_arr = malloc(numsSize * sizeof(int)); 
	int product = nums[0]; 
	prefix_arr[0] = 1; 
	for (int i = 1; i < numsSize; i++){
		prefix_arr[i] = product;
		product *= nums[i];
	}
	
	*returnSize = numsSize; 
	return prefix_arr; 
}

int* suffix_arr(int* nums, int numsSize, int* returnSize){
	int* suffix_arr = malloc(numsSize * sizeof(int)); 
	int product = nums[numsSize - 1]; 
	suffix_arr[numsSize - 1] = 1; 
	for (int i = numsSize - 2; i >= 0; i--){
		suffix_arr[i] = product; 
		product *= nums[i]; 
	}

	*returnSize = numsSize; 
	return suffix_arr; 
}

int* productExceptSelf(int* nums, int numsSize, int* returnSize) {
	int* prefix_array = prefix_arr(nums, numsSize, returnSize); 
	int* suffix_array = suffix_arr(nums, numsSize, returnSize); 
	int* res = malloc(numsSize * sizeof(int)); 

	for (int i = 0; i < numsSize; i++){
		res[i] = prefix_array[i] * suffix_array[i]; 
	}

	*returnSize = numsSize; 
	return res; 
}

int main(){
    int nums[] = {1,2,3,4}; 
    int returnSize; 
    int* res = productExceptSelf(nums, 4, &returnSize); 
    printf("[%d, %d, %d, %d]\n", res[0], res[1], res[2], res[3]);

    free(res); 
    return 0; 
}