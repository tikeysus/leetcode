/*
Problem: counting bits
Link:
Difficulty: Easy 
Topic(s):
Pattern:

Description:
Given an integer n, return an array ans of length n + 1 such that for each i (0 <= i <= n), ans[i] is the number of 1's in the binary representation of i.

Constraints:

Initial idea:
Let's traverse through the array and call hamming weight each time. Get a solution and then try to look for something 
more optimal after having done so. 

Final approach:

Complexity:
Initial solution has a complexity of nlogn, the challenge is to do this in linear time. 
Time:
Space:

Mistakes / difficulties:

Key lesson:

Review:
- Solved on:
- Revisit:
*/

#include <stdio.h>
#include "hamming_weight.h"
#include <stdlib.h>

int* countBits(int n, int* returnSize) {
    int* res = malloc((n+1) * sizeof(int)); 
	*returnSize = n + 1;

	int i = 0; 
	while (i <= n){
		res[i] = hammingWeight(i); 
		i++; 
	}

	return res; 
}

int main(){
	int n = 2; 
	int returnSize;
	int* res = countBits(n, &returnSize); 
	for (int i = 0; i < returnSize; i++){
		printf("%d,", res[i]); 
	}
	printf("\n");
	free(res); 
	
	
	return 0; 
}