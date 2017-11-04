//
// double_circle_linked_lists - double_circle_linked_lists.c
// Created by Edoardo Debenedetti on 15/10/2017.
//

// INCLUDES
#include <stdio.h>
#include <stdlib.h>
#include "double_circle_linked_lists.h"

// STRUCTS
typedef struct _LIST {
    list_type val; // data
    struct _LIST *next;
    struct _LIST *prior;
} LIST;

// FUNCTIONS
LIST *initList(void) { // initializes the list
    LIST *head = (LIST *) malloc(sizeof(LIST));
    if (!head) exit(EXIT_FAILURE);
    head->next = head;
    head->prior = head;
    return head;
}

int countList(LIST *head) { // counts the elements in the list
    LIST *ptr = head;
    int t;
    for (t = 0; ptr->next != head; ++t) {
        ptr = ptr->next;
    }
    return t;
}

int emptyList(LIST *head) { // checks if the list is empty
    if (countList(head) == 0) {
        return 1;
    }
    return 0;
}

int insertElement(LIST *head, list_type val, int pos) { // inserts the val 'val' in the pos-th position
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
    ptr->next->prior = new;
    ptr->next = new;
    new->prior = ptr;
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
    while (ptr != head) {
        printf(" %d", ptr->val);
        ptr = ptr->next;
    }
    printf(".\n");
    return 0;
}

int removeElement(LIST *head, int pos) { // removes the element in the pos-th position
    if (pos > countList(head)) {
        fprintf(stderr, "ERROR: The index is bigger than the list's dimension.\n");
        return 1;
    }
    LIST *ptr = head;
    for (int t = 0; t < pos - 1; ++t) ptr = ptr->next;
    LIST *toRemove = ptr->next;
    ptr->next->next->prior = ptr;
    ptr->next = ptr->next->next;
    free(toRemove);
    printf("Element removed successfully.\n");
    return 0;
}

list_type getElement(LIST *head, int pos) { // returns the 'val' in the pos-th position
    LIST *ptr = head;
    for (int t = 0; t < pos; ++t) ptr = ptr->next;
    return ptr->val;
}

LIST *clearList(LIST *head) { // clears the list
    while (!emptyList(head)) {
        LIST *ptr = head->next;
        ptr->next->prior = head;
        head->next = ptr->next;
        free(ptr);
    }
    printf("List cleared successfully.\n");
    return head;
}

void destroyList(LIST *head) { // destroys the list
    clearList(head);
    free(head);
    printf("List destroyed successfully\n");
}