/*
Problem: reverse bits
Link:
Difficulty: Easy
Topic(s):
Pattern:

Description:

Constraints:
0 <= n <= 231 - 2
n is even.

Initial idea:
Something with bit shifts, let's see what gives. 

Final approach:
This worked, but I will revisit this and try not to use the pow operator. 

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

int reverseBits(int n){
	int acc = 0; 
	for (int i = 0; i < 32; i++){
		acc <<= 1; 
		if ((n & 1) == 1){
			acc |= 1; 
		}
		n >>= 1; 
	}

	return acc; 
}

int main(){
	int n = 43261596; 
	int res = reverseBits(n);
	printf("%d\n", res); 
	
	return 0;
}