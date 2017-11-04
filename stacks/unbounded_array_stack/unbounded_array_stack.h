//
// unbounded_array_stack - unbounded_array_stack.h
// Created by Edoardo Debenedetti on 12/10/2017.
//
#ifndef UNBOUNDED_ARRAY_STACK_UNBOUNDED_ARRAY_STACK_H
#define UNBOUNDED_ARRAY_STACK_UNBOUNDED_ARRAY_STACK_H
#define SIZE_UNIT 2

// STRUCT
typedef int stack_type;
typedef struct _STACK {
    int maxSize; // max size of the allocated stack
    int index; // index of the last element of the stack
    int nSizeUnits; // units of allocated memory
    stack_type *start; // stack
} STACK;


// PROTOS
STACK *createIntStack(void);

void printIntStack(STACK *p);

stack_type pop(STACK *p);

void push(STACK *p, stack_type value);

void freeIntStack(STACK *p);

STACK *clearStack(STACK *p);

#endif //UNBOUNDED_ARRAY_STACK_UNBOUNDED_ARRAY_STACK_H
