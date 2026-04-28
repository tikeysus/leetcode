/*
Problem: Product of Array Except Self
Link:
Difficulty: Medium 
Topic(s):
Pattern:

Description:
Given an integer array nums, return an array answer such that answer[i] is equal to the product of all the elements of nums except nums[i].
The product of any prefix or suffix of nums is guaranteed to fit in a 32-bit integer.
You must write an algorithm that runs in O(n) time and without using the division operation.

Constraints:
2 <= nums.length <= 105
-30 <= nums[i] <= 30
The input is generated such that answer[i] is guaranteed to fit in a 32-bit integer.

Initial idea:
Initial idea was to calculate the cumulative product at the start and then fake division through subtraction. But this can't work because 
if there is a zero in the array that needs special consideration. 

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

#include <stdio.h>
#include <stdlib.h>


int arr_product(int* nums, int numsSize){
    int product = 1; 
    for (int i = 0; i < numsSize; i++){
        product *= nums[i]; 
    }
    return product; 
}

int quotient(int product, int num){
    int count = 0; 
    while (product > 0){
        product -= num; 
        count++; 
    }
    return count; 
}

int* productExceptSelf(int* nums, int numsSize, int* returnSize) {
    int product = arr_product(nums, numsSize); 
    int* res = malloc(numsSize * sizeof(int)); 

    for (int i = 0; i < numsSize; i++){
        int quotient_res = quotient(product, nums[i]);
        res[i] = quotient_res; 
    }

    *returnSize = 4; 
    return res; 
}

int main(){
    int nums[] = {1,2,3,4}; 
    int returnSize; 
    int* res = productExceptSelf(nums, 4, &returnSize); 
    printf("[%d, %d, %d, %d]\n", res[0], res[1], res[2], res[3]);

    free(res); 
    return 0; 
}