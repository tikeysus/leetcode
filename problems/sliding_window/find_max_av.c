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

double array_average(int* nums, int numsSize){
	double average = 0; 
	for (int i = 0; i < numsSize; i++){
		average += nums[i]; 
	}
	return average/numsSize; 
}

double array_sum(int* nums, int numsSize){
	double arr_sum = 0; 
	for (int i = 0; i < numsSize; i++){
		arr_sum += nums[i];
	}
	return arr_sum; 
}

double findMaxAverage(int* nums, int numsSize, int k) {
	if (numsSize == 1){
		return nums[0]; 
	}
	if (numsSize == k){
		return array_average(nums, numsSize); 
	}
	double max_average;
	int left = 0; 
	int right = k - 1; 
	double running_sum = array_sum(nums, k); 
	double window_average = running_sum/k; 
	while (right != numsSize - 1){
		if (window_average > max_average || left == 0){
			max_average = window_average; 
		}
		running_sum -= nums[left]; 
		running_sum += nums[right + 1]; 
		window_average = running_sum/k; 
		left++; 
		right++; 
	}
	if (window_average > max_average){
		return running_sum/k; 
	}
	return max_average; 
}

int main(){
	int nums[] = {8860,-853,6534,4477,-4589,8646,-6155,-5577,-1656,-5779,-2619,-8604,-1358,-8009,4983,7063,3104,-1560,4080,2763,5616,-2375,2848,1394,-7173,-5225,-8244,-809,8025,-4072,-4391,-9579,1407,6700,2421,-6685,5481,-1732,-8892,-6645,3077,3287,-4149,8701,-4393,-9070,-1777,2237,-3253,-506,-4931,-7366,-8132,5406,-6300,-275,-1908,67,3569,1433,-7262,-437,8303,4498,-379,3054,-6285,4203,6908,4433,3077,2288,9733,-8067,3007,9725,9669,1362,-2561,-4225,5442,-9006,-429,160,-9234,-4444,3586,-5711,-9506,-79,-4418,-4348,-5891};
	int k = 93; 
	int numsSize = 93; 
	double max_average = findMaxAverage(nums, numsSize, k); 
	printf("%f\n", max_average); 

	return 0; 
}