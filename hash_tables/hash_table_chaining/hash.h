//
// hash - hash.h
// Created by Edoardo Debenedetti on 26/10/2017.
//
#ifndef HASH_HASH_H
#define HASH_HASH_H

// MACROS
#define TABLE_SIZE 71

// STRUCTS
typedef struct _HASH_TABLE_DESCR HASH_TABLE_DESCR;
typedef char *key_type;
typedef int value_type;

// PROTOS
HASH_TABLE_DESCR *createHashTable(HASH_TABLE_DESCR *descriptor, int size);

void printTable(HASH_TABLE_DESCR *descriptor);

int insert(HASH_TABLE_DESCR *descriptor, key_type key, value_type val);

value_type search(key_type key, HASH_TABLE_DESCR *descriptor, value_type *result);

int delete(key_type key, HASH_TABLE_DESCR *descriptor);

void freeHashTable(HASH_TABLE_DESCR *descriptor);

#endif //HASH_HASH_H