//
// single_linked_lists - single_linked_lists.c
// Created by Edoardo Debenedetti on 15/10/2017.
//

// INCLUDES
#include <stdio.h>
#include <stdlib.h>
#include "linked_lists_for_stacks.h"

// NECESSARY LISTS STUFF TO MAKE THE STACK WORK

// STRUCTS
typedef struct _LIST {
    list_type val; // data
    struct _LIST *next;
} LIST;

// FUNCTIONS
LIST *initListForStack(void) {
    LIST *head = (LIST *) malloc(sizeof(LIST));
    if (!head) exit(EXIT_FAILURE);
    LIST *tail = (LIST *) malloc(sizeof(LIST));
    if (!tail) exit(EXIT_FAILURE);
    head->next = tail;
    tail->next = NULL;
    return head;
}

int countListForStack(LIST *head) {
    LIST *ptr = head;
    int t;
    for (t = 0; ptr->next != NULL; ++t) {
        ptr = ptr->next;
    }
    return t - 1;
}

int emptyListForStack(LIST *head) {
    if (countListForStack(head) == 0) {
        return 1;
    }
    return 0;
}

int insertElementForStack(LIST *head, list_type val, int pos) {
    LIST *ptr = head;
    for (int t = 0; t < pos - 1; ++t) ptr = ptr->next;
    LIST *new = (LIST *) malloc(sizeof(LIST));
    if (!new) exit(EXIT_FAILURE);
    new->val = val;
    new->next = ptr->next;
    ptr->next = new;
    return 0;
}

int printListForStack(LIST *head) {
    LIST *ptr = head->next;
    while (ptr->next != NULL) {
        printf(" %d", ptr->val);
        ptr = ptr->next;
    }
    printf(".\n");
    return 0;
}

int removeElementForStack(LIST *head, int pos) {
    LIST *ptr = head;
    for (int t = 0; t < pos - 1; ++t) ptr = ptr->next;
    LIST *toRemove = ptr->next;
    ptr->next = ptr->next->next;
    free(toRemove);
    return 0;
}

list_type getElementForStack(LIST *head, int pos) {
    LIST *ptr = head;
    for (int t = 0; t < pos; ++t) ptr = ptr->next;
    return ptr->val;
}

LIST *clearListForStack(LIST *head) {
    while (!emptyListForStack(head)) {
        LIST *ptr = head->next;
        head->next = ptr->next;
        free(ptr);
    }
    return head;
}

void destroyListForStack(LIST *head) {
    clearListForStack(head);
    free(head->next);
    free(head);
}