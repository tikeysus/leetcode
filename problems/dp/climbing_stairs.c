/*
Problem: climbing stairs
Link:
Difficulty:
Topic(s):
Pattern:

Description:
You are climbing a staircase. It takes n steps to reach the top.
Each time you can either climb 1 or 2 steps. In how many distinct ways can you climb to the top?

Constraints:
1 <= n <= 45

Initial idea:
Recursive approach first: f(n)=f(n-1)+f(n-2)
will try to come up with dp solution later. 

Final approach:
Fibonacci basically. Mind the constraints, had a problem with VLA at the start. 

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

int climbStairs(int n) {
	int dynamic_arr[45] = {0}; 
	dynamic_arr[0] = 1; dynamic_arr[1] = 2;
	for (int i = 2; i < n; i++){
		dynamic_arr[i] = dynamic_arr[i-1] + dynamic_arr[i-2]; 
	}
	return dynamic_arr[n - 1]; 
}

int main(){
	int n = 12; 
	int res = climbStairs(n); 
	printf("%d\n", res); 
	return 0; 
}