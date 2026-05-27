/*
Problem: subsets
Link:
Difficulty: Medium
Topic(s):
Pattern:

Description:
Given an integer array nums of unique elements, return all possible subsets (the power set).
The solution set must not contain duplicate subsets. Return the solution in any order.

Constraints:

Initial idea:

Final approach:
Had to look at a solution for this. In hindsight, it's pretty obvious. 
Very messy implementation, will come back and aim for something more elegant. 

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

int main(){
	int nums[] = {1,2,3}; 
    int numsSize = 3; 
	int returnSize; 
    int* returnColumnSizes; 
    int** res = subsets(nums, numsSize, &returnSize, &returnColumnSizes); 


    printf("["); 
    for (int i = 0; i < returnSize; i++){
        for (int j = 0; j < returnColumnSizes[i]; j++){
            printf("%d,", res[i][j]); 
        }
    }
    printf("]\n"); 

	printf("["); 
    for (int i = 0; i < returnSize; i++){
		printf("%d,", returnColumnSizes[i]); 
    }
    printf("]\n"); 

	free(res); 
    return 0; 
}