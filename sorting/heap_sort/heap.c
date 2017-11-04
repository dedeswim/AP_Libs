//
// heap - heap.c
// Created by Edoardo Debenedetti on 28/10/2017.
//

// INCLUDES
#include "heap.h"

// INTERNAL FUNCTIONS PROTOS
int left(int father);

int right(int father);

void exchange(heap_type *a, heap_type *b);

void maxHeapify(heap_type *heap, int i, int size);

void buildMaxHeap(heap_type *heap);

// FUNCTION
void heapSort(heap_type *heap) {
    int size = HEAP_SIZE;
    buildMaxHeap(heap);
    for (int i = size - 1; i > 0; --i) {
        exchange(&heap[0], &heap[i]);
        --size;
        maxHeapify(heap, 0, size);
    }
}

// BASIC HEAP NAVIGATING FUNCTIONS
void buildMaxHeap(heap_type *heap) { // builds the max heap
    int size = HEAP_SIZE;
    for (int i = size / 2 + 1; i >= 0; --i) {
        maxHeapify(heap, i, size);
    }
}

void maxHeapify(heap_type *heap, int i, int size) { // creates the heap on the part of the tree
    int l = left(i);
    int r = right(i);
    int largest;
    if (l < size && heap[l] > heap[i]) {
        largest = l;
    } else {
        largest = i;
    }
    if (r < size && heap[r] > heap[largest]) {
        largest = r;
    }
    if (largest != i) {
        exchange(&heap[i], &heap[largest]);
        maxHeapify(heap, largest, size);
    }
}

int left(int father) { // returns the left child
    return 2 * father + 1;
}

int right(int father) { // returns the right child
    return 2 * father + 2;
}


// EXCHANGE FUNCTION
void exchange(heap_type *a, heap_type *b) { // exhanges the elements
    heap_type t = *a;
    *a = *b;
    *b = t;
}