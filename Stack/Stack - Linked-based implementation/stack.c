#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "stack.h"


/* CreateStack: initialize the stack to be empty.
Pre : None.
Post: The stack has been initialized to be empty. */

void CreateStack(Stack *ps){  // O(1)
	
	ps->top = NULL;
	ps->size = 0;
	
}


/* Push: push an item onto the stack.
Pre : The stack exists and it is initialized.
post: The argument item has been stored at the top of the stack. */

void push(StackEntry e, Stack *ps){   // O(1)
	
	StackNode pn = (StackNode *)malloc(sizeof(StackNode));
	pn->entry = e;
	pn->next  = ps->top;
	ps->top   = pn;
	ps->size++;
}


/* Pop: pop an item from the stack.
Pre : The stack exists and it is not empty.
Post: The item at the top of stack has been removed and returned in *pe. */

void pop(StackEntry *pe, Stack *ps){   // O(1)
	StackNode *pn;
	*pe = ps->top->entry;
	pn = ps->top;
	ps->top = ps->top->next;
	free(pn);
	ps->size--;
}
	
	
	/* StackEmpty: returns non-zero if the stack is empty.
Pre : The stack exists and it has been initialized.
Post: Return non-zero if the stack is empty; return zero, otherwise. */

bool StackEmpty(Stack *ps){   // O(1)
	
	return !ps->top;
}


/* StackFull: returns non-zero if the stack is full.
Pre : The stack exists and it has been initialized.
Post: Return non-zero if the stack is full; return zero, otherwise. */

bool StackFull(Stack *ps){    // O(1)
	
	return 0;
}
	
	
/* ClearStack: make stack is empty.
Pre : Stack is exist.
Post: All entries in the stack have been deleted; the stack is empty. */

void ClearStack(Stack *ps){  // o(n)
	
	StackNode *pn = ps->top;
	while(pn){
		pn = pn->next;
		free(ps->top);
		ps->top = pn;
	}
	ps->size = 0;	
}


/* TraverseStack: returns the item at the top of the stack.
Pre : None.
Post: The function that Visit points to, has been invoked for each entry
      in the stack, beginning with the entry at the top and proceeding
      toward the bottom of stack. */

void TraverseStack(Stack *ps, void (*pf)(StackEntry)){
	
	for(StackNode *pn = ps->top ; pn; pn = pn->next)
		(*pf)(pn->entry);	
}


/* StackSize: returns size of stack.
Pre : None.
Post: returns the number of entries in the stack. */

int StackSize(Stack *ps){  // O(1)
	
	return ps->size;
}


/* StackTop: returns the item at the top of the stack.
Pre : The stack exists and it is not empty.
Post: The item at the top of the stack is returned (in *item) without
      being removed; the stack remains unchanged. */

StackEntry StackTop( Stack *ps){
	
	return ps->top->entry;
}