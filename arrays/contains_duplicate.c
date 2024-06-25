#include <stdio.h> 
#include <stdlib.h>

int duplicate(int *nums, int numsSize); 

int main(){
	return 0; 
}

int duplicate(int* nums, int numsSize){
	int occurences[10] = {0}; //can be made to be 256 if ASCII characters are to be considered

	for (int i = 0; i < numsSize; i++){
		int current = nums[i]; 
		occurences[current] += 1; 
	}

	for (int i = 0; i < 10; i++){
		if (occurences[i] >= 2){
			return 1; 
		}
	}

	return 0; 

}