#include <stdio.h>


typedef int StackEntry;


typedef struct stacknode{
	StackEntry entry;
    struct stacknode *next;
}StackNode;


typedef struct stack{
	StackNode *top;
	int size;
}Stack;


void CreateStack(Stack*);

void push(StackEntry, Stack *);

void pop(StackEntry *, Stack *);

bool StackEmpty(Stack *);

bool StackFull(Stack *);

void ClearStack(Stack *);

void TraverseStack(Stack *, void (*)(StackEntry));

int StackSize(Stack *);

StackEntry StackTop( Stack *);