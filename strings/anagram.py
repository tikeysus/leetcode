class Solution:
	def isAnagram(self, s: str, t: str) -> bool:
		return sorted(s) == sorted(t)
	
		 
def isAnagram(s, t):
	hash = dict()
	hash1 = dict() 

	for letter in s:
		if letter in hash:
			hash[letter] += 1
		else:
			hash[letter] = 1

	for letter in t:
		if letter in hash1:
			hash1[letter] += 1
		else:
			hash1[letter] = 1
		
	return hash == hash1