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

// int maxVowels(char* s, int k) {
//  int max_window_size = 0; 
// 	int curr_window_size = 0; 
// 	int count = 0; 
// 	while (*s != '\0'){
// 		if (*s=='a' || *s=='e' || *s=='i' || *s=='o' || *s=='u'){
// 			curr_window_size++; 
// 		}
// 		else if ((*s!='a' && *s!='e' && *s!='i' && *s!='o' && *s!='u') || (count != 0 && (count % k == 0))){
// 			curr_window_size = 0; 
// 		}
// 		if (curr_window_size > max_window_size){
// 			max_window_size = curr_window_size;
// 		}
// 		count++; 
// 		s++; 

// 	}
// 	return max_window_size; 
// }

int str_len(char* s_copy){
	int count = 0; 
	while (*s_copy != '\0'){
		count++; 
		s_copy++;
	}
	return count; 
}

int maxVowels(char* s, int k) {
	//char* s_copy = s;
	int left = 0; 
	int right = k-1; 
	//int s_len = str_len(s_copy) - 1; 
	int max_window_size = 0; 
	int curr_window_size = 0; 
	while (s[right] != '\0'){
		if ((*s=='a' || *s=='e' || *s=='i' || *s=='o' || *s=='u') && (right - left < k- 1)){
			right++;
			curr_window_size++; 
		}
		if ((right - left) == k - 1){
			curr_window_size = 0; 
			left++;
			right++; 
		}
		// else if ((*s!='a' && *s!='e' && *s!='i' && *s!='o' && *s!='u') && ((right - left) < k)){
		// 	curr_window_size = 0; 
		// 	left++; 
		// }
		if ((curr_window_size > max_window_size)){
			max_window_size = curr_window_size;
		}
		s++; 
	}
	
	return max_window_size; 
}

int main(){
	char s[13] = "weallloveyou";
	int k = 7; 
	int res = maxVowels(s, k); 
	printf("%d\n", res); 

	return 0;
}