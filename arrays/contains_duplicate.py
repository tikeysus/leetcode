class Solution:
    def containsDuplicate(self, nums: list[int]) -> bool:
        distinct = set(nums)
        return len(nums) != len(distinct)        