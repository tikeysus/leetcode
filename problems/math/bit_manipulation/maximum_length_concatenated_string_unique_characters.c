/*
Problem: max length
Link:
Difficulty: Medium 
Topic(s):
Pattern:

Description:
You are given an array of strings arr. A string s is formed by the concatenation of a subsequence of arr that has unique characters.
Return the maximum possible length of s.
A subsequence is an array that can be derived from another array by deleting some or no elements without changing the order of the remaining elements.

Constraints:

Initial idea:
I think I see the vision. We can use the XOR operator to check if there are repeated chars. 
Harder than it seemed originally. 

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

int maxLength(char** arr, int arrSize) {
	int count = 0; 
	int xor_sum = 0; 
}

int main(){
	char* arr[] = {"un", "iq", "ue"}; 
	int res = maxLength(arr, 3); 
	printf("%d\n", res); 
	return 0; 
}