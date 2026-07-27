/*
Problem: search insert
Link:
Difficulty:
Topic(s):
Pattern:

Description:
Given a sorted array of distinct integers and a target value, return the index if the target is found. If not, return the index where it would be if it were inserted in order.
You must write an algorithm with O(log n) runtime complexity.

Constraints:

Initial idea:

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

int searchInsert(int* nums, int numsSize, int target) {
	int low = 0; 
	int high = numsSize - 1; 
	int mid;
	while (low <= high){
        mid = low + (high-low)/2; 
		if (nums[mid] == target){ return mid; }
		else if (nums[mid] < target){ low = mid + 1; }
		else if (nums[mid] > target){ high = mid - 1; }
	}
	if (nums[mid] < target) {return mid + 1;}
    return mid; 
}