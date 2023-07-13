#ifndef STACK_H
#define STACK_H

#include <stdio.h>
#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

//#define LIMITED_MEMORY


#ifdef LIMITED_MEMORY

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

#else

//typedef int StackEntry;

/*typedef struct elementtype{
	short int etype;
	union{
		int number;
		char character;
	}info;
}ElementType;*/


typedef struct stacknode{
    void *entry;
    struct stacknode *next;
}StackNode;


typedef struct stack{
    StackNode *top;
    int size;
}Stack;


void CreateStack(Stack*);

//void push(StackEntry, Stack *);

void push(void *pe, Stack *ps, int z);

//void pop(StackEntry *, Stack *);

void pop(Stack *ps);

bool StackEmpty(Stack *);

bool StackFull(Stack *);

void ClearStack(Stack *);

void TraverseStack(Stack *ps, void (*pf)(void*));

int StackSize(Stack *);

void StackTop( void *pe,Stack *ps, int z);

//void* StackTop( Stack *ps);


#endif

#endif
