/*
Problem: palindrome
Link:
Difficulty:
Topic(s):
Pattern:

Description:
Given an integer x, return true if x is a palindrome, and false otherwise.

Constraints:

Initial idea:
Initially I thought that this is bit manipulation, but that won't work, interesting. 

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
#include <stdbool.h>

bool isPalindrome(int x) {
	if (x <= -1){ return false; }
	if (x <= 9){ return true; }

	long long reversed_num = 0; 
	int x_copy = x; 
	long long i = 1; 
	while (x_copy != 0){
		long long digit = x % (10LL * i); 
		digit /= i; 
		reversed_num *= 10; 
		reversed_num += digit; 
		i *= 10; x_copy /= 10; 
	}
	return reversed_num == x; 
}

int main(){
	int x = 1234567899; 
	bool res = isPalindrome(x); 
	printf("%d\n", res); 
	return 0; 
}