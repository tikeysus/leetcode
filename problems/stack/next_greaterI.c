/*
Problem: next greaterI
Link: 
Difficulty: Easy
Topic(s):
Pattern:

Description:
The next greater element of some element x in an array is the first greater element that is to the right of x in the same array.
You are given two distinct 0-indexed integer arrays nums1 and nums2, where nums1 is a subset of nums2.
For each 0 <= i < nums1.length, find the index j such that nums1[i] == nums2[j] and determine the next greater element of nums2[j] in nums2. If there is no next greater element, then the answer for this query is -1.
Return an array ans of length nums1.length such that ans[i] is the next greater element as described above.

Constraints:
1 <= nums1.length <= nums2.length <= 1000
0 <= nums1[i], nums2[i] <= 104
All integers in nums1 and nums2 are unique.
All the integers of nums1 also appear in nums2.

Initial idea:
On the topic of stacks, so let's see how one can be used here. 

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

int* nextGreaterElement(int* nums1, int nums1Size, int* nums2, int nums2Size, int* returnSize) {
	int* answer = malloc(nums1Size * sizeof(int)); 
	for (int i = 0; i < nums1Size; i++){
		answer[i] = -1; 
	}
	
	int* stack = malloc(nums2Size * sizeof(int)); 
	int top = -1; 
	int j = 0; 
	for (int i = 0; i < nums2Size; i++){
		while (top != -1 && nums2[i] > stack[top]){
			int prev = stack[top]; 
			top--; 
			while (j <= nums1Size - 1){
				if (nums1[j] == nums2[i]){
					answer[j] = prev; 
				}
				j++; 
			}
			j = 0; 
		}

		top++; 
		stack[top] = nums2[i]; 
	}
	
	*returnSize = nums1Size; 
	free(stack);
	return answer; 
}

int main(){
	int nums1[] = {4,1,2}; 
	int nums1Size = 3; 
	int nums2[] = {1,3,4,2}; 
	int nums2Size = 4; 
	int returnSize; 
	int* res = nextGreaterElement(nums1, nums1Size, nums2, nums2Size, &returnSize); 
	printf("["); 
	for (int i = 0; i < returnSize; i++){
		printf(" %d ", res[i]); 
	}
	printf("]\n");
}
