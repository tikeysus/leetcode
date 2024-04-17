class Solution:
    def containsDuplicate(self, nums: List[int]) -> bool:
        dictionary = {}
        for num in nums:
            if (num in dictionary):
                return True
            dictionary[num] = 1
