//
// stack_bounded_array - stack_bounded_array.h
// Created by Edoardo Debenedetti on 12/10/2017.
//
#ifndef STACK_BOUNDED_ARRAY_STACK_BOUNDED_ARRAY_H
#define STACK_BOUNDED_ARRAY_STACK_BOUNDED_ARRAY_H

// STRUCT
typedef struct _STACK STACK;

// PROTOS
STACK* createIntStack(int size);
void freeIntStack(STACK* stack);
void printIntStack(STACK* stack);
void push(STACK* stack, int val);
int pop(STACK* stack, int* a);
int stackEmpty(STACK* stack);

#endif //STACK_BOUNDED_ARRAY_STACK_BOUNDED_ARRAY_H
