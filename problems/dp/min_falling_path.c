/*
Problem: min falling path
Link:
Difficulty:
Topic(s):
Pattern:

Description:
Given an n x n array of integers matrix, return the minimum sum of any falling path through matrix.
A falling path starts at any element in the first row and chooses the element in the next row that is either directly below or diagonally left/right. Specifically, the next element from position (row, col) will be (row + 1, col - 1), (row + 1, col), or (row + 1, col + 1).

Constraints:

Initial idea:
I honestly don't know for now. Will have to just type something out. 

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
#include <limits.h>

int minFallingPathSum(int** matrix, int matrixSize, int* matrixColSize) {
	if (matrixSize == 1){ return matrix[0][0]; } //matrix has to be square 

	for (int i = 1; i < matrixSize; i++){
		for (int j = 0; j < matrixColSize[0]; j++){
			if (j == 0){
				int option_1 = matrix[i - 1][j] + matrix[i][j]; //up
				int option_2 = matrix[i - 1][j + 1] + matrix[i][j]; //right-diagonal 

				matrix[i][j] = (option_1 < option_2) ? option_1 : option_2; 
			}
			else if (j == matrixColSize[0] - 1){
				int option_1 = matrix[i - 1][j] + matrix[i][j]; //up
				int option_2 = matrix[i - 1][j - 1] + matrix[i][j]; //left-diagonal 

				matrix[i][j] = (option_1 < option_2) ? option_1 : option_2; 
			}
			else{
				int option_1 = matrix[i - 1][j] + matrix[i][j]; //up
				int option_2 = matrix[i - 1][j - 1] + matrix[i][j]; //left-diagonal 
				int option_3 = matrix[i - 1][j + 1] + matrix[i][j]; //right-diagonal 

				int options[] = {option_1, option_2, option_3}; 
				int min = option_1; 
				for (int i = 1; i < 3; i++){
					if (options[i] < min) { min = options[i]; }
				}
				matrix[i][j] = min; 
			}
		}
	}

	int res = matrix[matrixSize - 1][0];
	for (int i = 1; i < matrixColSize[0]; i++){
		if (matrix[matrixSize - 1][i] < res) { res = matrix[matrixSize - 1][i]; }
	}
	return res; 
}