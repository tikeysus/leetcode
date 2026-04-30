/*
Problem: reshape matrix
Link:
Difficulty: Easy 
Topic(s):
Pattern:

Description:
In MATLAB, there is a handy function called reshape which can reshape an m x n matrix into a new one with a different size r x c keeping its original data.
You are given an m x n matrix mat and two integers r and c representing the number of rows and the number of columns of the wanted reshaped matrix.
The reshaped matrix should be filled with all the elements of the original matrix in the same row-traversing order as they were.
If the reshape operation with given parameters is possible and legal, output the new reshaped matrix; Otherwise, output the original matrix.

Constraints:
1 <= r, c <= 300

Initial idea:
Something to do with pointers, I reckon I will get the jist as I start coding (saying that never goes well though). 

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

#include <stdlib.h>
#include <stdio.h>

int* matrix_to_arr(int** mat, int matSize, int* matColSize){
	int arr_size = matSize * matColSize[0]; 
	int* single_d_arr = malloc(arr_size * sizeof(int)); 
	int count = 0; 
	for (int i = 0; i < matSize; i++){
		for (int j = 0; j < matColSize[0]; j++){
			single_d_arr[j + count] = mat[i][j]; 
		}
		count += matColSize[0]; 
	}

	return single_d_arr; 
}

int** matrixReshape(int** mat, int matSize, int* matColSize, int r, int c, int* returnSize, int** returnColumnSizes) {
	if (r * c != (matSize * matColSize[0])){
		*returnSize = matSize;
		*returnColumnSizes = matColSize;
		return mat; 
	}

	int* one_d = matrix_to_arr(mat, matSize, matColSize); 
    int** res = malloc(r * sizeof(int *)); 
	*returnSize = r; 
	*returnColumnSizes = malloc(r * sizeof(int)); 

	int count = 0; 
	for (int i = 0; i < r; i++){
		res[i] = malloc(c * sizeof(int)); 
		(*returnColumnSizes)[i] = c; 
		for (int j = 0; j < c; j++){
			res[i][j] = one_d[j + count]; 
		}
		count += c; 
	}


	return res; 
}

int main(){
    int matrix[2][3] = {{1,2,3}, {4,5,6}}; 
    int matColSize[] = {3, 3}; 
    int* rows[2]; 
    for (int i = 0; i < 2; i++){
        rows[i] = matrix[i]; 
    }

    int returnSize; 
    int* returnColumnSizes; 
	int matSize = 2; 
    int** res = matrixReshape(rows, matSize, matColSize, 3, 2, &returnSize, &returnColumnSizes); 


    printf("["); 
    for (int i = 0; i < returnSize; i++){
        for (int j = 0; j < returnColumnSizes[i]; j++){
            printf("%d,", res[i][j]); 
        }
    }
    printf("]\n"); 
    return 0; 
}