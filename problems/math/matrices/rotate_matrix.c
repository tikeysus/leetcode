/*
Problem: rotate matrix
Link:
Difficulty:
Topic(s):
Pattern:

Description:
You are given an n x n 2D matrix representing an image, rotate the image by 90 degrees (clockwise).
You have to rotate the image in-place, which means you have to modify the input 2D matrix directly. DO NOT allocate another 2D matrix and do the rotation.

Constraints:

Initial idea:
Interesting problem, I don't really have a plan, let's play around and see what happens. 

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

void transpose(int** matrix, int matrixSize, int* matrixColSize){
	for (int i = 0; i < matrixSize; i++){
		for (int j = i + 1; j < matrixColSize[i]; j++){
			int temp = matrix[i][j]; 
			matrix[i][j] = matrix[j][i]; 
			matrix[j][i] = temp; 
		}
	}
}

void row_reverse(int** matrix, int matrixSize, int* matrixColSize){
	for (int i = 0; i < matrixSize; i++){
		int left = 0; 
		int right = matrixColSize[0] - 1; 
		while (left < right){
			int temp = matrix[i][left];
			matrix[i][left] = matrix[i][right]; 
			matrix[i][right] = temp; 
			left++; 
			right--; 
		}
	}
}

void rotate(int** matrix, int matrixSize, int* matrixColSize) {
	transpose(matrix, matrixSize, matrixColSize); 
	row_reverse(matrix, matrixSize, matrixColSize); 
}