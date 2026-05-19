int main(){
    int matrix[][] = {}; 
    int matrixColSize[] = {}; 
	int matrixSize;
    int* rows[]; 
    for (int i = 0; i < matrixSize; i++){
        rows[i] = matrix[i]; 
    }

    int returnSize; 
    int* returnColumnSizes; 
    int** res = fn(rows, matrixSize, matrixColSize, &returnSize, &returnColumnSizes); 

    printf("["); 
    for (int i = 0; i < returnSize; i++){
		printf("["); 
        for (int j = 0; j < returnColumnSizes[i]; j++){
            printf("%d,", res[i][j]); 
        }
		printf("]"); 
    }
    printf("]\n"); 
 
	return 0; 
}