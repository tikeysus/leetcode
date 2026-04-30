/*
Problem: remove element
Link:
Difficulty: Easy 
Topic(s):
Pattern:

Description:
Given an integer array nums and an integer val, remove all occurrences of val in nums in-place. The order of the elements may be changed. Then return the number of elements in nums which are not equal to val.
Consider the number of elements in nums which are not equal to val be k, to get accepted, you need to do the following things:
Change the array nums such that the first k elements of nums contain the elements which are not equal to val. The remaining elements of nums are not important as well as the size of nums.
Return k.

Constraints:

Initial idea:

Final approach:

Complexity:
Time:
Space:

Mistakes / difficulties:
Overall difficulty with in-place maneouvering. Need to learn some concepts here. 


Key lesson:

Review:
- Solved on:
- Revisit:
*/

#include <stdio.h>

int removeElement(int* nums, int numsSize, int val) {
    int i = 0;
    int n = numsSize;

    while (i < n) {
        if (nums[i] == val) {
            nums[i] = nums[n - 1]; // replace with last active element
            n--;                   // shrink active array
        } else {
            i++;
        }
    }

    return n;
}