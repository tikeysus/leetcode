/*
Problem: hamming weight
Link:
Difficulty: Easy
Topic(s):
Pattern:

Description:
Given a positive integer n, write a function that returns the number of set bits in its binary representation (also known as the Hamming weight).

Constraints:

Initial idea:
While loop, bit shifts, and ANDs. 

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

int hammingWeight(int n) {
	int count = 0; 
	while (n != 0){
		if ((n & 1) == 1){
			count++; 
		}
		n >>= 1; 
	}

	return count; 
}

// int main(){
// 	int input = 2147483645;
// 	int res = hammingWeight(input); 
// 	printf("%d\n", res); 
// 	return 0;
// }