/*
Problem: min path sum
Link:
Difficulty:
Topic(s):
Pattern:

Description:
Given a m x n grid filled with non-negative numbers, find a path from top left to bottom right, which minimizes the sum of all numbers along its path.
Note: You can only move either down or right at any point in time.

Constraints:

Initial idea:
Bottom-up DP. Need to write on paper to see the pattern. 

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

#include<stdio.h>

int minPathSum_recursive(int** grid, int gridSize, int gridColSize, int acc) {
	if (gridSize == 1){
		for (int i = gridColSize - 1; i >= 0; i--){
			acc += grid[0][i]; 
		}
		return acc; 
	}
	else if (gridColSize == 1){
		for (int i = gridSize - 1; i >= 0; i--){
			acc += grid[i][0]; 
		}
		return acc; 
	}
	int left = minPathSum_recursive(grid, gridSize, gridColSize - 1, acc + grid[gridSize - 1][gridColSize - 1]); 
	int up = minPathSum_recursive(grid, gridSize - 1, gridColSize, acc + grid[gridSize - 1][gridColSize - 1]); 
	if (left < up){
		return left; 
	}
	else{ return up; }
}

int minPathSum(int** grid, int gridSize, int* gridColSize) {
	if (gridSize == 1){ 
		int acc = 0; 
		for (int i = 0; i < gridColSize[0]; i++){ acc += grid[0][i]; }
		return acc; 
	}
	return minPathSum_recursive(grid, gridSize, gridColSize[0], 0);
}


int main(){
	int grid[2][3] = {
		{1,2,3},
		{4,5,6}, 
	}; 
	int gridSize = 2; 
	int gridColSize[] = {3,3}; 
	int* row_pointers[2]; 
	row_pointers[0] = grid[0]; 
	row_pointers[1] = grid[1]; 
	int res = minPathSum(row_pointers, gridSize, gridColSize); 
	printf("%d\n", res); 

	return 0; 
}