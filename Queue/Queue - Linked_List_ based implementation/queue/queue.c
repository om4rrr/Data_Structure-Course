#include "queue.h"


// create the queue


void CreateQueue(Queue *pq){
    pq->front = NULL;
    pq->back  = NULL;
    pq->size  = 0;
}


// function to append an element to the rear


int Push(QueueEntry e, Queue *pq){
    QueueNode *pn = (QueueNode *)malloc(sizeof(QueueNode));
    if(!pn) return 0;
    pn->next = NULL;
    pn->entry = e;
    if(!pq->front) pq->front = pn;
    else pq->back->next = pn;
    pq->back = pn;
    pq->size++;
    return 1;
}


// function to serve the front element


void Pop(QueueEntry *pe, Queue *pq){
    QueueNode *pn = pq->front;
    *pe = pq->front->entry;
    pq->front = pq->front->next;
    free(pn);
    if(!pq->front) pq->back = NULL;
    pq->size--;
}


// function to return the front element


QueueEntry Front(Queue *pq){
    return pq->front->entry;
}


// function to return the rear element


QueueEntry Back(Queue *pq){
    return pq->back->entry;
}


// function to tell if the queue is empty


bool QueueEmpty(Queue *pq){
    return !pq->size;
}


// function to tell if the queue is full


bool QueueFull(Queue *pq){
    return 0;
}


// function to tell if the queue size


int QueueSize(Queue *pq){
    return pq->size;
}


// function to clear  the queue


void ClearQueue(Queue *pq){
    while (pq->front){
        pq->back = pq->front->next;
        free(pq->front);
        pq->front = pq->back;
    }
    pq->size = 0;
}


// function to traverse  the queue


void TraverseQueue(Queue *pq, void (*pf)(QueueEntry)){

    for (QueueNode *pn = pq->front; pn; pn = pn->next)
        (*pf)(pn->entry);

}
