//
// stack_bounded_array - stack_bounded_array.c
// Created by Edoardo Debenedetti on 12/10/2017.
//


// INCLUDES
#include <stdio.h>
#include <stdlib.h>
#include "stack_bounded_array.h"

// STRUCTS
typedef struct _STACK {
    int maxSize; // max size of the stack
    int index; // index of the last element of the stack
    stack_type *start; // stack
} STACK;

// FUNCTIONS
STACK *createStack(int size) { // initializes the stack
    STACK *stack = (STACK *) malloc(sizeof(STACK));
    if (!stack) exit(EXIT_FAILURE);
    stack->maxSize = size;
    stack->start = (stack_type *) malloc(sizeof(stack_type) * stack->maxSize);
    if (!stack->start) exit(EXIT_FAILURE);
    for (int t = 0; t < stack->maxSize; ++t) {
        stack->start[t] = 0;
    }
    stack->index = stack->maxSize;
    return stack;
}

void freeStack(STACK *stack) { // frees the stack
    free(stack->start);
    free(stack);
}

void printStack(STACK *stack) { // prints the stack
    printf("Stack:");
    for (int t = stack->maxSize; t > stack->index; --t) {
        printf(" %d", stack->start[t]);
    }
    printf(";\n");
}

void push(STACK *stack, stack_type val) { // pushes 'val' into the stack
    stack->start[stack->index--] = val;
}

stack_type pop(STACK *stack, stack_type *a) { // pops the last element of the stack
    if (stackEmpty(stack) == 1) {
        printf("Error: the stack is empty.\n");
        return 1;
    }
    *a = stack->start[++stack->index]; // assigns to 'a' the value of the popped value
    return 0;
}

int stackEmpty(STACK *stack) { // empties the stack
    if (stack->maxSize == stack->index) return 1;
    return 0;
}

