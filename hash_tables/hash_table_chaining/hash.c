//
// hash - hash.c
// Created by Edoardo Debenedetti on 26/10/2017.
//

// INCLUDES
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "hash.h"

// STRUCTS
typedef struct _HASH_EL {
    key_type key; // key of the element
    value_type value; // value of the element
    struct _HASH_EL *next;
} HASH_EL;

typedef struct _HASH_TABLE_DESCR {
    int size; // size of the table
    int elements; // number of elements in the table
    HASH_EL **table; // table
} HASH_TABLE_DESCR;

// PROTOS FOR INTERNAL FUNCTIONS
HASH_EL *createChaining(HASH_EL *head);

int hash(char *key, HASH_TABLE_DESCR *descriptor);

void destroyChaining(HASH_EL *head);
// FUNCTIONS
int hash(char *key, HASH_TABLE_DESCR *descriptor) { // creates an hash for the 'key'
    int sum = 0;
    for (int i = 0; key[i] != '\0'; ++i) {
        sum += key[i]; // sums all the key chars with the ASCII code
    }
    return sum % descriptor->size;
}

HASH_TABLE_DESCR *createHashTable(HASH_TABLE_DESCR *descriptor, int size) { // initializes the hash table
    descriptor = (HASH_TABLE_DESCR *) malloc(sizeof(HASH_TABLE_DESCR));
    descriptor->size = size;
    descriptor->table = (HASH_EL **) malloc(sizeof(HASH_EL) * size);
    for (int i = 0; i < descriptor->size; ++i) {
        descriptor->table[i] = NULL; // initializes all the elements of the array to NULL
    }
    descriptor->elements = 0;
    return descriptor;
}

void printTable(HASH_TABLE_DESCR *descriptor) { // prints the table
    for (int i = 0; i < descriptor->size; ++i) {
        if (descriptor->table[i] != NULL) { // goes in the list only if has been initialized
            HASH_EL *ptr = descriptor->table[i]->next; // creates the pointer used to go through the list
            while (ptr->next) {
                printf("Key: %s, value %d;\n", ptr->key, ptr->value);
                ptr = ptr->next;
            }
        }
    }
}

int insert(HASH_TABLE_DESCR *descriptor, key_type key, value_type val) { // inserts the element with key 'key' and value 'val
    HASH_EL *new = (HASH_EL *) malloc(sizeof(HASH_EL)); // element mem allocation
    new->key = (char *) malloc(sizeof(char) * (strlen(key) + 1)); // key mem allocation
    if (!new->key) exit(EXIT_FAILURE);
    strcpy(new->key, key); // save key in struct
    int hash_number = hash(new->key, descriptor); // hashes the element
    printf("The hash for \"%s\" is %d;\n", key, hash_number);
    new->value = val;
    if (descriptor->table[hash_number] == NULL) { // if the list hasn't been initialized, initializes it
        descriptor->table[hash_number] = createChaining(descriptor->table[hash_number]);
    }
    // inserts the element in the linked list
    new->next = descriptor->table[hash_number]->next;
    descriptor->table[hash_number]->next = new;
    ++descriptor->elements;
    return 0;
}

value_type search(key_type key, HASH_TABLE_DESCR *descriptor, value_type *result) { // searches the element in the hash table
    int hash_number = hash(key, descriptor); // hashes the key
    if (!descriptor->table[hash_number]) { // if the hash-th list has not been initialized, exits
        return 0; // not found
    }
    HASH_EL *ptr = descriptor->table[hash_number]->next; // pointer to go through the list
    while (ptr->next) {
        if (strcmp(ptr->key, key) == 0) { // searches through the list
            *result = ptr->value;
            return 1; // found
        }
        ptr = ptr->next;
    }
    return 0; // not found
}

int delete(key_type key, HASH_TABLE_DESCR *descriptor) { // deletes an element in the table
    int hash_number = hash(key, descriptor); // hashes the key
    if (!descriptor->table[hash_number]) { // if the hash-th list has not been initialized, exits
        return 0;
    }
    HASH_EL *ptr = descriptor->table[hash_number]->next; // pointer to go through the list
    int flag = 0; // flag, if 0 not found, if 1 found
    while (!flag && ptr->next) {
        if (strcmp(ptr->next->key, key) == 0) { // searches through the list
            flag = 1; // exits when finds the element
        } else {
            ptr = ptr->next;
        }
    }
    if (flag == 1) {
        HASH_EL *toBeFreed = ptr->next;
        ptr->next = toBeFreed->next;
        free(toBeFreed);
        --descriptor->elements;
        return 1;
    }
    return 0;
}

void freeHashTable(HASH_TABLE_DESCR *descriptor) { // frees the hash table
    for (int i = 0; i < descriptor->size; ++i) {
        if (descriptor->table[i]) {
            destroyChaining(descriptor->table[i]);
        }
    }
    free(descriptor->table);
    free(descriptor);
}

// LIST MANAGEMENT FUNCTIONS
HASH_EL *createChaining(HASH_EL *head) { // initializes the linked list when required for the chaining
    head = (HASH_EL *) malloc(sizeof(HASH_EL));
    if (!head) exit(EXIT_FAILURE);
    HASH_EL *tail = (HASH_EL *) malloc(sizeof(HASH_EL));
    if (!tail) exit(EXIT_FAILURE);
    tail->next = NULL;
    head->next = tail;
    return head;
}

void destroyChaining(HASH_EL *head) { // destroys the list necessary for the chaining
    while (head->next) {
        HASH_EL *ptr = head->next;
        head->next = ptr->next;
        free(ptr);
    }
    free(head->next);
    free(head);
}