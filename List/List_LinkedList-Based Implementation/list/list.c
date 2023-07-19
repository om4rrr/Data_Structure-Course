#include "list.h"
#include <stdlib.h>

void CreateList(List *pl)
{
    pl->Head = NULL;
    pl->Current = NULL;
    pl->CurrentPos = 0;
    pl->size = 0;

}
int Insert(int ind, ListEntry e, List *pl)
{
    ListNode *p = (ListNode *) malloc(sizeof (ListNode));
    if(p)
    {
        p->entry = e;
        if(ind == 0)
        {
            p->next = pl->Head;
            pl->Head = p;
            pl->Current = p;
            pl->CurrentPos = 0;
        }
        else
        {
            if(ind <= pl->CurrentPos)
            {
                pl->CurrentPos = 0;
                pl->Current = pl->Head;
            }

            for( ; pl->CurrentPos < ind - 1 ; ++pl->CurrentPos)
            {
                pl->Current = pl->Current->next;
            }
            p->next = pl->Current->next;
            pl->Current->next = p;
        }
        pl->size++;
        return 1;
    }
    else return 0;

}

void Delete(int ind, ListEntry *pe, List *pl)
{
    ListNode *temp ;
    if(ind == 0)
    {
        *pe = pl->Head->entry;
        pl->Current = pl->Head->next;
        free(pl->Head);
        pl->Head = pl->Current;
        pl->CurrentPos = 0;
    }
    else
    {
        if(ind <= pl->CurrentPos)
        {
            pl->CurrentPos = 0;
            pl->Current = pl->Head;
        }

        for( ; pl->CurrentPos < ind - 1 ; ++pl->CurrentPos)
        {
            pl->Current = pl->Current->next;
        }
        temp= pl->Current->next->next;
        *pe = pl->Current->next->entry;
        free(pl->Current->next);
        pl->Current->next = temp;
    }
    pl->size--;

}

void Retrieve(int ind, ListEntry *pe, List *pl)
{
    if(ind <= pl->CurrentPos)
    {
        pl->CurrentPos = 0;
        pl->Current = pl->Head;
    }

    for( ; pl->CurrentPos < ind ; ++pl->CurrentPos)
    {
        pl->Current = pl->Current->next;
    }
    *pe = pl->Current->entry;
}

void Replace(int ind, ListEntry e, List *pl)
{
    if(ind <= pl->CurrentPos)
    {
        pl->CurrentPos = 0;
        pl->Current = pl->Head;
    }

    for( ; pl->CurrentPos < ind ; ++pl->CurrentPos)
    {
        pl->Current = pl->Current->next;
    }
    pl->Current->entry = e;

}

int ListSize(List *pl)
{
    return pl->size;
}

int ListEmpty(List *pl)
{
    return !pl->size;

}

int ListFull(List *pl)
{
    return 0;
}

void ClearList(List *pl);

void TraverseList(List *pl, void(*Display)(ListEntry))
{
    ListNode *p = pl->Head;
    while(p)
    {
        (*Display)(p->entry);
        p = p->next;
    }
}