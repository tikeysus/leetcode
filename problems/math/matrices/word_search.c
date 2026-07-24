/*
Problem: word search
Link:
Difficulty:
Topic(s):
Pattern:

Description:

Constraints:
Given an m x n grid of characters board and a string word, return true if word exists in the grid.
The word can be constructed from letters of sequentially adjacent cells, where adjacent cells are horizontally or vertically neighboring. The same letter cell may not be used more than once.

Initial idea:

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

#include <stdbool.h>

bool exist(char** board, int boardSize, int* boardColSize, char* word) {	
	int x = -1;
	int y = -1; 
	for (int i = 0; i < boardSize; i++){
		for (int j = 0; j < boardColSize[i]; j++){
			if (*word == '\0'){
				return true; 
			}
			for (int k = 0; word[k] != '\0'; k++){
				if (board[i][j] == word[k]){
					if (x == - 1 && y == -1){
						x = i; y = j; break; 
					}
					if (j - 1 == y || )
					word[k] = '5'; //dummy value
				}
			}
		}
	}
	return false; 
}


