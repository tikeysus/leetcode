"""
Problem: group anagrams
Link:
Difficulty:
Topic(s):
Pattern:

Description:
Given an array of strings strs, group the anagrams together. You can return the answer in any order.

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

def group_anagrams(strings): 
	anagram_groups = []
	anagram_dictionaries = []
	for string in strings:
		frequency_counter = dict()
		for letter in string:
			if letter in frequency_counter:
				frequency_counter[letter] += 1
			else:
				frequency_counter[letter] = 1
		already_exists = False 
		for i in range(len(anagram_dictionaries)):
			if frequency_counter == anagram_dictionaries[i]:
				anagram_groups[i].append(string)
				already_exists = True 
				break
		if already_exists == False: 
			anagram_dictionaries.append(frequency_counter)
			anagram_groups.append([string])
	return anagram_groups 

print(group_anagrams(["eat","tea","tan","ate","nat","bat"]))
		


