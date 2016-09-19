#include <stdio.h>
#include "protDecodificar.h"

char* decode(char* s)
{
    char* first = s,
        *  last = s,
        *  next = s,
        *  pos = NULL,
           c;

    int i = 1,
        digit;

    while(*next)
    {
       while(*next && !isDigit(*next))
        {
            *first = *next;
            first ++;
            next ++;
        }

        if(*next)
        {
            digit = isDigit(*next);
            next += digit;
            last = next;
            pos = first + digit;

            while(first <= last)
            {
                if(first > next - digit)
                {
                    c = *last - i;
                    *last = *first - digit;
                    *first = c;
                    digit --;
                }
                else
                    *first = *last - i;

                last --;
                first ++;
                i ++;
            }

            first = pos;
            next ++;
            i = 1;
        }
    }
    *first = '\0';

    return s;
}

int isDigit(const char c)
{
    const char* digit = {"123456789"};

    while(*digit)
    {
        if(c == *digit)
            return c - '0';
        digit ++;
    }
    return 0;
}
