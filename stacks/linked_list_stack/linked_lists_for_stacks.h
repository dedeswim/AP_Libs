//
// single_linked_lists - single_linked_lists.h
// Created by Edoardo Debenedetti on 15/10/2017.
//
#ifndef SINGLE_LINKED_LISTS_SINGLE_LINKED_LISTS_H
#define SINGLE_LINKED_LISTS_SINGLE_LINKED_LISTS_H

// STRUCTS
typedef struct _LIST LIST;

// FUNCTIONS
LIST *initListForStack(void);

int insertElementForStack(LIST *head, int val, int pos);

int countListForStack(LIST *head);

int emptyListForStack(LIST *head);

int printListForStack(LIST *head);

int removeElementForStack(LIST *head, int pos);

int getElementForStack(LIST *head, int pos);

LIST *clearListForStack(LIST *head);

void destroyListForStack(LIST *head);

#endif //SINGLE_LINKED_LISTS_SINGLE_LINKED_LISTS_H
