//
// stack_linked_list - stack_linked_lists.c
// Created by Edoardo Debenedetti on 16/10/2017.
//

// INCLUDES
#include <stdio.h>
#include <stdlib.h>
#include "stack_linked_lists.h"


// STRUCTS
typedef struct _STACK {
    int actualSize; // stack size
    LIST *start; // stack
} STACK;

// FUNCTIONS
STACK *createStack(void) { // initializes the stack
    STACK *p = (STACK *) malloc(sizeof(STACK));
    if (!p) exit(EXIT_FAILURE);
    p->start = initListForStack();
    if (!p->start) exit(EXIT_FAILURE);
    p->actualSize = 0;
    return p;
}

void *freeStack(STACK *stack) { // frees the stack
    destroyListForStack(stack->start);
    free(stack);
}

void push(STACK *stack, list_type val) { // pushes 'val' in the stack
    insertElementForStack(stack->start, val, ++stack->actualSize);
}

list_type pop(STACK *stack) { // pops the last element in the stack
    list_type val = getElementForStack(stack->start, stack->actualSize);
    removeElementForStack(stack->start, stack->actualSize--);
    return val;
}

void printStack(STACK *p) { // prints the stack
    if (p->actualSize == 0) {
        printf("The stack is empty.\n");
    } else {
        printf("Stack:");
        printListForStack(p->start);
        printf("\n");
    }
}