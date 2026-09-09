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

int minFallingPathSum_recursive(int** matrix, int matrixSize, int row, int column, int** weight_matrix) {
	if (row == matrixSize - 1){
		return matrix[row][column]; 
	}

	if (weight_matrix[row][column] != INT_MAX){
		return weight_matrix[row][column];
	}

	int best = INT_MAX; 
	if (column == 0){
		int option_1 = minFallingPathSum_recursive(matrix, matrixSize, row + 1, column, weight_matrix); //down
		int option_2 = minFallingPathSum_recursive(matrix, matrixSize, row + 1, column + 1, weight_matrix); //right-diagonal 

		if (option_1 < option_2){ weight_matrix[row + 1][column] = option_1; }
		else{ weight_matrix[row + 1][column + 1] = option_2; }
	}

	if (column == matrixSize - 1){
		int option_1 = minFallingPathSum_recursive(matrix, matrixSize, row + 1, column, weight_matrix); //down
		int option_2 = minFallingPathSum_recursive(matrix, matrixSize, row + 1, column - 1, weight_matrix); //left-diagonal 

		if (option_1 < option_2){ weight_matrix[row + 1][column] = option_1; }
		else{ weight_matrix[row + 1][column - 1] = option_2; }
	}

	else{
		int option_1 = minFallingPathSum_recursive(matrix, matrixSize, row + 1, column, weight_matrix); //down
		int option_2 = minFallingPathSum_recursive(matrix, matrixSize, row + 1, column - 1, weight_matrix); //left-diagonal 
		int option_3 = minFallingPathSum_recursive(matrix, matrixSize, row + 1, column + 1, weight_matrix); //right-diagonal 

		int options[] = {option_1, option_2, option_3}; 
		int min = INT_MAX; 
		for (int i = 0; i < 3; i++){
			if (options[i] < min){ min = options[i]; }
		}
		if (min == option_1) { weight_matrix[row + 1][column] = option_1; }
		else if (min == option_2) { weight_matrix[row + 1][column - 1] = option_2; }
		else if (min == option_3) { weight_matrix[row + 1][column + 1] = option_3; }
	}


}

int minFallingPathSum(int** matrix, int matrixSize, int* matrixColSize) {
	if (matrixSize == 1){
		int min = 101; 
		for (int i = 0; i < matrixColSize[0]; i++){
			if (matrix[0][i] < min){ min = matrix[0][i]; }
		}
		return min; 
	}


	int** weight_matrix = malloc(matrixSize * sizeof(int*)); 
	for (int i = 0; i < matrixSize; i++){
		weight_matrix[i] = malloc(matrixColSize[0] * sizeof(int));
		for (int j = 0; j < matrixColSize[0]; j++){
			weight_matrix[i][j] = matrix[i][j];  // actual value copy
		}
	}

	for (int i = 0; i < matrixSize; i++){
		for (int j = 0; j < matrixColSize[0]; j++){
			weight_matrix[i][j] = INT_MAX; //constraint on the problem makes it so. 
		}
	}

	for (int i = 0; i < 1; i++){
		for (int j = 0; j < matrixColSize[0]; j++){
			weight_matrix[i][j] = matrix[i][j]; 
		}
	}

	int row = 0; 
	int column = 0; 
	int res = INT_MAX; 
	for (int j = 0; j < matrixColSize[0]; j++) {
		int val = minFallingPathSum_recursive(matrix, matrixSize, 0, j, weight_matrix);
		if (val < res) res = val;
	}

	for (int i = 0; i < matrixSize; i++){
		free(weight_matrix[i]); 
	}
	free(weight_matrix); 

	return res; 
}

int main(){

}