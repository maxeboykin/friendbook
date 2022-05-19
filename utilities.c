//
// Created by Max Boykin on 5/11/22.
//
#include "string.h"
#include "ctype.h"
#include "utilities.h"

void strtolower(char *str)
{
    int len = strlen(str);
    int i;
    for(i=0; i < len; i++) {
        str[i] = tolower(str[i]);
    }
}