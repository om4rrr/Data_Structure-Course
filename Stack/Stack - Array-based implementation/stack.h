#ifndef STACK_H
#define STACK_H

#include <stdio.h>
#include <stdbool.h>

#define MAX_SIZE 100

typedef int StackEntry;

typedef struct Stack{
	
	int top;
	StackEntry items[MAX_SIZE];
}Stack;

void CreateStack(Stack *);

void Push(StackEntry, Stack *);

bool StackFull(Stack *);

void Pop(StackEntry *, Stack *);

bool StackEmpty(Stack *);

int StackSize(Stack *);

void ClearStack(Stack *ps);

void StackTop(StackEntry *, Stack *);

void TraverseStack(Stack *, void (*)(StackEntry));

#endif