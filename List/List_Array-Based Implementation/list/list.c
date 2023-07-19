#include "list.h"


void CreateList(List *pl)
{
    pl->size = 0;
}

/*
-Precondition:
    1- The list pl has been created.
    2- not full
    3- 0 <= ind >= size.
-Postcondition:
    1- e has been inserted at position ind
    2- all elements at old positions ind, ind+1, …, size-1 are incremented by 1.
    3- size increases by 1.
 */

void Insert(int ind, ListEntry e, List *pl)
{
    for(int i = pl->size - 1; i >= ind; --i)
    {
        pl->entry[i+1] = pl->entry[i];
    }
    pl->entry[ind] = e;
    pl->size++;
}


/*
-Precondition:
    1- The list pl has been created,
    2- not empty,
    3- 0 <= p >= size-1.
-Postcondition:
    1- e has been retrieved from position p,
    2- all elements at old positions ind+1, …, size-1 are decremented by 1.
    3- size decreases by 1.
 */

void Delete(int ind, ListEntry *pe, List *pl)
{
    *pe = pl->entry[ind];
    for (int i = ind; i < pl->size - 1; ++i)
    {
        pl->entry[i] = pl->entry[i + 1];
    }
    pl->size--;
}


// 0<= ind <= size-1

void Retrieve(int ind, ListEntry *pe, List *pl)
{
    *pe = pl->entry[ind];
}
// 0<= ind <= size-1

void Replace(int ind, ListEntry e, List *pl)
{
    pl->entry[ind] = e;
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
    return pl->size == MAX_SIZE;
}

void ClearList(List *pl)
{
    pl->size = 0;
}

void TraverseList(List *pl, void(*Display)(ListEntry))
{
    for(int i = 0; i < pl->size; ++i)
    {
        (*Display)(pl->entry[i]);
    }
}