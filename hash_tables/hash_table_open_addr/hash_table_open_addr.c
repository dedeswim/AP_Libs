//
// hash_table_open_addr_descriptor - hash_table_open_addr_descr.c
// Created by Edoardo Debenedetti on 30/10/2017.
// Copyright © 2017 Edoardo Debenedetti. All rights reserved.
//

// INCLUDES
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "hash_table_open_addr.h"

// STRUCTS
typedef struct _HASH_EL {
    key_type key; // key of the element
    value_type value; // value of the element
} HASH_EL;

typedef struct _HASH_TABLE_DESCR {
    int size; // size of the hash table
    int elements; // number of elements in the hash table
    HASH_EL **table; // the table
} HASH_TABLE_DESCR;

// FUNCTIONS
int hash(char *key, HASH_TABLE_DESCR *descriptor) { // hashes the element with key 'key'
    int sum = 0;
    for (int i = 0; key[i] != '\0'; ++i) {
        sum += key[i]; // sums all the key chars with the ASCII code
    }
    return sum % descriptor->size;
}

HASH_TABLE_DESCR *createHashTable(HASH_TABLE_DESCR *descriptor, int size) { // initializes the table
    descriptor = (HASH_TABLE_DESCR *) malloc(sizeof(HASH_TABLE_DESCR));
    descriptor->size = size;
    descriptor->table = (HASH_EL **) malloc(sizeof(HASH_EL) * descriptor->size);
    for (int i = 0; i < descriptor->size; ++i) {
        descriptor->table[i] = NULL; // initializes all the elements of the array to NULL
    }
    descriptor->elements = 0;
    return descriptor;
}

int insert(HASH_TABLE_DESCR *descriptor, key_type key, value_type val) { // inserts the element with key 'key and val 'val' in the table
    if (tableIsFull(descriptor)) {
        return 1;
    }
    HASH_EL *new = (HASH_EL *) malloc(sizeof(HASH_EL)); // element mem allocation
    new->key = (char *) malloc(sizeof(char) * (strlen(key) + 1)); // key mem allocation
    if (!new->key) exit(EXIT_FAILURE);
    strcpy(new->key, key); // save key in struct
    int hash_number = hash(new->key, descriptor); // hashes the element
    printf("The hash for \"%s\" is %d;\n", key, hash_number);
    new->value = val;
    while (descriptor->table[hash_number] && hash_number < descriptor->size) { // searches the first free place
        ++hash_number;
    }
    if (hash_number < descriptor->size) {
        descriptor->table[hash_number] = new;
    } else {
        hash_number = 0; // searches for free places from the beginning
        while (!descriptor->table[hash_number]) { // searches the first free place
            ++hash_number;
        }
    }
    ++descriptor->elements;
    return 0;
}

void printTable(HASH_TABLE_DESCR *descriptor) { // prints the table
    int size = descriptor->size;
    for (int i = 0; i < size; ++i) {
        if (descriptor->table[i] != NULL) { // goes in the list only if has been initialized
            printf("Key: %s, value %d;\n", descriptor->table[i]->key, descriptor->table[i]->value);
        }
    }
}

int tableIsFull(HASH_TABLE_DESCR *descriptor) { // checks if the table is full or not
    if (descriptor->elements >= descriptor->size) {
        printf("The table is full.\n");
        return 1;
    }
    return 0;
}

int search(key_type key, HASH_TABLE_DESCR *descriptor, value_type *result) { // searches the element with key 'key' in the hash table
    int hash_number = hash(key, descriptor); // hashes the key
    if (!descriptor->table[hash_number]) { // if the hash-th list has not been initialized, exits
        return 0; // not found
    }
    while (hash_number < descriptor->size) {
        if (strcmp(descriptor->table[hash_number]->key, key) == 0) { // searches through the list
            *result = descriptor->table[hash_number]->value; // assigns the result to the input
            return 1; // found
        }
        ++hash_number; // goes for another position
    }
    int prev_hash = hash(key, descriptor);
    while (hash_number < prev_hash) { // searches from 0 to the initial position
        if (strcmp(descriptor->table[hash_number]->key, key) == 0) { // searches through the list
            *result = descriptor->table[hash_number]->value; // assigns the result to the input
            return 1; // found
        }
        ++hash_number; // goes for another position
    }
    return 0; // not found
}

void freeHashTable(HASH_TABLE_DESCR *descriptor) { // frees the hash table memory
    for (int i = 0; i < descriptor->size; ++i) {
        free(descriptor->table[i]);
    }
    free(descriptor->table);
    free(descriptor);
}