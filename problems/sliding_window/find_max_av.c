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
I will have to come back to this, this solution is way too messy. 

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
	double running_sum = 0; 
	for (int i = 0; i < k; i++){
		running_sum += nums[i]; 
	}
	double max_sum = running_sum;
	
	for (int right = k; right < numsSize; right++){
		running_sum += nums[right]; 
		running_sum -= nums[right - k]; 

		if (running_sum > max_sum){
			max_sum = running_sum;
		}
	}
	
	return max_sum/k; 
}

int main(){
	int nums[] = {50};
	int k = 1; 
	int numsSize = 1; 
	double max_average = findMaxAverage(nums, numsSize, k); 
	printf("%f\n", max_average); 

	return 0; 
}