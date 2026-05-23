/*
Problem: max vowels
Link:
Difficulty:
Topic(s):
Pattern:

Description:
Given a string s and an integer k, return the maximum number of vowel letters in any substring of s with length k.
Vowel letters in English are 'a', 'e', 'i', 'o', and 'u'.

Constraints:
1 <= s.length <= 105
s consists of lowercase English letters.
1 <= k <= s.length

Initial idea:
I suspect that it's about the same as problem 485. Unfortunately, no use of ASCII here. 

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

int is_vowel(char c){
	return (c=='a' || c=='e' || c=='i' || c=='o' || c=='u'); 
}

int maxVowels(char* s, int k) {
	int left = 0; 
	int max_count = 0; 
	int curr_count = 0; 

	for (int right = 0; s[right] != '\0'; right++){
		if (is_vowel(s[right])){
			curr_count++; 
		}

		if (right - left + 1 > k){
			if (is_vowel(s[left])){
				curr_count--; 
			}
			left++; 
		}
		
		if (curr_count > max_count){
			max_count = curr_count; 
		}
	}

	return max_count; 
}

int main(){
	char s[10] = "abciiidef";
	int k = 3; 
	int res = maxVowels(s, k); 
	printf("%d\n", res); 

	return 0;
}