"""
Problem: longest consecutive
Link:
Difficulty:
Topic(s):
Pattern:

Description:
Given an unsorted array of integers nums, return the length of the longest consecutive elements sequence.
You must write an algorithm that runs in O(n) time.

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

def longest_consecutive(nums):
	if not nums: return 0 

	nums_set = set(nums)
	longest = 0 
	for num in nums_set: 
		if num - 1 not in nums_set:
			current = num 
			streak = 1

			while current + 1 in nums_set:
				streak += 1
				current += 1

			longest = max(streak, longest)

	return longest 

	


res = longest_consecutive([0,1,2,4,8,5,6,7,9,3,55,88,77,99,999999999])
print(res)
		

	