/*
Problem: find max av
Link:
Difficulty: Easy
Topic(s):
Pattern:

Description:
You are given an integer array nums consisting of n elements, and an integer k.

Find a contiguous subarray whose length is equal to k that has the maximum average value and return this value. Any answer with a calculation error less than 10-5 will be accepted.

Constraints:
n == nums.length
1 <= k <= n <= 105
-104 <= nums[i] <= 104

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

double findMaxAverage(int* nums, int numsSize, int k) {
    
}

int main(){
	int nums[] = {1,12,-5,-6,50,3};
	int k = 4; 
	double max_average = findMaxAverage(nums, 6, 4); 
	printf("%d\n", max_average); 

	return 0; 
}