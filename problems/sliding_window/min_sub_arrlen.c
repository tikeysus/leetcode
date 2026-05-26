/*
Problem: min sub arrlen
Link:
Difficulty: Medium 
Topic(s):
Pattern: Sliding Window 

Description:
Given an array of positive integers nums and a positive integer target, return the minimal length of a subarray whose sum is greater than or equal to target. If there is no such subarray, return 0 instead.

Constraints:
1 <= target <= 109
1 <= nums.length <= 105
1 <= nums[i] <= 104

Initial idea:
The pattern is a sliding window, but I need to see how and when the window should be shrinked or expanded.
As well, the optimal solution needs to be considered. 

Final approach:

Complexity:
Time:
Space:

Mistakes / difficulties:
Do not be afraid of intermixing while and for loops, it's not the end of the world.

Key lesson:

Review:
- Solved on:
- Revisit:
*/

#include <stdio.h>

int minSubArrayLen(int target, int* nums, int numsSize) {
    int min_window_size = numsSize + 1; //dummy value that any initial solution will beat
    int running_sum = 0;
    int left = 0;

    for (int right = 0; right < numsSize; right++) {
        running_sum += nums[right];

        while (running_sum >= target) {
            int curr_window_size = right - left + 1;

            if (curr_window_size < min_window_size) {
                min_window_size = curr_window_size;
            }

            running_sum -= nums[left];
            left++;
        }
    }

    if (min_window_size == numsSize + 1) {
    	return 0;
	} 
	else {
    	return min_window_size;
	}
}

int main(){
	int target = 7;
	int nums[] = {2,3,1,2,4,3};
	int numsSize = 6; 
	int res = minSubArrayLen(target, nums, numsSize);
	printf("%d\n", res);
	return 0; 
}