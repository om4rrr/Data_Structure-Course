#ifndef QUEUE_H
#define QUEUE_H

#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#define MAX_QUEUE_SIZE 100

typedef int QueueEntry;


typedef struct queuenode{
    QueueEntry entry;
    struct queuenode *next;
}QueueNode;


typedef struct queue{
    QueueNode *front;
    QueueNode *back;
    int size;
}Queue;


void CreateQueue(Queue *);

int Push(QueueEntry , Queue *);

void Pop(QueueEntry *, Queue *);

QueueEntry Front(Queue *);

QueueEntry Back(Queue *);

bool QueueEmpty(Queue *);

bool QueueFull(Queue *);

int QueueSize(Queue *);

void ClearQueue(Queue *);

void TraverseQueue(Queue *, void (*)(QueueEntry));


#endif