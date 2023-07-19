#ifndef LIST_H
#define LIST_H



typedef  int ListEntry;

typedef struct listnode
{
    ListEntry entry;
    struct listnode *next;

}ListNode;

typedef struct list{
    ListNode *Head;
    ListNode *Current;
    int CurrentPos;
    int size;
}List;

void CreateList(List *pl);


int Insert(int ind, ListEntry e, List *pl);

void Delete(int ind, ListEntry *pe, List *pl);

void Retrieve(int ind, ListEntry *pe, List *pl);

void Replace(int ind, ListEntry e, List *pl);

int ListSize(List *pl);

int ListEmpty(List *pl);

int ListFull(List *pl);

void ClearList(List *pl);

void TraverseList(List *pl, void(*Display)(ListEntry));

#endif
