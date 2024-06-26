#include <stdio.h> 
#include <stdlib.h>

int duplicate(int *nums, int numsSize); 

int main(){
	return 0; 
}

int duplicate(int* nums, int numsSize){
	int occurences[19] = {0}; //can be made to be 256 if ASCII characters are to be considered

	for (int i = 0; i < numsSize; i++){
		if (nums[i] >= 0){
			int current = nums[i] + 10; 
			occurences[current] += 1; 
		}

		else{
			int current = nums[i] + 10; 
			occurences[current] += 1; 
		}
	}

	for (int i = 0; i < 19; i++){
		if (occurences[i] >= 2){
			return 1; 
		}
	}

	return 0; 

}