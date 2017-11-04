//
// stack_linked_list - stack_linked_lists.h
// Created by Edoardo Debenedetti on 16/10/2017.
//
#ifndef STACK_LINKED_LIST_STACK_LINKED_LISTS_H
#define STACK_LINKED_LIST_STACK_LINKED_LISTS_H

#include "linked_lists_for_stacks.h"

// STRUCTS
typedef struct _STACK STACK;


// FUNCTIONS
STACK *createStack(void);

STACK *freeStack(STACK *stack);

void push(STACK *stack, list_type val);

int pop(STACK *stack);

void printStack(STACK *p);

#endif //STACK_LINKED_LIST_STACK_LINKED_LISTS_H
