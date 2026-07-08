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
    int carry = 0; 
	int shift_count = 0;
	
	int acc = 0; 
	for (int i = 0; i < 32; i++){
		int a_last_bit = a & 1;
		int b_last_bit = b & 1;
		if (carry == 0){
			if (a_last_bit == 1 && b_last_bit == 1){
				carry = 1;
			}
			else if (a_last_bit == 1 || b_last_bit == 1){
				acc |= (1LL << shift_count);
			}
		}
		else{
			if (a_last_bit == 0 && b_last_bit == 0){
				acc |= (1LL << shift_count);
				carry = 0; 
			}
			else if (a_last_bit == 1 && b_last_bit == 1){
				acc |= (1LL << shift_count);
			}
		}
		shift_count++;
		a >>= 1; 
		b >>= 1; 
	}
	return acc; 
}

int main(){
	int a = -12; 
	int b = -8; 
	int sum = getSum(a, b); 
	printf("%d\n", sum); 
	return 0; 
}