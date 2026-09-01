/*
Problem: perfect squares
Difficulty:
Topic(s):
Pattern:

Link:
Description:
Given an integer n, return the least number of perfect square numbers that sum to n.
A perfect square is an integer that is the square of an integer; in other words, it is the product of some integer with itself. For example, 1, 4, 9, and 16 are perfect squares while 3 and 11 are not.

Constraints:

Initial idea:
I will look at patterns for now and see if I can establish a recurrence relation. 

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

int numSquares(int n) {
	if (n == 1 || n == 2){ return n; }

	int curr_root = 1; 
	int* dp_arr = calloc(n, sizeof(int)); 
	dp_arr[0] = 1; 
	dp_arr[1] = 2; 
	for (int i = 2; i < n; i++){
		if ((curr_root + 1) * (curr_root + 1) == i+1){
			curr_root++; 
			dp_arr[i] = 1; 
		}
		else if ((i+1) % (curr_root) == 0){ dp_arr[i] = (i+1)/(curr_root); }
		else{
			dp_arr[i] = dp_arr[curr_root*curr_root - 1] + dp_arr[i - (curr_root*curr_root - 1) - 1];
		}
	}
	int res = dp_arr[n-1]; 
	free(dp_arr); 
	return res; 
}

int main(){
	int n = 12; 
	int res = numSquares(n); 
	printf("%d\n", res); 
	
	return 0; 
}