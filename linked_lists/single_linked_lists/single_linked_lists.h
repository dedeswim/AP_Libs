//
// single_linked_lists - single_linked_lists.h
// Created by Edoardo Debenedetti on 15/10/2017.
//
#ifndef SINGLE_LINKED_LISTS_SINGLE_LINKED_LISTS_H
#define SINGLE_LINKED_LISTS_SINGLE_LINKED_LISTS_H

// STRUCTS
typedef int list_type;
typedef struct _LIST LIST;

// FUNCTIONS
LIST *initList(void);

int insertElement(LIST *head, list_type val, int pos);

int countList(LIST *head);

int emptyList(LIST *head);

int printList(LIST *head);

int removeElement(LIST *head, int pos);

list_type getElement(LIST *head, int pos);

LIST *clearList(LIST *head);

void destroyList(LIST *head);

#endif //SINGLE_LINKED_LISTS_SINGLE_LINKED_LISTS_H
