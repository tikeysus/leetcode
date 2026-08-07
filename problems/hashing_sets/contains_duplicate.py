"""
Problem: contains duplicate
Link:
Difficulty:
Topic(s):
Pattern:

Description:
Given an integer array nums, return true if any value appears at least twice in the array, and return false if every element is distinct.

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

def contains_duplicate(nums):
	occurence_counter = dict()
	for num in nums:
		if (occurence_counter.get(num, 0) == 1): return True 
		else: occurence_counter[num] = 1
	return False 