//
// list_queue - list_queue.h
// Created by Edoardo Debenedetti on 19/10/2017.
//
#ifndef LIST_QUEUE_LIST_QUEUE_H
#define LIST_QUEUE_LIST_QUEUE_H

// STRUCTS
typedef int queue_type;
typedef struct _QUEUE QUEUE;

// PROTOS
QUEUE *initQueue();

int emptyQueue(QUEUE *queue);

void enqueue(QUEUE *queue, queue_type val);

queue_type dequeue(QUEUE *queue, queue_type *val);

queue_type peekQueue(QUEUE *queue, queue_type *val);

int printQueue(QUEUE *queue);

int clearQueue(QUEUE *queue);

void freeQueue(QUEUE *queue);

#endif //LIST_QUEUE_LIST_QUEUE_H
