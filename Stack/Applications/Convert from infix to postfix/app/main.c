#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "../program/program.h"


int main(){
	
	int choice;
	
	//printf("\nEnter your operation : ");
	//char *operation = Validate_Operation();
	
	Stack st;
	CreateStack(&st);
	StackEntry e;
	
	push(2, &st);
	push(1, &st);
	push(4, &st);
	push(7, &st);
	
	
	while(!StackEmpty(&st)){
		printf(" %d ",StackTop(&st));
		pop(&e, &st);
	}

	
	//while(1){
		
		
		
	//}
	return 0;
}

