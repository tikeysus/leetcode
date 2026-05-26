/*
Problem: check inclusion
Link:
Difficulty: Medium
Topic(s):
Pattern: Window/ASCII, could probably also be solved using DP 

Description:
Given two strings s1 and s2, return true if s2 contains a permutation of s1, or false otherwise.
In other words, return true if one of s1's permutations is the substring of s2.

Constraints:

Initial idea:
Right now I can only think of a n^2 solution where we simulate a hashmap with an ASCII array and then check for equality. 

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

bool checkInclusion(char* s1, char* s2) {
    
}

int main(){
	char s1[3] = "ab";
	char s2[9] = "eidbaooo";
	bool res = checkInclusion(s1, s2); 
	printf("%d\n", res); 
	return 0; 
}