#include "stack.h"


#ifdef LIMITED_MEMORY

//CreateStack: initialize the stack to be empty.


void CreateStack(Stack *ps){
	
	ps->top=0;
}


// Push: push an item onto the stack.


void Push(StackEntry item, Stack *ps){
	
	ps->items[ps->top++] = item;
}


// StackFull: returns non-zero if the stack is full.


bool StackFull(Stack *ps){
	
	return ps->top == MAX_SIZE;
}


// Pop: pop an item from the stack.


void Pop(StackEntry *item, Stack *ps){
	
	*item = ps->items[--ps->top];
}


// StackEmpty: returns non-zero if the stack is empty.


bool StackEmpty(Stack *ps){
	
	return !ps->top;
}


// StackSize: returns size of stack.


int StackSize(Stack *ps){
	
	return ps->top;
}


// ClearStack: make stack is empty.


void ClearStack(Stack *ps){
	
	ps->top = 0;
}


// StackTop: returns the item at the top of the stack.


void StackTop(StackEntry *item, Stack *ps){
	
	*item = ps->items[ps->top - 1];
}


// TraverseStack: returns the item at the top of the stack.


void TraverseStack(Stack *ps, void (*pf)(StackEntry)){
	
	for(int i = ps->top - 1; i >= 0; --i)
		(*pf)(ps->items[i]);	
}


#else

//CreateStack: initialize the stack to be empty.


void CreateStack(Stack *ps){  // O(1)
	
	ps->top = NULL;
	ps->size = 0;
	
}


// Push: push an item onto the stack.


void push(StackEntry e, Stack *ps){   // O(1)
	
	StackNode *pn = (StackNode *)malloc(sizeof(StackNode));
	pn->entry = e;
	pn->next  = ps->top;
	ps->top   = pn;
	ps->size++;
}


// Pop: pop an item from the stack.


void pop(StackEntry *pe, Stack *ps){   // O(1)
	StackNode *pn;
	*pe = ps->top->entry;
	pn = ps->top;
	ps->top = ps->top->next;
	free(pn);
	ps->size--;
}
	
	
// StackEmpty: returns non-zero if the stack is empty.


bool StackEmpty(Stack *ps){   // O(1)
	
	return !ps->top;
}


// StackFull: returns non-zero if the stack is full.


bool StackFull(Stack *ps){    // O(1)
	
	return 0;
}
	
	
// ClearStack: make stack is empty.


void ClearStack(Stack *ps){  // o(n)
	
	StackNode *pn = ps->top;
	while(pn){
		pn = pn->next;
		free(ps->top);
		ps->top = pn;
	}
	ps->size = 0;	
}


// TraverseStack: returns the item at the top of the stack.


void TraverseStack(Stack *ps, void (*pf)(StackEntry)){
	
	for(StackNode *pn = ps->top ; pn; pn = pn->next)
		(*pf)(pn->entry);	
}


// StackSize: returns size of stack.


int StackSize(Stack *ps){  // O(1)
	
	return ps->size;
}


// StackTop: returns the item at the top of the stack.


StackEntry StackTop( Stack *ps){
	
	return ps->top->entry;
}

#endif