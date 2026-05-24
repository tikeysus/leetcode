/*
Problem: longest onesIII
Link:
Difficulty: Medium
Topic(s): 
Pattern: Sliding Window

Description:
Given a binary array nums and an integer k, return the maximum number of consecutive 1's in the array if you can flip at most k 0's.

Constraints:
1 <= nums.length <= 105
nums[i] is either 0 or 1.
0 <= k <= nums.length

Initial idea:
Sliding window and a counter of how many bits have been flipped so far. 
Also, I want to use the simple solution of the earlier ones problem in this solution. 

Final approach:
I had a relevation while watching the habs game, the leftmost flipped bit does not have to be considered in the next 
iteration of curr_sequence. 

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

int findMaxConsecutiveOnes(int* nums, int numsSize) {
    int max_window = 0; 
	int current_window = 0; 
	for (int i = 0; i < numsSize; i++){
		if (nums[i] == 1){
			current_window++; 
		}
		else{
			current_window = 0; 
		}
		if (current_window > max_window){
			max_window = current_window; 
		}
	}
	return max_window; 
}

int longestOnes(int* nums, int numsSize, int k) {
	if (k == 0){
		return findMaxConsecutiveOnes(nums, numsSize); 
	}
	int bits_flipped = 0; 
	int curr_seq = 0; 
	int max_seq = 0; 
	int last_flipped_index = 0; 
	int right = 0; 
	while (right < numsSize){
		if ((nums[right] == 0) && (bits_flipped == 0)){
			curr_seq++; 
			bits_flipped++; 
			last_flipped_index = right; 
			right++;
		}

		else if ((nums[right] == 0) && (bits_flipped < k)){
			curr_seq++; 
			bits_flipped++; 
			right++;
		}

		else if (nums[right] == 1){
			curr_seq++; 
			right++;
		}

		else if ((nums[right] == 0) && (bits_flipped == k)){
			curr_seq = 0; 
			bits_flipped = 0; 
			right = last_flipped_index + 1; 
		}

		if (curr_seq > max_seq){
			max_seq = curr_seq; 
		}
	}

	return max_seq; 
}

int main(){
	int nums[] = {0,0,1,1}; 
	int numsSize = 4; 
	int k = 1; 
	int res = longestOnes(nums, numsSize, k); 
	printf("%d\n", res); 

	return 0; 
}