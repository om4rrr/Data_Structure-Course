#ifndef LIST_H
#define LIST_H

#define MAX_SIZE 100

typedef  int ListEntry;

typedef struct list{
    ListEntry entry[MAX_SIZE];
    int size;
}List;


void Insert(int ind, ListEntry e, List *pl);

void Delete(int ind, ListEntry *pe, List *pl);

void Retrieve(int ind, ListEntry *pe, List *pl);

void Replace(int ind, ListEntry e, List *pl);

int ListSize(List *pl);

int ListEmpty(List *pl);

int ListFull(List *pl);

void ClearList(List *pl);

void TraverseList(List *pl, void(*Display)(ListEntry));

#endif
