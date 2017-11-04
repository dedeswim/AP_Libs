//
// list_queue - list_queue.c
// Created by Edoardo Debenedetti on 19/10/2017.
//

// INCLUDES
#include <stdio.h>
#include <stdlib.h>
#include "list_queue.h"

// STRUCTS
typedef struct _NODE {
    queue_type val; // value in the queue
    struct _NODE *next;
} NODE;

typedef struct _QUEUE {
    NODE *head; // address of the head of the queue
    NODE *tail; // address of the tail of the queue
} QUEUE;

// FUNCTIONS
QUEUE *initQueue() { // initializes the queue
    QUEUE *queue = (QUEUE *) malloc(sizeof(QUEUE));
    if (!queue) exit(EXIT_FAILURE);
    queue->head = queue->tail = NULL;
    return queue;
}

int emptyQueue(QUEUE *queue) { // checks if the queue is empty
    if (queue->head == NULL) {
        return 1;
    }
    return 0;
}

void enqueue(QUEUE *queue, queue_type val) { // enqueues the val 'val' in the last position of the queue
    NODE *new = (NODE *) malloc(sizeof(NODE));
    if (!new) exit(EXIT_FAILURE);
    new->val = val;
    new->next = NULL;
    if (queue->tail == NULL) {
        queue->head = queue->tail = new;
    } else {
        queue->tail->next = new;
        queue->tail = queue->tail->next;
    }
}

queue_type dequeue(QUEUE *queue, queue_type *val) { // dequeues the first element of the queue
    // call with dequeue(queue, &val), where 'val' is the variable where you want to write the dequeued element
    if (queue->head == NULL) {
        printf("Empty queue\n");
        return 0;
    }
    *val = queue->head->val;
    NODE *p = queue->head;
    queue->head = p->next;
    if (queue->head == NULL) {
        queue->tail = NULL;
    }
    free(p);
    return 1;
}

queue_type peekQueue(QUEUE *queue, queue_type *val) { // returns the first element of the queue
    // call with peekQueue(queue, &val), where 'val' is the variable where you want to write the dequeued element
    if (queue->head == NULL) {
        printf("The queue is empty.\n");
        return 0;
    }
    *val = queue->head->val;
    return 1;
}

int clearQueue(QUEUE *queue) { // clears the queue bringing it at the initial state
    if (emptyQueue(queue)) { // checks if the queue is empty, so doesn't need to be cleared
        return 0;
    }
    NODE *p = queue->head;
    while (!p) { // frees all the pointers
        queue->head = queue->head->next;
        free(p);
        p = queue->head;
    }
    queue->head = queue->tail = NULL;
    return 0;
}

int printQueue(QUEUE *queue) { // prints the queue
    if (emptyQueue(queue)) { // checks if the queue is empty
        printf("The queue is empty.\n");
        return 0;
    }
    NODE *ptr = queue->head;
    printf("Queue:");
    while (ptr != NULL) {
        printf(" %d", ptr->val);
        ptr = ptr->next;
    }
    printf(";\n");
    return 1;
}

void freeQueue(QUEUE *queue) { // frees the queue's memory
    clearQueue(queue);
    free(queue->head);
    free(queue->tail);
    free(queue);
    printf("Queue freed successfully.\n");
}
