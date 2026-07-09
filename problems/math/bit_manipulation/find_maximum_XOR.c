/*
Problem: find maximum XOR
Link:
Difficulty:
Topic(s):
Pattern:
Bit Manipulation 

Description:
Given an integer array nums, return the maximum result of nums[i] XOR nums[j], where 0 <= i <= j < n.

Constraints:
1 <= nums.length <= 2 * 105
0 <= nums[i] <= 231 - 1

Initial idea:
Something like a greedy approach mixed with bit shifting, if we can take a set bit - we take it. 
Nope, turns out it's not as simple as that.

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

int findMaximumXOR(int* nums, int numsSize){
	int result = 0; 

}

int main(){
	int nums[] = {3, 10, 5, 25, 2, 8}; 
	int result = findMaximumXOR(nums, 6); 
	printf("%d\n", result);
	return 0; 
}
