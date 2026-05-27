/*
Problem: transpose
Link: easy 
Difficulty:
Topic(s):
Pattern:

Description:
Given a 2D integer array matrix, return the transpose of matrix.
The transpose of a matrix is the matrix flipped over its main diagonal, switching the matrix's row and column indices.

Constraints:

Initial idea:
Create a new array with reverse directions of the original one and fill it using two loops. 

Final approach:

Complexity: n^2
Time:
Space:

Mistakes / difficulties:
Bad with pointers, but it becomes much easier once you name your variables consistently. 

Key lesson:

Review:
- Solved on:
- Revisit:
*/

#include <stdio.h>
#include <stdlib.h>

int** transpose(int** matrix, int matrixSize, int* matrixColSize, int* returnSize, int** returnColumnSizes) {
    int rows = matrixSize;
    int cols = matrixColSize[0];

    int** transpose_array = malloc(cols * sizeof(int*));
    *returnColumnSizes = malloc(cols * sizeof(int));
    *returnSize = cols;

    for (int i = 0; i < cols; i++) {
        transpose_array[i] = malloc(rows * sizeof(int));
        (*returnColumnSizes)[i] = rows;
        for (int j = 0; j < rows; j++) {
            transpose_array[i][j] = matrix[j][i];
        }
    }
    return transpose_array;
}

int main(){
    int matrix[3][3] = {{1,2,3}, {4,5,6}, {7,8,9}}; 
    int matrixColSize[] = {3, 3, 3}; 
    int* rows[3]; 
    for (int i = 0; i < 3; i++){
        rows[i] = matrix[i]; 
    }

    int returnSize; 
    int* returnColumnSizes; 
    int** res = transpose(rows, 3, matrixColSize, &returnSize, &returnColumnSizes); 

    printf("["); 
    for (int i = 0; i < returnSize; i++){
        for (int j = 0; j < returnColumnSizes[i]; j++){
            printf("%d,", res[i][j]); 
        }
    }
    printf("]\n"); 
    
    
    return 0; 
}