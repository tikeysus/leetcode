"""
Problem: coin change
Link:
Difficulty:
Topic(s):
Pattern:

Description:
You are given an integer array coins representing coins of different denominations and an integer amount representing a total amount of money.
Return the fewest number of coins that you need to make up that amount. If that amount of money cannot be made up by any combination of the coins, return -1.
You may assume that you have an infinite number of each kind of coin.

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
"""

def coinChange_recursive(coins, amount, acc):
	if amount == 1:
		if 1 in coins: 
			return acc + 1
		else: return - 1

	if amount in coins: return 1 + acc

	


def coinChange(coins, amount):
	if amount in coins:
		return 1 
	return coinChange_recursive(coins, amount, 0)
