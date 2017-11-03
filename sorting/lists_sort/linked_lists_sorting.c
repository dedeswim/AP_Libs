//
// lists_sort - linked_lists_sorting.c
// Created by Edoardo Debenedetti on 01/11/2017.
//

// INCLUDES
#include <stdio.h>
#include <stdlib.h>
#include "linked_lists_sorting.h"

// STRUCTS

// PROTOS FOR INTERNAL USE FUNCTIONS
int countList(LIST *head);

// NECESSARY FUNCTIONS
LIST **arrayList(LIST *head) { // gets an array from the list
    int size = countList(head);
    LIST *ptr = head->next;
    LIST **array = (LIST **) malloc(size * sizeof(LIST *));
    for (int i = 0; ptr; ++i) {
        array[i] = ptr;
        ptr = ptr->next;
    }
    return array;
}

LIST *rebuildList(LIST **array, LIST *head) { // rebuilds the list from the ordered array and frees it
    LIST *tail = head;
    while (tail->next) { // gets the tail of the list
        tail = tail->next;
    }
    int size = countList(head);
    LIST *ptr = head;
    for (int i = 0; i < size; ++i) {
        ptr->next = array[i];
        ptr = ptr->next;
    }
    ptr->next = tail; // puts the tail at the end of the list
    free(array); // frees the array
}

int countList(LIST *head) { // counts the elements in the list
    LIST *ptr = head->next;
    int t;
    for (t = 0; ptr->next != NULL; ++t) {
        ptr = ptr->next;
    }
    return t;
}

// FUNCTIONS USED TO TEST
void addElement(LIST *head, int val) { // adds an element to the list
    LIST *new = (LIST *) malloc(sizeof(LIST));
    new->val = val;
    new->next = head->next;
    head->next = new;
}

void printList(LIST *head) { // prints the list
    int size = countList(head);
    LIST *ptr = head->next;
    printf("list:\t");
    for (int i = 0; i < size; ++i) {
        printf(" %d", ptr->val);
        ptr = ptr->next;
    }
    printf(".\n");
}

LIST *initList(void) { // initializes the linked list
    LIST *head = (LIST *) malloc(sizeof(LIST));
    LIST *tail = (LIST *) malloc(sizeof(LIST));
    head->next = tail;
    tail->next = NULL;
    return head;
}