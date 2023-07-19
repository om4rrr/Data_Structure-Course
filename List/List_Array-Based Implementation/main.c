#include <stdio.h>
#include "list/list.h"
void Display(ListEntry e)
{
    printf("%d ", e);
}

int main() {

    List l;
    ClearList(&l);
    ListEntry e;

    // To Use it like Stack

    printf("\nUsing List like Stack : \n");
    for(int i = 0; i < 20; ++i)
    {
        if(!ListFull(&l))
        {
            Insert(0,i+1,&l);
        }
    }
    TraverseList(&l, &Display);
    for(int i = 0; i < 20; ++i)
    {
        if(!ListEmpty(&l))
        {
            Delete(0,&e,&l);
        }
    }


    // To Use it like Queue

    printf("\nUsing List like Stack : \n");

    for(int i = 0; i < 20; ++i)
    {
        if(!ListFull(&l))
        {
            Insert(ListSize(&l),i+1,&l);
        }
    }
    TraverseList(&l, &Display);
    for(int i = 0; i < 20; ++i)
    {
        if(!ListFull(&l))
        {
            Delete(0,&e,&l);
        }
    }

    return 0;
}
