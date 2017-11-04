//
// unbounded_array_queue - unbounded_array_queue.h
// Created by Edoardo Debenedetti on 17/10/2017.
//
#ifndef UNBOUNDED_ARRAY_QUEUE_UNBOUNDED_ARRAY_QUEUE_H
#define UNBOUNDED_ARRAY_QUEUE_UNBOUNDED_ARRAY_QUEUE_H

// STRUCTS
typedef struct _QUEUE QUEUE;
typedef int queue_type; // defines the value type of the queue

// PROTOS
QUEUE *createQueue();

void printQueue(QUEUE *queue);

int enqueue(QUEUE *queue, queue_type val);

int dequeue(QUEUE *queue);

void freeQueue(QUEUE *queue);

#endif //UNBOUNDED_ARRAY_QUEUE_UNBOUNDED_ARRAY_QUEUE_H