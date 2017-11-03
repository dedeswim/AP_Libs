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
    int *start; // stack
} STACK;

// FUNCTIONS
STACK *createIntStack(int size) { // initializes the stack
    STACK *istack = (STACK *) malloc(sizeof(STACK));
    if (!istack) exit(EXIT_FAILURE);
    istack->maxSize = size;
    istack->start = (int) malloc(sizeof(int) * istack->maxSize);
    if (!istack->start) exit(EXIT_FAILURE);
    for (int t = 0; t < istack->maxSize; ++t) {
        istack->start[t] = 0;
    }
    istack->index = istack->maxSize;
    return istack;
}

void freeIntStack(STACK *stack) { // frees the stack
    free(stack->start);
    free(stack);
}

void printIntStack(STACK *stack) { // prints the stack
    printf("Stack:");
    for (int t = stack->maxSize; t > stack->index; --t) {
        printf(" %d", stack->start[t]);
    }
    printf(";\n");
}

void push(STACK *stack, int val) { // pushes 'val' into the stack
    stack->start[stack->index--] = val;
}

int pop(STACK *stack, int *a) { // pops the last element of the stack
    if (stackEmpty(stack) == 1) {
        printf("Error: the stack is empty.\n");
        return 1;
    }
    *a = stack->start[++stack->index];
    return 0;
}

int stackEmpty(STACK *stack) { // empties the stack
    if (stack->maxSize == stack->index) return 1;
    return 0;
}

