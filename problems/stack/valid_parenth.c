/*
Problem: valid parenth
Link:
Difficulty: Easy
Topic(s):
Pattern: stack 

Description:

Constraints:
s consists of parentheses only '()[]{}'.

Initial idea:
Imitating a stack using an array. 

Final approach:
Looked up the solution for this one, important fundamentals. 

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

bool isValid(char* s) {
	char stack[10000];
	int top = -1; 
	for (int i = 0; s[i] != '\0'; i++){
		char curr_char = s[i];
		if (curr_char == '[' || curr_char == '{' || curr_char == '('){
			top++; 
			stack[top] = curr_char; 
		}
		else{
			if (top == -1){
				return false; 
			}
			char opening_bracket = stack[top]; 
			top--; 

			if (opening_bracket == '(' && curr_char != ')'){
				return false; 
			}
			if (opening_bracket == '{' && curr_char != '}'){
				return false; 
			}
			if (opening_bracket == '[' && curr_char != ']'){
				return false; 
			}
		}
	}
	return top == -1; 
}

int main(){
	char s[7] = "()[]{}";
	bool valid = isValid(s);
	printf("%d\n", valid);
	return 0; 
}