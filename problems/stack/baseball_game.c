/*
Problem: baseball game
Link:
Difficulty: Easy
Topic(s):
Pattern: Stack type thinking 

Description:
You are keeping the scores for a baseball game with strange rules. At the beginning of the game, you start with an empty record.
You are given a list of strings operations, where operations[i] is the ith operation you must apply to the record and is one of the following:
An integer x.
Record a new score of x.
'+'.
Record a new score that is the sum of the previous two scores.
'D'.
Record a new score that is the double of the previous score.
'C'.
Invalidate the previous score, removing it from the record.
Return the sum of all the scores on the record after applying all the operations.
The test cases are generated such that the answer and all intermediate calculations fit in a 32-bit integer and that all operations are valid.

Constraints:
1 <= operations.length <= 1000
operations[i] is "C", "D", "+", or a string representing an integer in the range [-3 * 104, 3 * 104].
For operation "+", there will always be at least two previous scores on the record.
For operations "C" and "D", there will always be at least one previous score on the record.

Initial idea:
Going through the loop and branching, the only tricky part is allocating and reallocating memory. 

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

#include <stdio.h>
#include <stdlib.h>

int nums_sum(int *nums, size_t numsSize) {
    int sum = 0;
    for (int i = 0; i < numsSize; i++){
        sum += nums[i];
    }
    return sum;
}

int calPoints(char **operations, int operationsSize) {
    size_t size = 0;
    int *ops_tracker = malloc(operationsSize * sizeof(*ops_tracker));
    if (ops_tracker == NULL) {
        return 1;
    }

    while (operationsSize > 0) {
        char *curr_op = *operations;
        if (curr_op[0] == '+') {
            ops_tracker[size] = ops_tracker[size - 1] + ops_tracker[size - 2];
            size++;
        }
        else if (curr_op[0] == 'D') {
            ops_tracker[size] = ops_tracker[size - 1] * 2;
            size++;
        }
        else if (curr_op[0] == 'C') {
            size--;
        }
        else {
            ops_tracker[size] = atoi(curr_op);
            size++;
        }
        operations++;
        operationsSize--;
    }

    int sum = nums_sum(ops_tracker, size);
    free(ops_tracker);
    return sum;
}

int main(){
	char *operations[] = {"5", "200001", "C"};
	int operationsSize = sizeof(operations)/sizeof(operations[0]); 
	int res = calPoints(operations, operationsSize); 
	printf("%d\n", res); 
	return 0; 
}