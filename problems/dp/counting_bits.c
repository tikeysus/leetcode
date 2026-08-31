/*
Problem: counting bits
Link:
Difficulty:
Topic(s):
Pattern:

Description:
Given an integer n, return an array ans of length n + 1 such that for each i (0 <= i <= n), ans[i] is the number of 1's in the binary representation of i.
Do not solve it with built-in functions (i.e., like __builtin_popcount in C++).

Constraints:

Initial idea:
n log n solution was too obvious. couldn't find the recurrence relation myself. 

Final approach:

Complexity:
Time:
Space:

Mistakes / difficulties:

Key lesson:

Review:
- Solved on:
- Revisit:
*/

int* countBits(int n, int* returnSize) {
    int* res = malloc((n + 1) * sizeof(int));
    *returnSize = n + 1;

    res[0] = 0;
    for (int i = 1; i <= n; i++) {
        res[i] = res[i >> 1] + (i & 1);
    }

    return res;
}