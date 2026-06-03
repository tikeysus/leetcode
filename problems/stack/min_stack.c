/*
Problem: min stack
Link:
Difficulty: Medium 
Topic(s):
Pattern:

Description:
Design a stack that supports push, pop, top, and retrieving the minimum element in constant time.

Implement the MinStack class:

MinStack() initializes the stack object.
void push(int val) pushes the element val onto the stack.
void pop() removes the element on the top of the stack.
int top() gets the top element of the stack.
int getMin() retrieves the minimum element in the stack.
You must implement a solution with O(1) time complexity for each function.

Constraints:
Methods pop, top and getMin operations will always be called on non-empty stacks.

Initial idea:
The problem requires a linear time complexity for each of the functions, which makes me think that the struct should track the min element

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

typedef struct {
    int stack_top;      // number of elements
    size_t capacity;
    int* stack;
    int* min_stack;
} MinStack;

MinStack* minStackCreate() {
    MinStack* obj = malloc(sizeof(MinStack));

    obj->stack_top = 0;
    obj->capacity = 100;
    obj->stack = malloc(100 * sizeof(int));
    obj->min_stack = malloc(100 * sizeof(int));

    return obj;
}

void minStackPush(MinStack* obj, int val) {
    if (obj->stack_top >= obj->capacity) {
        obj->capacity *= 2;

        obj->stack = realloc(obj->stack, obj->capacity * sizeof(int));
        obj->min_stack = realloc(obj->min_stack, obj->capacity * sizeof(int));
    }

    int i = obj->stack_top;
    obj->stack[i] = val;

    if (i == 0) {
        obj->min_stack[i] = val;
    } else if (val < obj->min_stack[i - 1]) {
        obj->min_stack[i] = val;
    } else {
        obj->min_stack[i] = obj->min_stack[i - 1];
    }
    obj->stack_top++;
}

void minStackPop(MinStack* obj) {
    obj->stack_top--;
}

int minStackTop(MinStack* obj) {
    return obj->stack[obj->stack_top - 1];
}

int minStackGetMin(MinStack* obj) {
    return obj->min_stack[obj->stack_top - 1];
}

void minStackFree(MinStack* obj) {
    free(obj->stack);
    free(obj->min_stack);
    free(obj);
}

/**
 * Your MinStack struct will be instantiated and called as such:
 * MinStack* obj = minStackCreate();
 * minStackPush(obj, val);
 
 * minStackPop(obj);
 
 * int param_3 = minStackTop(obj);
 
 * int param_4 = minStackGetMin(obj);
 
 * minStackFree(obj);
*/