/*
Problem: coin change
Link:
Difficulty:
Topic(s):
Pattern:

Description:

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
#include <limits.h>
#include <stdlib.h>

int coinChange_helper(int* coins, int coinsSize, int amount, int* memo) {
	if (amount == 0){ return 0; }
	if (amount < 0){ return -1; }
	
	int ans = INT_MAX; 

	if (memo[amount - 1] != -2){ return memo[amount - 1]; }
	
	for (int i = 0; i < coinsSize; i++){
		if (coins[i] <= amount){
			int potential_answer = coinChange_helper(coins, coinsSize, amount - coins[i], memo); 
			if (potential_answer != -1 && potential_answer + 1 < ans){
				ans = potential_answer + 1; 
			}
		}
	}

	memo[amount - 1] = (ans == INT_MAX) ? -1 : ans; 
	return memo[amount - 1]; 
}


int coinChange(int* coins, int coinsSize, int amount) {
	if (amount == 0){ return 0; }
	if (amount < 0){ return -1; }

	int* memo = malloc(amount * sizeof(int)); 
	for (int i = 0; i < amount; i++){ memo[i] = -2; }

	int result = coinChange_helper(coins, coinsSize, amount, memo); 
	free(memo); 
	return result; 
}

int coinChange_DP(int* coins, int coinsSize, int amount) {
	if (amount == 0){ return 0; }
	int* dp_arr = malloc((amount + 1) * sizeof(int)); 
	for (int i = 1; i <= amount; i++){
		dp_arr[i] = amount + 1; 
	}

	dp_arr[0] = 0; 
	for (int j = 1; j <= amount; j++){
		for (int i = 0; i < coinsSize; i++){
			if (coins[i] <= j){
				int candidate = dp_arr[j - coins[i]] + 1; 
				dp_arr[j] = (candidate < dp_arr[j]) ? candidate : dp_arr[j]; 
			}
		}
	}
	int res = dp_arr[amount]; 
	free(dp_arr); 
	return (res == amount + 1) ? -1 : res; 
}

int main(){
	int coins[] = {1,2,5}; 
	int coinsSize = 3; 
	int amount = 11; 
	int ans = coinChange_DP(coins, coinsSize, amount); 
	printf("%d\n", ans); 

	return 0; 
}