#ifndef PORGRAM_H
#define PROGRAM_H

#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "../stack/stack.h"


char* SetString();

int StringToInt(char*);

int ChoiceValidate();

char *Validate_Operation();

int is_digit(char ch);





#endif
