/*
Problem: single numberII
Link:
Difficulty: Medium 
Topic(s):
Pattern:

Description:

Constraints:

Initial idea:
This smells like an ASCII array. But these aren't chars, they are numbers, which means I have to change my approach. 
Hashing in python would make this a lot easier. 

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

int singleNumber(int* nums, int numsSize) {
	int result = 0; 
	for (int i = 0; i < 32; i++){
		int count = 0; 
		for (int j = 0; j < numsSize; j++){
			if ((nums[j] >> i) & 1){
				count++; 
			}
		}

		if ((count % 3) == 1){
			result |= (1LL << i); 
		}
	}
	return result; 
}

int main(){
	int nums[] = {2,3,2,2}; 
	int numsSize = 4; 
	int res = singleNumber(nums, numsSize); 
	printf("%d\n", res); 
}