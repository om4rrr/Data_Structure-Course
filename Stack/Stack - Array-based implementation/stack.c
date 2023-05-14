#include <stdio.h>
#include <stdbool.h>
#include "stack.h"


/* CreateStack: initialize the stack to be empty.
Pre : None.
Post: The stack has been initialized to be empty. */

void CreateStack(Stack *ps){
	
	ps->top=0;
}



/* Push: push an item onto the stack.
Pre : The stack exists and it is not full.
post: The argument item has been stored at the top of the stack. */

void Push(StackEntry item, Stack *ps){
	
	ps->items[ps->top++] = item;
}



/* StackFull: returns non-zero if the stack is full.
Pre : The stack exists and it has been initialized.
Post: Return non-zero if the stack is full; return zero, otherwise. */

bool StackFull(Stack *ps){
	
	return ps->top == MAX_SIZE;
}



/* Pop: pop an item from the stack.
Pre : The stack exists and it is not empty.
Post: The item at the top of stack has been removed and returned in *item. */

void Pop(StackEntry *item, Stack *ps){
	
	*item = ps->items[--ps->top];
}



/* StackEmpty: returns non-zero if the stack is empty.
Pre : The stack exists and it has been initialized.
Post: Return non-zero if the stack is empty; return zero, otherwise. */

bool StackEmpty(Stack *ps){
	
	return !ps->top;
}



/* StackSize: returns size of stack.
Pre : None.
Post: returns the number of entries in the stack. */

int StackSize(Stack *ps){
	
	return ps->top;
}




/* ClearStack: make stack is empty.
Pre : None.
Post: All entries in the stack have been deleted; the stack is empty. */

void ClearStack(Stack *ps){
	
	ps->top = 0;
}




/* StackTop: returns the item at the top of the stack.
Pre : The stack exists and it is not empty.
Post: The item at the top of the stack is returned (in *item) without
      being removed; the stack remains unchanged. */

void StackTop(StackEntry *item, Stack *ps){
	
	*item = ps->items[ps->top - 1];
}




/* TraverseStack: returns the item at the top of the stack.
Pre : None.
Post: The function that Visit points to, has been invoked for each entry
      in the stack, beginning with the entry at the top and proceeding
      toward the bottom of stack. */

void TraverseStack(Stack *ps, void (*pf)(StackEntry)){
	
	for(int i = ps->top - 1; i >= 0; --i)
		(*pf)(ps->items[i]);	
}
	







	
	