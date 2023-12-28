'''
Given an array of integers nums and an integer target, return indices of the two numbers such that they add up to target.

You may assume that each input would have exactly one solution, and you may not use the same element twice.

You can return the answer in any order.
'''

def two_sum(nums, target):
    for i in range(len(nums)):
        for j in range(i + 1, len(nums)):
            if nums[i] + nums[j] == target:
                return i, j 
#Quadratic solution


def two_sum(nums, target):
    hash_table = {}
    for index, num in enumerate(nums):
        if num in hash_table:
            return hash_table[num], index
        hash_table[target - num] = index

    return hash_table



