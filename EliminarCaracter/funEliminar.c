#include <stdio.h>
#include "protEliminar.h"

int deleteChar(char *s1,const char *s2)
{
    char *first = s1,
         *last = s1,
         *next = s1;
    int accumulator = 0;

    while(*next)
    {
        while(isWhite(*next) && *next)
            next ++;
        while(*next && !isWhite(*next))
        {
            if(isCharacter(*next, s2))
            {
                *next = ' '; //error de segmentacio
                accumulator ++;
            }
            next ++;
        }
        while(last < next)
        {
            if(*last != ' ')
            {
                *first = *last;
                first ++;
            }
            last ++;
        }
        *first = ' ';
        first ++;
    }
    first --;
    *first = '\0';

    return accumulator;
}

int isCharacter(const char c, const char *s)
{
    while(c != *s && *s)
        s ++;

    return c == *s ? 1 : 0;
}
