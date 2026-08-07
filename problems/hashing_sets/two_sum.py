"""
Problem: two sum
Link:
Difficulty:
Topic(s):
Pattern:

Description:
You are given an array of integers nums and an integer target, return indices of the two numbers such that they add up to target.
You may assume that each input would have exactly one solution, and you may not use the same element twice.
You can return the answer in any order.

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

def two_sum(nums, target):
	complement_dict = dict()
	for i in range(len(nums)):
		if nums[i] in complement_dict:
			return [i, complement_dict.get(nums[i])]
		complement_dict[target - nums[i]] = i

	return [-1, -1]

print(two_sum([2,7,11,15], 18))

			