//
// heap - heap.h
// Created by Edoardo Debenedetti on 28/10/2017.
//
#ifndef HEAP_HEAP_H
#define HEAP_HEAP_H

#include "linked_lists_sorting.h"
// STRUCTS
typedef LIST *heap_type;

// PROTOS
void heapSort(heap_type *heap, int size);

#endif //HEAP_HEAP_H