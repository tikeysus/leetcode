/*
Problem: subset xor sum
Link:
Difficulty: Easy 
Topic(s):
Pattern:

Description:
The XOR total of an array is defined as the bitwise XOR of all its elements, or 0 if the array is empty.

For example, the XOR total of the array [2,5,6] is 2 XOR 5 XOR 6 = 1.
Given an array nums, return the sum of all XOR totals for every subset of nums. 
Note: Subsets with the same elements should be counted multiple times.
An array a is a subset of an array b if a can be obtained from b by deleting some (possibly zero) elements of b.

Constraints:

Initial idea:
Will use the subset function that I solved for in another problem, call it each time and maintain a running sum. 

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

int** subsets(int* nums, int numsSize, int* returnSize, int** returnColumnSizes) {
	int** res = malloc((1 << numsSize) * sizeof(int *)); 
	*returnSize = 1 << numsSize;
	*returnColumnSizes = malloc((1 << numsSize) * sizeof(int)); 
	for (int i = 0; i < (1 << numsSize); i++){
		int count = 0; 
		for (int j = 0; j < numsSize; j++){
			if ((i & (1 << j)) != 0){
				count++; 
			}
		}
		res[i] = malloc(count * sizeof(int)); 
		(*returnColumnSizes)[i] = count; 

		int ind_count = 0; 
		for (int j = 0; j < numsSize; j++){
			if ((i & (1 << j)) != 0){
				res[i][ind_count] = nums[j]; 
				ind_count++; 
			}
		}
	}

	return res; 
}

int subsetXORSum(int* nums, int numsSize) {
	int returnSize; 
	int* returnColumnSizes; 
    int** res = subsets(nums, numsSize, &returnSize, &returnColumnSizes); 
	int total_sum = 0; 
	for (int i = 0; i < returnSize; i++){
		int sum = 0; 
		for (int j = 0; j < returnColumnSizes[i]; j++){
			sum ^= res[i][j]; 
		}
		total_sum += sum; 
	}
	
	free(res); 
	return total_sum; 
}

int main(){
	int nums[] = {1,3}; 
	int numsSize = 2; 
	int res = subsetXORSum(nums, numsSize); 
	printf("%d\n", res); 
	return 0; 
}