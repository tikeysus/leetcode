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
My main mistake was not considering the fact that a possible permutation of s1 in s2 has to be of length s1.len()

Key lesson:

Review:
- Solved on:
- Revisit:
*/

#include <stdio.h>
#include <stdbool.h>

int array_compare(int* a, int* b) {
    for (int i = 0; i < 26; i++) {
        if (a[i] != b[i]) return 0;
    }
    return 1;
}

int array_length(char *s) {
    int count = 0;
    for (int i = 0; s[i] != '\0'; i++) {
        count++;
    }
    return count;
}

bool checkInclusion(char* s1, char* s2) {
    int s1_ascii_arr[26] = {0};
    int s2_ascii_arr[26] = {0};

    int s1_len = array_length(s1);
    int s2_len = array_length(s2);

    if (s1_len > s2_len) return false;

    for (int i = 0; i < s1_len; i++) {
        s1_ascii_arr[s1[i] - 'a']++;
        s2_ascii_arr[s2[i] - 'a']++;
    }

    if (array_compare(s1_ascii_arr, s2_ascii_arr)) return true;

    for (int right = s1_len; s2[right] != '\0'; right++) {
        s2_ascii_arr[s2[right] - 'a']++;
        s2_ascii_arr[s2[right - s1_len] - 'a']--;

        if (array_compare(s1_ascii_arr, s2_ascii_arr)) {
            return true;
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