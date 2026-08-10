/*
Problem: subarray sum
Link:
Difficulty:
Topic(s):
Pattern:

Description:
A subarray is a contiguous non-empty sequence of elements within an array.
Given an array of integers nums and an integer k, return the total number of subarrays whose sum equals to k.

Constraints:

Initial idea:
I don't see a way of doing this with dictionaries for now, I will try using two pointers. 
Let's try the naive approach first and see if we learn anything from that (probably not). 

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

int subarraySum(int* nums, int numsSize, int k) {
	int count = 0; 
	for (int i = 0; i < numsSize; i++){
		int sum = 0; 
		for (int j = i; j < numsSize; j++){
			sum += nums[j]; 
			if (sum == k){ count ++; }
		}
	}
	return count; 
}

int main(){
	int nums[] = {6,4,3,1}; 
	int numsSize = 4; 
	int k = 10; 
	int res = subarraySum(nums, numsSize, k); 
	printf("%d\n", res); 
	return 0; 
}