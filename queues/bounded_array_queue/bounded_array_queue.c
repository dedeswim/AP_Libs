//
// bounded_array_queue - bounded_array_queue.c
// Created by Edoardo Debenedetti on 16/10/2017.
//

// INCLUDES
#include <stdio.h>
#include <stdlib.h>
#include "bounded_array_queue.h"

// STRUCTS
typedef struct _QUEUE {
    int maxSize; // max size of the queue
    int head; // position of the head
    int tail; // position of the tail
    int nElements; // number of elements in the queue
    queue_type *start; // queue
} QUEUE;

// FUNCTIONS
QUEUE *createQueue(int size) { // initializes the queue
    QUEUE *queue = (QUEUE *) malloc(sizeof(QUEUE));
    if (!queue) exit(EXIT_FAILURE);
    queue->maxSize = size;
    queue->head = queue->tail = 0;
    queue->nElements = 0;
    queue->start = (queue_type *) malloc((queue->maxSize + 1) * sizeof(queue_type));
    if (!queue->start) exit(EXIT_FAILURE);
    for (int t = 0; t < queue->maxSize + 1; ++t) {
        queue->start[t] = 0;
    }
    return queue;
}

int printQueue(QUEUE *queue) { // prints the queue (managed in a circular way)
    if (queue->nElements == 0) {
        printf("The queue is empty.\n");
        return 0;
    }
    printf("Queue:");
    int count = queue->head;
    for (int t = 0; t < queue->nElements; t++) {
        printf(" %d", queue->start[count]);
        count = (count) % queue->maxSize;
        ++count;
    }
    printf("\n");
}

int enqueue(QUEUE *queue, queue_type val) { // enqueues the value 'val' in position 'tail' of the queue
    // (managed in a circular way)
    if (queue->nElements >= queue->maxSize) { // checks if the queue is full
        printf("The queue is full.\n");
        return -1;
    }
    queue->start[queue->tail] = val;
    queue->tail = queue->tail % queue->maxSize + 1;
    ++queue->nElements;
    return 0;
}

queue_type dequeue(QUEUE *queue) { // dequeues the element in position 'head' of the queue
    if (queue->nElements == 0) { // checks if the queue is empty
        printf("The queue is empty\n");
        return -1;
    }
    queue->head = queue->head % queue->maxSize;
    --queue->nElements;
    return queue->start[queue->head++];
}