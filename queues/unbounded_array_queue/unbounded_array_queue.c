//
// unbounded_array_queue - unbounded_array_queue.c
// Created by Edoardo Debenedetti on 17/10/2017.
//

// INCLUDES
#include <stdio.h>
#include <stdlib.h>
#include "unbounded_array_queue.h"

#define SIZE_UNIT 2

// STRUCTS
typedef struct _QUEUE {
    int maxSize; // max size of the queue
    int nElements; // elements in the queue
    int nSizeUnits; // number of 'SIZE_UNIT' slots
    int head; // index of the first element of the queue
    queue_type *queue; // queue
} QUEUE;

// PROTOS FOR INTERNAL USE FUNCTIONS
void queueRealloc(QUEUE *queue);

// FUNCTIONS
QUEUE *createQueue() { // initializes the queue
    QUEUE *queue = (QUEUE *) malloc(sizeof(QUEUE));
    if (!queue) exit(EXIT_FAILURE);
    queue->head = 0;
    queue->nElements = 0;
    queue->nSizeUnits = 1;
    queue->maxSize = queue->nSizeUnits * SIZE_UNIT;
    queue->queue = (queue_type *) malloc(sizeof(queue_type) * queue->maxSize);
    if (!queue->queue) exit(EXIT_FAILURE);
    return queue;
}

int enqueue(QUEUE *queue, queue_type val) { // enqueues the value 'val' in the last position of the queue
    if (queue->nElements == queue->maxSize) { // checks if the array is full
        queue->nSizeUnits++; // increases the slots
        queue->maxSize = queue->nSizeUnits * SIZE_UNIT; // increases the max size
        queue->queue = realloc(queue->queue, sizeof(queue_type) * queue->maxSize); // reallocs the memory
        if (!queue->queue) exit(EXIT_SUCCESS);
        queue->queue[queue->nElements++] = val; // enqueues the value 'val'
        return 0;
    }
    queue->queue[queue->nElements++] = val; // enqueues the value 'val'
    return 0;
}

int dequeue(QUEUE *queue) { // dequeues the element at the head of the queue
    if (queue->nElements == 0) { // checks if the queue is empty
        printf("The queue is empty.\n");
        return 1;
    }
    queue_type dequeued = queue->queue[queue->head++]; // takes the first element of the queue, shifting ahead the head
    --queue->nElements; // decreases the number of elements in the queue
    if (queue->maxSize - queue->nElements == 2 &&
        queue->maxSize != 2) { // checks if the first two pos of the array are free
        queueRealloc(queue); // reallocates the memory of the queue
    }
    return dequeued; // returns the dequeued value
}

void printQueue(QUEUE *queue) { // prints the queue
    if (queue->nElements == 0) { // checks if the queue is empty
        printf("The queue is empty.\n");
    } else {
        printf("QUEUE:");
        for (int i = queue->head; i < queue->nElements + queue->head; ++i) {
            printf(" %d", queue->queue[i]);
        }
        printf(";\n");
    }
}

void queueRealloc(QUEUE *queue) { // reallocates the memory of the queue
    --queue->nSizeUnits; // decreases the slots
    queue->maxSize = queue->nSizeUnits * SIZE_UNIT; // recomputes the maxSize
    queue_type *buffer = (queue_type *) malloc(
            sizeof(queue_type) * queue->maxSize); // creates a buffer where to copy all the elements
    if (!buffer) exit(EXIT_SUCCESS);
    for (int i = 0; i < queue->maxSize; ++i) { // copies the elements from the new head
        buffer[i] = queue->queue[i + queue->head];
    }
    free(queue->queue); // frees the memory of the old queue
    queue->queue = buffer;
    queue->head = 0;
}

void freeQueue(QUEUE *queue) {
    free(queue->queue);
    free(queue);
    printf("Memory freed successfully.\n");
}