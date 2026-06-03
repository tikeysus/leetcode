/*
Problem: backspace compare
Link:
Difficulty:
Topic(s):
Pattern:

Description:
Given two strings s and t, return true if they are equal when both are typed into empty text editors. '#' means a backspace character.
Note that after backspacing an empty text, the text will continue empty.

Constraints:
1 <= s.length, t.length <= 200
s and t only contain lowercase letters and '#' characters.

Initial idea:
Should I gradually build a string or is there a better way? 
Also, how should I deal with a deletion of an already empty string, i.e. "#". 
Let's first try a space complexity of n, because leetcode hints at a possible solution with space of O(1)

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
#include <stdlib.h>
#include <stdbool.h>

int str_len(char* s){
	int count = 0; 
	for (int i = 0; s[i] != '\0'; i++){
		count++; 
	}
	return count; 
}

bool string_compare(char* s_acc, char* t_acc, int s_stack_top, int t_stack_top){
	if (s_stack_top != t_stack_top) return false; 
	else if (s_stack_top == 0) return true; 
	for (int i = 0; i < s_stack_top; i++){
		if (s_acc[i] != t_acc[i]) return false; 
	}
	return true; 
}

bool backspaceCompare(char* s, char* t) {
    int s_len = str_len(s); 
	int t_len = str_len(t); 

	char* s_acc = malloc(s_len * sizeof(char)); 
	char* t_acc = malloc(t_len * sizeof(char)); 

	int s_stack_top = 0; 
	for (int i = 0; s[i] != '\0'; i++){
		if (s[i] != '#'){
			s_acc[s_stack_top] = s[i];
			s_stack_top++; 
		}
		else{
			if (s_stack_top == 0){
				continue; 
			}
			s_stack_top--; 
		}
	}

	int t_stack_top = 0; 
	for (int i = 0; t[i] != '\0'; i++){
		if (t[i] != '#'){
			t_acc[t_stack_top] = t[i];
			t_stack_top++; 
		}
		else{
			if (t_stack_top == 0){
				continue; 
			}
			t_stack_top--; 
		}
	}

	bool result = string_compare(s_acc, t_acc, s_stack_top, t_stack_top); 
	free(s_acc);
	free(t_acc); 

	return result;
}

int main(){
	char s[8] = "xywrrmp"; 
	char t[10] = "xywrrmu#p"; 
	int result = backspaceCompare(s, t); 
	printf("%d\n", result);

	return 0; 
}