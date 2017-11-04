//
// bounded_array_queue - bounded_array_queue.h
// Created by Edoardo Debenedetti on 16/10/2017.
//
#ifndef BOUNDED_ARRAY_QUEUE_BOUNDED_ARRAY_QUEUE_H
#define BOUNDED_ARRAY_QUEUE_BOUNDED_ARRAY_QUEUE_H

// STRUCTS
typedef int queue_type;
typedef struct _QUEUE QUEUE;

// PROTOS
QUEUE *createQueue(int size);

int printQueue(QUEUE *queue);

int enqueue(QUEUE *queue, queue_type val);

queue_type dequeue(QUEUE *queue);

#endif //BOUNDED_ARRAY_QUEUE_BOUNDED_ARRAY_QUEUE_H