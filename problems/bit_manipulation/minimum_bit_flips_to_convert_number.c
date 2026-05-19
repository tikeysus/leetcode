/*
Problem: min bit flips
Link:
Difficulty: Easy
Topic(s):
Pattern:

Description:
A bit flip of a number x is choosing a bit in the binary representation of x and flipping it from either 0 to 1 or 1 to 0.
For example, for x = 7, the binary representation is 111 and we may choose any bit (including any leading zeros not shown) and flip it. We can flip the first bit from the right to get 110, flip the second bit from the right to get 101, flip the fifth bit from the right (a leading zero) to get 10111, etc.
Given two integers start and goal, return the minimum number of bit flips to convert start to goal.

Constraints:

Initial idea: Something to do with XOR

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

int minBitFlips(int start, int goal) {
    int count = 0;
	while (start != goal){
		if (((start & 1) ^ (goal & 1)) != 0){
			count ++;
		}
		start >>= 1;
		goal >>= 1;
	}
	return count;
}

int main(){
	int start = 3;
	int goal = 4;

	int res = minBitFlips(start, goal);
	printf("%d\n", res);
}
