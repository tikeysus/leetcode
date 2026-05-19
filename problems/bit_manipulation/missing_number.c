/*
Problem: missing number
Link:
Difficulty: Easy 
Topic(s):
Pattern:

Description:
Given an array nums containing n distinct numbers in the range [0, n], return the only number in the range that is missing from the array.

Constraints:

Initial idea:
Lame idea, but we can make an array of nums that is of size n, every time a value pops up, we make that index one, and then see which index is 0. 
I will do this and then see if I can come up with something that is more aking to bit manipulation. 

So there is another idea which relates to XOR and it is amazing. 

Final approach:
You XOR a running sum using the fact that a^a=0, so all the elements cancel each other out, the only one remaining is the missing number.

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
#include <stdlib.h>

int missingNumber(int* nums, int numsSize) {
	int* indexer = calloc(numsSize + 1, sizeof(int)); 
	for (int i = 0; i < numsSize; i++){
		indexer[nums[i]] = 1; 
	}

	int i;
	for (i = 0; i < (numsSize + 1); i++){
		if (indexer[i] == 0){
			break; 
		}
	}

	free(indexer); 
	return i; 
}

int missingNumber_XOR(int* nums, int numsSize){
	int nums_sum = 0; 
	for (int i = 0; i < numsSize; i++){
		nums_sum = nums_sum ^ nums[i]; 
	}

	int range_sum = 0; 
	for (int i = 0; i < numsSize + 1; i++){
		range_sum = range_sum ^ i; 
	}

	return range_sum ^ nums_sum; 
} 

int main(){
	int nums[] = {3,0,1}; 
	int numsSize = 3; 
	int res = missingNumber(nums, numsSize); 
	printf("%d\n", res); 

	return 0; 
}
