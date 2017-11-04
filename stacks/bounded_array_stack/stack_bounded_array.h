//
// stack_bounded_array - stack_bounded_array.h
// Created by Edoardo Debenedetti on 12/10/2017.
//
#ifndef STACK_BOUNDED_ARRAY_STACK_BOUNDED_ARRAY_H
#define STACK_BOUNDED_ARRAY_STACK_BOUNDED_ARRAY_H

// STRUCT
typedef int stack_type;
typedef struct _STACK STACK;

// PROTOS
STACK* createStack(int size);
void freeStack(STACK *stack);
void printStack(STACK *stack);
void push(STACK* stack, stack_type val);
int pop(STACK* stack, stack_type * a);
int stackEmpty(STACK* stack);

#endif //STACK_BOUNDED_ARRAY_STACK_BOUNDED_ARRAY_H
