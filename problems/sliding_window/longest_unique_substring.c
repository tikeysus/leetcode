/*
Problem: longest unique substring
Link:
Difficulty: Medium 
Topic(s):
Pattern: Sliding Window

Description:
Given a string s, find the length of the longest substring without duplicate characters.

Constraints:

Initial idea:
This is C, so we can't use hashmaps. The other approach is to mimic the ASCII table using an array. 

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

int lengthOfLongestSubstring(char* s) {
    int curr_unique = 0; 
	int max_unique = 0; 
	int ascii_arr[95] = {0}; 
	int left = 0; 
	for (int right = 0; s[right] != '\0'; right++){
		while (ascii_arr[s[right] - ' '] >= 1){
			ascii_arr[s[left] - ' ']--; 
			left++; 
		}
		if (ascii_arr[s[right] - ' '] == 0){
			ascii_arr[s[right] - ' '] = 1; 
		}
		
		curr_unique = right - left + 1;
		if (curr_unique > max_unique){
			max_unique = curr_unique; 
		}
	}
	return max_unique; 
}

int main(){
	char s[7] = "pwwkew";
	int res = lengthOfLongestSubstring(s); 
	printf("%d\n", res);
	return 0; 
}