/*
Problem: min cost tickets
Link:
Difficulty:
Topic(s):
Pattern:

Description:
You have planned some train traveling one year in advance. The days of the year in which you will travel are given as an integer array days. Each day is an integer from 1 to 365.

Train tickets are sold in three different ways:

a 1-day pass is sold for costs[0] dollars,
a 7-day pass is sold for costs[1] dollars, and
a 30-day pass is sold for costs[2] dollars.
The passes allow that many days of consecutive travel.

For example, if we get a 7-day pass on day 2, then we can travel for 7 days: 2, 3, 4, 5, 6, 7, and 8.
Return the minimum number of dollars you need to travel every day in the given list of days.

Constraints:

Initial idea:

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

int mincostTickets(int* days, int daysSize, int* costs, int costsSize) {
    int* dp = malloc(daysSize * sizeof(int)); 
	dp[0] = costs[0]; 

	for (int i = 1; i < daysSize; i++){
		int option_1 = dp[i - 1] + costs[0]; //one more day
		int option_2 = costs[1]; //7-day
		int option_3 = costs[2]; //30-day
		int options[] = {option_1, option_2, option_3}; 
		int min = option_1; 
		for (int i = 1; i < 3; i++){
			if (options[i] < min){ min = options[i]; }
		}
		dp[i] = min; 
	}
	int res = dp[daysSize - 1]; 
	free(dp); 
	return res; 
}


int main(){
	int days[] = {1,4,6,7,8,20}; 
	int daysSize = 6; 
	int costs[] = {2,7,15}; 
	int costsSize = 3; 
	int res = mincostTickets(days, daysSize, costs, costsSize); 
	printf("%d\n", res); 

	return 0; 
}