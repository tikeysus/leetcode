/*
Problem: get sum
Link:
Difficulty: Easy
Topic(s):
Pattern: Bit Manipulation 

Description:
Given two integers a and b, return the sum of the two integers without using the operators + and -.

Constraints:
-1000 <= a, b <= 1000

Initial idea:
We can express 1000 within 10 bits, so we do a for loop that includes 10 iterations using logical operators. 
Haven't thought about negative numbers yet. 

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

int getSum(int a, int b) {
    int sum = 0; 
	while (a > 0 || b > 0){
		int a_last = a & 1; 
		int b_last = b & 1; 

		sum <<= 1; 
		if ((a_last | b_last) == 1){
			sum |= 1; 
		}
		a >>= 1;
		b >>= 1;  
	}

	return sum <<= 1; 
}

int main(){
	int a = 10; 
	int b = 2; 
	int sum = getSum(a, b); 
	printf("%d\n", sum); 
	return 0; 
}