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

int minPathSum(int** grid, int gridSize, int* gridColSize) {

}

int minPathSum_recursive(int** grid, int gridSize, int* gridColSize, int acc) {
	if (gridSize == 1){
		for (int i = gridColSize[0] - 1; i >= 0; i--){
			acc += grid[0][i]; 
		}
		return acc; 
	}
	else if (gridColSize[0] == 1){
		for (int i = gridColSize[0] - 1; i >= 0; i--){
			acc += grid[i][0]; 
		}
		return acc; 
	}
	int option_2; 
	else{
		option_2 = 
	}
	int option_1 = minPathSum_recursive(grid, gridSize - 1, gridColSize, acc + grid[gridColSize[0]]); 
}