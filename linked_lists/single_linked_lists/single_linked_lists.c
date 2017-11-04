//
// single_linked_lists - single_linked_lists.c
// Created by Edoardo Debenedetti on 15/10/2017.
//

// INCLUDES
#include <stdio.h>
#include <stdlib.h>
#include "single_linked_lists.h"


// STRUCTS
typedef struct _LIST {
    list_type val; // data
    struct _LIST *next;
} LIST;

// FUNCTIONS
LIST *initList(void) { // initializes the list
    LIST *head = (LIST *) malloc(sizeof(LIST));
    if (!head) exit(EXIT_FAILURE);
    LIST *tail = (LIST *) malloc(sizeof(LIST));
    if (!tail) exit(EXIT_FAILURE);
    head->next = tail;
    tail->next = NULL;
    return head;
}

int countList(LIST *head) { // counts the element of the list
    LIST *ptr = head;
    int t;
    for (t = 0; ptr->next != NULL; ++t) {
        ptr = ptr->next;
    }
    return t - 1;
}

int emptyList(LIST *head) { // checks if the list is empty
    if (countList(head) == 0) {
        return 1;
    }
    return 0;
}

int insertElement(LIST *head, list_type val, int pos) { // insert the element with val 'val' int the pos-th position
    if (pos > countList(head) + 1) {
        fprintf(stderr, "ERROR: The index is bigger than the list's dimension + 1.\n");
        return 1;
    }
    LIST *ptr = head;
    for (int t = 0; t < pos - 1; ++t) ptr = ptr->next;
    LIST *new = (LIST *) malloc(sizeof(LIST));
    if (!new) exit(EXIT_FAILURE);
    new->val = val;
    new->next = ptr->next;
    ptr->next = new;
    printf("Element added successfully.\n");
    return 0;
}

int printList(LIST *head) { // prints the list
    if (emptyList(head)) {
        fprintf(stderr, "ERROR: the list is empty.\n");
        return 1;
    }
    LIST *ptr = head->next;
    printf("List:");
    while (ptr->next != NULL) {
        printf(" %d", ptr->val);
        ptr = ptr->next;
    }
    printf(".\n");
    return 0;
}

int removeElement(LIST *head, int pos) { // removes the pos-th element
    if (pos > countList(head)) {
        fprintf(stderr, "ERROR: The index is bigger than the list's dimension.\n");
        return 1;
    }
    LIST *ptr = head;
    for (int t = 0; t < pos - 1; ++t) ptr = ptr->next;
    LIST *toRemove = ptr->next;
    ptr->next = ptr->next->next;
    free(toRemove);
    printf("Element removed successfully.\n");
    return 0;
}

list_type getElement(LIST *head, int pos) { // returns the content of the pos-th element
    LIST *ptr = head;
    for (int t = 0; t < pos; ++t) ptr = ptr->next;
    return ptr->val;
}

LIST *clearList(LIST *head) { // clears the list
    while (!emptyList(head)) {
        LIST *ptr = head->next;
        head->next = ptr->next;
        free(ptr);
    }
    printf("List cleared successfully.\n");
    return head;
}

void destroyList(LIST *head) { // destroys the list
    clearList(head);
    free(head->next);
    free(head);
    printf("List destroyed successfully\n");
}