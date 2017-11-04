//
// hash_table_open_addr_descriptor - hash_table_open_addr_descr.h
// Created by Edoardo Debenedetti on 30/10/2017.
//
#ifndef HASH_TABLE_OPEN_ADDR_DESCRIPTOR_HASH_TABLE_OPEN_ADDRH
#define HASH_TABLE_OPEN_ADDR_DESCRIPTOR_HASH_TABLE_OPEN_ADDR_H


#define TABLE_SIZE 71

// STRUCTS
typedef struct _HASH_TABLE_DESCR HASH_TABLE_DESCR;
typedef char *key_type;
typedef int value_type;

// PROTOS
HASH_TABLE_DESCR *createHashTable(HASH_TABLE_DESCR *descriptor, int size);

int insert(HASH_TABLE_DESCR *descriptor, key_type key, value_type val);

void printTable(HASH_TABLE_DESCR *descriptor);

int tableIsFull(HASH_TABLE_DESCR *descriptor);

int search(key_type key, HASH_TABLE_DESCR *descriptor, value_type *result);

void freeHashTable(HASH_TABLE_DESCR *descriptor);

#endif //HASH_TABLE_OPEN_ADDR_DESCRIPTOR_HASH_TABLE_OPEN_ADDR_H