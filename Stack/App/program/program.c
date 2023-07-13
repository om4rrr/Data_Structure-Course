#include "program.h"


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
    bool flag;
    char *str;
    do{
        str = SetString();
        flag = 0;

        for(int i = 0; i < strlen(str); ++i){

            if(!is_digit(str[i]) && str[i] != '-' && str[i] != '+' &&  str[i] != '*' &&  str[i] != '/' &&  str[i] != '^' && str[i] != '.' && str[i] != '(' && str[i] != ')' ){
                flag = 1;
                break;
            }
            if(str[i] == '-' || str[i] == '+' || str[i] == '*' ||  str[i] == '/' ||  str[i] == '^' || str[i] == '('){

                if(str[i+1] == '*' ||  str[i+1] == '/' ||  str[i+1] == '^' || str[i+1] == ')'){
                    flag = 1;
                    break;
                }
            }
        }

        Stack st;
        CreateStack(&st);

        char ch = ')';
        int top = 0;
        for(int i = 0; i < strlen(str); ++i){
            if(!StackEmpty(&st))StackTop((void*)&top,&st, sizeof(top));
            if(str[i] == '(') push((void*)&ch, &st, sizeof(ch));
            if(str[i] == ')') pop(&st);
        }
        if(!StackEmpty(&st)) flag = 1;
    }while(flag && printf("\n\nInvalid Operation, Try Again...\n\nyour operation : "));
    return str;
}

char *Infix_To_Postfix(char *infix){

    Stack st;
    CreateStack(&st);
    int op, num, i , j, temp = 0;

    for(i = 0,  j = 0; i < strlen(infix); ++i){

        if(is_digit(infix[i])) temp = temp * 10 + infix[i];
        else{

        }
    }



}
