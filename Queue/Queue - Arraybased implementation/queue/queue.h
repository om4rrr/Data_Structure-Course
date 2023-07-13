#ifndef QUEUE_H
#define QUEUE_H

#include <stdio.h>
#include <stdbool.h>
#define MAX_QUEUE_SIZE 100

typedef int QueueEntry;

typedef struct queue{
    int front;
    int back;
    int size;
    QueueEntry entry[MAX_QUEUE_SIZE];
}Queue;


void CreateQueue(Queue *);

void Push(QueueEntry , Queue *);

void Pop(QueueEntry *, Queue *);

QueueEntry Front(Queue *);

QueueEntry Back(Queue *);

bool QueueEmpty(Queue *);

bool QueueFull(Queue *);

int QueueSize(Queue *);

void ClearQueue(Queue *);

void TraverseQueue(Queue *, void (*)(QueueEntry));


#endif
