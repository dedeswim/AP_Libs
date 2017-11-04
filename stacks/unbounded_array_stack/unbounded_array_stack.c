//
// unbounded_array_stack - unbounded_array_stack.c
// Created by Edoardo Debenedetti on 12/10/2017.
//

// INCLUDES
#include <stdio.h>
#include <stdlib.h>
#include "unbounded_array_stack.h"


// FUNCTIONS
STACK *createIntStack(void) { // initializes the stack
    STACK *p = (STACK *) malloc(sizeof(STACK));
    if (!p) exit(EXIT_FAILURE);
    p->nSizeUnits = 1;
    p->maxSize = p->nSizeUnits * SIZE_UNIT;
    p->index = p->maxSize - 1;
    p->start = (int) malloc(p->maxSize * sizeof(int));
    if (!p->start) exit(EXIT_FAILURE);
    for (int t = 0; t < p->maxSize; ++t) {
        p->start[t] = 0;
    }
    return p;
}

void printIntStack(STACK *p) { // prints the stack
    if (p->index == p->maxSize - 1) {
        printf("The stack is empty.\n");
    } else {
        printf("Stack:");
        for (int t = p->maxSize - 1; t > p->index; --t) {
            printf(" %d", p->start[t]);
        }
        printf("\n");
    }
}

stack_type pop(STACK *p) { // pops the first element of the stack
    if (p->index == p->maxSize - 1) {
        printf("The stack is empty.\n");
        return 1;
    }
    stack_type val = p->start[++p->index];
    if (p->index == 1) {
        p->maxSize = --p->nSizeUnits * SIZE_UNIT;
        stack_type *buffer = (stack_type *) malloc(p->maxSize * sizeof(stack_type));
        for (int t = 0; t < p->maxSize; ++t) {
            buffer[t] = p->start[t + 2];
        }
        free(p->start);
        p->start = buffer;
        p->index = -1;
    }
    return val;
}

void push(STACK *p, stack_type value) { // pushes 'value' in the stack
    if (p->index >= 0) {
        p->start[p->index--] = value;
    } else {
        stack_type *buffer = (stack_type *) malloc((2 + p->maxSize) * sizeof(stack_type));
        for (int t = 0; t < p->maxSize + 2; ++t) {
            if (t < 2) {
                buffer[t] = 0;
            } else {
                buffer[t] = p->start[t - 2];
            }
        }
        // int prevMax = p->maxSize;
        p->maxSize = SIZE_UNIT * ++p->nSizeUnits;
        free(p->start);
        p->start = buffer;
        p->index += 2;
        p->start[p->index--] = value;
    }
}

void freeIntStack(STACK *p) { // frees the stack
    free(p->start);
    free(p);
    printf("Memory freed successfully\n");
}

STACK *clearStack(STACK *p) { // clears the stack
    p->nSizeUnits = 1;
    p->maxSize = p->nSizeUnits * SIZE_UNIT;
    p->index = p->maxSize - 1;
    p->start = (int) realloc(p->start, p->maxSize * sizeof(int));
    p->nSizeUnits = 1;
    p->maxSize = p->nSizeUnits * SIZE_UNIT;
    p->index = p->maxSize - 1;
    printf("Stack cleared successfully\n");
    return p;
};