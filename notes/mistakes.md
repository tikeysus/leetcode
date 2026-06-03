## Bit Manipulation 

- Coming up with solutions that are too iterative in nature, the whole point of bit manipulation is to consider numbers bit by bit.

## Memory Management 

- Anything allocated by malloc() must be then manually freed so that it does not persist living on the heap. See below.
```c
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
void minStackFree(MinStack* obj) {
    free(obj->stack);
    free(obj->min_stack);
    free(obj);
}
```
- Not only do we free `obj`, but we also free `stack` and `min_stack`. 
