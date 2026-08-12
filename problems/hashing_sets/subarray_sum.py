"""
Problem: subarray sum
Link:
Difficulty:
Topic(s):
Pattern:

Description:
A subarray is a contiguous non-empty sequence of elements within an array.
Given an array of integers nums and an integer k, return the total number of subarrays whose sum equals to k.

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

def subarray_sums(nums, k):
	prefix_sums = {0:1}
	count = 0
	curr_sum = 0 
	for num in nums:
		curr_sum += num
		if curr_sum - k in prefix_sums:
			count += prefix_sums[curr_sum-k]

		prefix_sums[curr_sum] = prefix_sums.get(curr_sum, 0) + 1
	return count
