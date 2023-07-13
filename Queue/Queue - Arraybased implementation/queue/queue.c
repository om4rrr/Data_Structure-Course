#include "queue.h"


// create the queue


void CreateQueue(Queue *pq){
    pq->front =  0;
    pq->back  = -1;
    pq->size  =  0;
}


// function to append an element to the rear


void Push(QueueEntry e, Queue *pq){
    pq->back = ( pq->back + 1 ) % MAX_QUEUE_SIZE;
    pq->entry[pq->back] = e;
    pq->size++;
}


// function to serve the front element


void Pop(QueueEntry *pe, Queue *pq){
    *pe = pq->entry[pq->front];
    pq->front = ( pq->front + 1 ) % MAX_QUEUE_SIZE;
    pq->size--;
}


// function to return the front element


QueueEntry Front(Queue *pq){
    return pq->entry[pq->front];
}


// function to return the rear element


QueueEntry Back(Queue *pq){
    return pq->entry[pq->back];
}


// function to tell if the queue is empty


bool QueueEmpty(Queue *pq){
    return !pq->size;
}


// function to tell if the queue is full


bool QueueFull(Queue *pq){
    return pq->size == MAX_QUEUE_SIZE;
}


// function to tell if the queue size


int QueueSize(Queue *pq){
    return pq->size;
}


// function to clear  the queue


void ClearQueue(Queue *pq){
    pq->front =  0;
    pq->back  = -1;
    pq->size  =  0;
}


// function to traverse  the queue


void TraverseQueue(Queue *pq, void (*pf)(QueueEntry)){

    for (int pos = pq->front, i = 0; i < pq->size; ++i){
        (*pf)(pq->entry[pos]);
        pos = (pos+1) % MAX_QUEUE_SIZE;
    }

}

