#include "program.h"
#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#include "../stack/stack.h"




// Take string from user


char* SetString()
{
    char *str = (char *)calloc(1,sizeof(char));
    int len = 1;
    *str = '\0';
    char ch;
    ch = getchar();
    int cnt = 1;
    while(ch != '\n'){
        if(cnt == len)
        {
            str = (char *)realloc(str, (2 * len) * sizeof(char));
            len = 2 * len;
        }
        *(str + cnt - 1) = ch;
        *(str + cnt) = '\0';
        cnt++;
        ch = getchar();
    }
    fflush(stdin);
    if(len == 1 ) return SetString();
    return str;
}


// convert String to int


int StringToInt(char* StringNum)
{
    if(strlen(StringNum) > 10) return -1;
    int num = 0;
    for(int i = 0; i < strlen(StringNum); i++)
    {
        if(!isdigit(StringNum[i])) return -1;
        num *= 10;
        num += StringNum[i] - '0';
    }
    return num;
}


//


int is_digit(char ch){
	
	return (ch >= '0' && ch <='9');
}
	
	

// validate choice	


int ChoiceValidate()
{
    int choice;
    char *temp;
    do{
        temp = SetString();
        choice = StringToInt(temp);
    } while((choice!=1 && choice!=2) && printf("\nInvalid Choice! please try again..\n\nYour Choice : "));
    return choice;
}


char *Validate_Operation()
{
	bool flag = 0;
	char *str;
	do{
	str = SetString();
	//printf("\n%s\n", str);
	flag = 0;
	
	for(int i = 0; i < strlen(str); ++i){
		
		if(!is_digit(str[i]) && str[i] != '-' && str[i] != '+' &&  str[i] != '*' &&  str[i] != '/' &&  str[i] != '^' && str[i] != '.' && str[i] != '(' && str[i] != ')' ){ 
		 
		   printf("\n1111111111\n");
		   flag = 1;
		   break;
		}
		if(str[i] == '-' || str[i] == '+' || str[i] == '*' ||  str[i] == '/' ||  str[i] == '^' || str[i] == '('){
			
			if(str[i+1] == '*' ||  str[i+1] == '/' ||  str[i+1] == '^' || str[i+1] == ')'){
				
				printf("\n22222222222\n");
				flag = 1;
		        break;
				
			}
		}
	}
	
	
	Stack st;
	CreateStack(&st);
	StackEntry e;
	
	for(int i = 0; i < strlen(str); ++i){
		
		
		if(StackEmpty(&st) || str[i] != ')') push(str[i], &st);

		if(str[i] == ')'){
			bool f = 1;
			while(f){
				pop(&e, &st);
				if(e == '(') f = 0;
			}
			
		}	
	}
	
	
	/*while(!StackEmpty(&st)){
		printf(" %d ",StackTop(&st));
		pop(&e, &st);
	}*/
	
	
	while(!StackEmpty(&st)){
		if(StackTop(&st) == '(' || StackTop(&st) == ')' ) {
			
			printf("\n3333333333333333\n");
			flag = 1;
			break;
		}
		pop(&e, &st);
	}
		
	printf("   %d      ", flag);
	}while(flag && printf("\n\nInvalid Operation, Try Again...\n\nyour operation : "));
		
    return str;		
}


// gcc main.c ../program/program.c ../stack/stack.c -o main.exe