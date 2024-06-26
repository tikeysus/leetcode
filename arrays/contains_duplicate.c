#include <stdio.h> 
#include <stdlib.h>

int duplicate(int *nums, int numsSize); 

int main(){
	int nums[] = {1,2,8,6,1};
	int* nums_ptr = nums; 
	int len = 5; 

	int answer = duplicate(nums_ptr, len); 
	printf("%d\n", answer); 

	return 0; 
}

int duplicate(int* nums, int numsSize){
	for (int i = 0; i < numsSize - 1; i++){
		for (int j = i + 1; j < numsSize; j++){
			if (nums[i] == nums[j]){
				return 1; 
			}
		}
	}
	return 0; 
}