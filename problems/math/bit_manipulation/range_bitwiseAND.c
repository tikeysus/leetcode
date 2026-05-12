/*
Problem: range bitwiseAND
Link:
Difficulty: Medium 
Topic(s):
Pattern:

Description:
Given two integers left and right that represent the range [left, right], return the bitwise AND of all numbers in this range, inclusive.

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
	if (left == 0 || right == 0){
		return 0; 
	}
	else if (left == right){
		return right; 
	}

	int running_and = left; 
	long long int i; 
	for (i = left; i <= right; i++){
		if (running_and == 0){
			return 0; 
		}
		running_and &= i; 
	}
	return running_and; 

}

int main(){
	int res = rangeBitwiseAnd(1073741832,2147483647); 
	printf("%d\n", res); 
	return 0; 
}