#include <stdio.h>

int* bubble(int* nums, int nums_len); 

int main(){
	return 0; 
}

int* bubble(int* nums, int size){
	for (int i = 0; i < size; i++){
		for (int j = 0; j < size - 1 - i; j++){
			if (nums[j] > nums[j + 1]){
				int temp = nums[j];
				nums[j] = nums[j + 1];
				nums[j + 1] = temp; 
			}
		}
	}
	return nums;
}