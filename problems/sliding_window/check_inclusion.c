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

// int* ascii_arr_builder(char* s){
// 	int ascii_arr[28] = {0}; //we know the size of the array here, so iteration through it will be safer later on. 
// 	for (int i = 0; s[i] != '\0'; i++){
// 		ascii_arr[s[i] - 'a']++; 
// 	}
// 	return ascii_arr; 
// }

bool array_compare(int* s1_ascii_arr, int* s2_ascii_arr){
	for (int i = 0; i < 28; i++){
		if (s1_ascii_arr[i] != s2_ascii_arr[i]){
			return false; 
		}
	}
	return true; 
}

bool checkInclusion(char* s1, char* s2) {
	int s1_ascii_arr[28] = {0};
	for (int i = 0; s1[i] != '\0'; i++){
		s1_ascii_arr[s1[i] - 'a']++; 
	}
	int s2_ascii_arr[28] = {0}; 
	
	for (int right = 0; s2[right] != '\0'; right++){
		if (s1_ascii_arr[s2[right] - 'a'] == 0){
			continue; 
		}
		else{
			while (s1_ascii_arr[s2[right] - 'a'] != 0){
				s2_ascii_arr[s2[right] - 'a']++; 
				right++; 
			}
		}

		if (array_compare(s1_ascii_arr, s2_ascii_arr) == 1){
			return true; 
		}
		for (int i = 0; i < 28; i++){
			s2_ascii_arr[i] = 0; 
		}
	}
	return false; 
}

int main(){
	char s1[4] = "adc";
	char s2[5] = "dcda";
	bool res = checkInclusion(s1, s2); 
	printf("%d\n", res); 
	return 0; 
}