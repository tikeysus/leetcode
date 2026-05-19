/*
Problem: twosumII
Link:
Difficulty: Medium
Topic(s):
Pattern:

Description:
Given a 1-indexed array of integers numbers that is already sorted in non-decreasing order, find two numbers such that they add up to a specific target number. Let these two numbers be numbers[index1] and numbers[index2] where 1 <= index1 < index2 <= numbers.length.
Return the indices of the two numbers index1 and index2, each incremented by one, as an integer array [index1, index2] of length 2.
The tests are generated such that there is exactly one solution. You may not use the same element twice.
Your solution must use only constant extra space.

Constraints:
-1000 <= numbers[i] <= 1000
numbers is sorted in non-decreasing order.
The tests are generated such that there is exactly one solution.

Initial idea:
Two pointers, one at the left side, one at the right. Icrement or decrement based on the sum compared to the target.

Final approach:
Same as initial

Complexity: n
Time:
Space:

Mistakes / difficulties:

Key lesson:

Review:
- Solved on: 27/04/26
- Revisit:
*/

#include <stdio.h>
#include <stdlib.h>

int *twoSum(int *numbers, int numbersSize, int target, int *returnSize)
{
    int left = 0;
    int right = numbersSize - 1;

    while (left != right)
    {
        if (numbers[left] + numbers[right] < target)
        {
            left++;
        }
        else if (numbers[left] + numbers[right] > target)
        {
            right--;
        }
        else
        {
            break;
        }
    }

    int *res = malloc(2 * sizeof(int));
    res[0] = left + 1;
    res[1] = right + 1;
    *returnSize = 2;
    return res;
}

int main(void)
{
    int numbers[] = {2, 7, 11, 15};
    int returnSize = 0;
    int *res = twoSum(numbers, 4, 9, &returnSize);
    printf("[%d, %d]\n", res[0], res[1]);
    free(res);

    return 0;
}