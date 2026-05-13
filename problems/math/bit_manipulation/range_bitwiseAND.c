/*
Problem: range bitwiseAND
Link:
Difficulty: Medium 
Topic(s):
Pattern:

Description:
Given two integers left and right that represent the range [left, right], return the bitwise AND of all numbers in this range, inclusive.
The difficulty is with exceeding the time limit, an optimization is needed. 
What if we adopt a strategy that solves this problem bit by bit?
A key hint is that we only care about the common prefix that remains (after conducting the AND operation) from the left. 

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

int rangeBitwiseAnd(int left, int right) {
	int shift_count = 0; 
	while (left != right){
		left >>= 1;
		right >>= 1; 
		shift_count++; 
	}
	return left << shift_count; 
	
}

int main(){
	int res = rangeBitwiseAnd(1123123123,2147483647); 
	printf("%d\n", res); 
	return 0; 
}