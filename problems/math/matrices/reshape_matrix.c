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

int** matrixReshape(int** mat, int matSize, int* matColSize, int r, int c, int* returnSize, int** returnColumnSizes) {
	if (r * c != (matSize * matColSize[0])){
		return mat; 
	}
	else if (r = matSize){
		return mat; 
	}

    int** res = malloc(r * sizeof(int *)); 
	*returnSize = r; 
	returnColumnSizes = malloc(r * sizeof(int)); 
	for (int i = 0; i < r; i++){
		res[i] = malloc(c * sizeof(int)); 
		(*returnColumnSizes)[i] = c; 
		for (int j = 0; j < c; j++){
						
		}
	}


	return res; 
}

int main(){
    int matrix[2][2] = {{1,2}, {3,4}}; 
    int matrixColSize[] = {2, 2}; 
    int* rows[2]; 
    for (int i = 0; i < 2; i++){
        rows[i] = matrix[i]; 
    }

    int returnSize; 
    int* returnColumnSizes; 
	int matSize = 2; 
    int** res = matrixReshape(rows, matSize, matrixColSize, 1, 4, &returnSize, &returnColumnSizes); 

    printf("["); 
    for (int i = 0; i < returnSize; i++){
        for (int j = 0; j < returnColumnSizes[i]; j++){
            printf("%d,", res[i][j]); 
        }
    }
    printf("]\n"); 
    return 0; 
}