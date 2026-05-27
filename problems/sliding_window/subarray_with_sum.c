/*
Problem: subarray with sum
Link:
Difficulty: Medium
Topic(s):
Pattern: Sliding Window

Description:
Given a binary array nums and an integer goal, return the number of non-empty subarrays with a sum goal.
A subarray is a contiguous part of the array.

Constraints:

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

int numSubarraysWithSum(int* nums, int numsSize, int goal) {
    int count = 0; 
	int running_sum = 0; 

	int left = 0;
	for (int right = 0; right < numsSize; right++){
		running_sum += nums[right]; 
		if (running_sum == goal){
			count++; 
		}

		if (nums[right] == goal){
			count++;
			continue; 
		}

		else if (running_sum > goal){
			while (running_sum > goal){
				running_sum -= nums[left]; 
				left++; 
			}
			count++;
		}
	}
	return count;
}

int main(){
	int nums[] = {1,0,1,0,1};
	int goal = 2; 
	int numsSize = 5; 
	int count = numSubarraysWithSum(nums, numsSize, goal);
	printf("%d\n", count); 
	return 0; 
}