#include <stdio.h>
#include <string.h>
#include "ProtNormalizarCad.h"

void normalizeString(char *s)
{
    char *first = s,
         *last = s;

    while(*last)
    {
        while(esBlanco(*last) && *last)
            last ++;

        if(*last)
        {
            *first = capitalize(*last);
            first ++;
            last ++;
        }
        while(!esBlanco(*last) && *last)
        {
            *first = lowercase(*last);
            first ++;
            last ++;
        }
        if(*first)
        {
            *first = ' ';
            first ++;
        }

    }
    if( *(first - 1) == ' ')
    {
        first --;
        *first = '\0';
    }
}
