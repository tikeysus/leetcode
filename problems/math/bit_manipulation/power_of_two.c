/*
Problem: power of two
Link:
Difficulty: Easy
Topic(s):
Pattern:

Description:

Constraints:

Initial idea:
Same thing with bit shifts and ANDs. 

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

bool isPowerOfTwo(int n) {
	if (n == -1 || n == 0){
		return false; 
	}
	while (n != 1){
		if ((n & 1) == 1){
			return false; 
		}
		n >>= 1; 
	}
	return true; 
}