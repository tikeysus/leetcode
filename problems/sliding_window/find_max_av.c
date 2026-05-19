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
This is an easier version of the sliding window, window size is fixed and we only have to 
consider contiguous elements. 
Now I have to see if there are more optimal ways of doing this. 

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

double array_average(int* nums, int left, int right, int k){
	double average = 0; 
	for (int i = left; i <= right; i++){
		average += nums[i]; 
	}
	return average/k; 
}

double findMaxAverage(int* nums, int numsSize, int k) {
	double max_average = 0; 
	int left = 0; 
	int right = k - 1; 
	while (right != numsSize){
		double average = array_average(nums, left, right, k); 
		if (average > max_average){
			max_average = average; 
		}
		left++; 
		right++; 
	}
	return max_average; 
}

int main(){
	int nums[] = {-1};
	int k = 1; 
	double max_average = findMaxAverage(nums, 1, k); 
	printf("%f\n", max_average); 

	return 0; 
}