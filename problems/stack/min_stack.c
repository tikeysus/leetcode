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
    int stack_top; 
	size_t capacity; 
	int min_element; 
	int* stack;
} MinStack;


MinStack* minStackCreate() {
	MinStack minstack; 
	minstack.stack_top = -1; //empty 
	minstack.capacity = 100; 
	minstack.min_element = -1; //can also do this because we are guaranteed that minStack will only be called on a non-empty array
	int* stack = malloc(minstack.capacity * sizeof(int)); 
	minstack.stack = stack; 
}

void minStackPush(MinStack* obj, int val) {
	size_t capacity = (*obj).capacity; 
	int stack_top = (*obj).stack_top; 
	int min_element = (*obj).min_element; 
	int* stack = (*obj).stack; 

    if (stack_top >= capacity - 1){
		capacity *= 2; 
		int* temp = realloc(stack, capacity);
		if (temp == NULL){
			return 1; 
		}
		stack = temp; 
	}
	if (stack_top == -1){
		stack_top++; 
		stack[stack_top] = val; 
		min_element = val; 
		stack_top++; 
	}
	else{
		if (val < min_element){
			min_element = val; 
		}
		stack[stack_top] = val;
		stack_top++; 
	}

	(*obj).capacity = capacity; 
	(*obj).stack_top = stack_top; 
	(*obj).min_element = min_element; 
	(*obj).stack = stack; 
}

void minStackPop(MinStack* obj) {
	size_t capacity = (*obj).capacity; 
	int stack_top = (*obj).stack_top; 
	int min_element = (*obj).min_element; 
	int* stack = (*obj).stack; 

	if (min_element != stack[stack_top - 1]){
		obj->stack_top--; 
		return; 
	}

	MinStack* new_stack = minStackCreate();
	new_stack->capacity = capacity;
	new_stack->stack_top = stack_top - 1; 
}

int minStackTop(MinStack* obj) {
	int stack_top = (*obj).stack_top; 
	int* stack = (*obj).stack; 

	return stack[stack_top - 1]; 
}

int minStackGetMin(MinStack* obj) {
    int min_element = (*obj).min_element; 
	return min_element; 
}

void minStackFree(MinStack* obj) {
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