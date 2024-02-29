'''
Given a string s, return the longest 
palindromic substring in s.

Example 1:

Input: s = "babad"
Output: "bab"
Explanation: "aba" is also a valid answer.

Example 2:

Input: s = "cbbd"
Output: "bb"
''' 

class Solution:
    def longestPalindrome(self, s: str) -> str:
        answer = s[0]
        for i in range(len(s)):
            for j in range(i + 1, len(s)):
                if len(s[i:j + 1]) > len(answer) and s[i:j + 1] == (s[i:j + 1])[::-1]:
                    answer = s[i:j + 1]
        
        return answer 