#include <stdio.h>
#include "protItoa.h"

int a_toi(const char *s)
{
    int num = 0,
        sig = 1;
    char *aux = (char*) s;

    while(esBlanco(*aux))
        aux ++;

    if(*aux == '-')
    {
        sig = -1;
        aux ++;
    }
    else{
        if(*aux == '+')
            aux ++;
    }

    while(*aux && esDigito(*aux))
    {
        num = (num * 10) + (*aux - '0');
        aux ++;
    }

    return num * sig;
}
