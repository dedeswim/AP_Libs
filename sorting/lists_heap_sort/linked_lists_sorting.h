//
// lists_sort - linked_lists_sorting.h
// Created by Edoardo Debenedetti on 01/11/2017.
//
#ifndef LISTS_SORT_LINKED_LISTS_SORTING_H
#define LISTS_SORT_LINKED_LISTS_SORTING_H

// STRUCTS
typedef int list_type;
typedef struct _LIST {
    list_type val; // data
    struct _LIST *next;
} LIST;

// PROTOS
LIST **arrayList(LIST *head);

LIST *rebuildList(LIST **array, LIST *head);

LIST *initList(void);

void addElement(LIST *head, list_type val);

void printList(LIST *head);

#endif //LISTS_SORT_LINKED_LISTS_SORTING_H