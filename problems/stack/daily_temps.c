/*
Problem: daily temps
Link:
Difficulty:
Topic(s):
Pattern:

Description:
Given an array of integers temperatures represents the daily temperatures, return an array answer such that answer[i] is the number of days you have to wait after the ith day to get a warmer temperature. If there is no future day for which this is possible, keep answer[i] == 0 instead.

Constraints:

Initial idea:
One idea that popped up was maintaining an array that includes the max number encountered up to that point

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

int* dailyTemperatures(int* temperatures, int temperaturesSize, int* returnSize) {
	int* num_days = malloc(temperaturesSize * sizeof(int)); 
	int left = 0;
	int right = 0; 
	int count; 
	while(right < temperaturesSize){
		count = right - left; 
		if (temperatures[right] > temperatures[left]){
			num_days[left] = count; 
			left++; 
			if (count == 1){
				right++; 
			}
		}
		else{
			if (right == temperaturesSize - 1){
				while(left < temperaturesSize){
					num_days[left] = 0;
					left++; 
				}
			}
			right++; 
		}
	}

	return num_days;
}

int main(){
	int temperatures[] = {73,74,75,71,69,72,76,73}; 
	int temperaturesSize = 8; 
	int returnSize; 
	int* res = dailyTemperatures(temperatures, temperaturesSize, &returnSize); 
	for (int i = 0; i < returnSize; i++){
		printf("%d\n", res[i]);
	}

	return 0; 
}