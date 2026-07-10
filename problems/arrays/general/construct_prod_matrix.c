/*
Problem: construct prod matrix
Link:
Difficulty: Medium 
Topic(s):
Pattern: 

Description:

Constraints:

Initial idea:
I suspect that this has the same underlying idea as the product of array except self problem. 
So once again something to do with prefixes and suffixes. 

Final approach:

Complexity: n^2, solution is quite inneficient, there is probably a better way. 
Time:
Space:

Mistakes / difficulties:
I HAVE TO GET BETTER AT POINTERS AND MEMORY MANAGEMENT. 

Key lesson:

Review:
- Solved on:
- Revisit:
*/

#include <stdio.h>
#include <stdlib.h>

int** prefix_array(int** grid, int gridSize, int* gridColSize, int* returnSize, int** returnColumnSizes) {
    int** prefix_arr = malloc(gridSize * sizeof(int*));
    *returnColumnSizes = malloc(gridSize * sizeof(int));

    int product = 1; 
    for (int i = 0; i < gridSize; i++) {
        prefix_arr[i] = malloc(gridColSize[i] * sizeof(int));
        (*returnColumnSizes)[i] = gridColSize[i];

        for (int j = 0; j < gridColSize[i]; j++) {
            prefix_arr[i][j] = product;
            product = ((long long)product * grid[i][j]) % 12345;
        }
    }

    *returnSize = gridSize;
    return prefix_arr;
}

int** suffix_array(int** grid, int gridSize, int* gridColSize, int* returnSize, int** returnColumnSizes){
    int** suffix_arr = malloc(gridSize * sizeof(int*));
    *returnColumnSizes = malloc(gridSize * sizeof(int));

    int product = 1; 
    for (int i = gridSize - 1; i >= 0; i--) {
        suffix_arr[i] = malloc(gridColSize[i] * sizeof(int));
        (*returnColumnSizes)[i] = gridColSize[i];

        for (int j = gridColSize[i] - 1; j >= 0; j--) {
            suffix_arr[i][j] = product;
            product = ((long long)product * grid[i][j]) % 12345;
        }
    }

    *returnSize = gridSize;
    return suffix_arr;
}

int** constructProductMatrix(int** grid, int gridSize, int* gridColSize, int* returnSize, int** returnColumnSizes) {
    int** suffix_arr = suffix_array(grid, gridSize, gridColSize, returnSize, returnColumnSizes); 
    int** prefix_arr = prefix_array(grid, gridSize, gridColSize, returnSize, returnColumnSizes); 
    int** res_arr = malloc(gridSize * sizeof(int *)); 

    for (int i = 0; i < gridSize; i++){
        res_arr[i] = malloc(gridColSize[i] * sizeof(int)); 
        (*returnColumnSizes)[i] = gridColSize[i];
        for (int j = 0; j < gridColSize[i]; j++){
            res_arr[i][j] = ((long long)suffix_arr[i][j] * prefix_arr[i][j]) % 12345;
        }
    }

    *returnSize = gridSize; 
    return res_arr; 
}

int main(){
    int input[3][3] = {{1,2,3}, {4,5,6}}; 
    int gridColSize[] = {3, 3, 3}; 
    int returnSize; 
    int *returnColumnSizes; 

    int* rows[2];
    for (int i = 0; i < 2; i++) {
        rows[i] = input[i];
    }

    int** res_arr = constructProductMatrix(rows, 2, gridColSize, &returnSize, &returnColumnSizes); 

    printf("["); 
    for (int i = 0; i < 2; i++){
        for (int j = 0; j < 3; j++){
            printf("%d,", res_arr[i][j]); 
        }
    }
    printf("]\n"); 
    
    return 0; 
}