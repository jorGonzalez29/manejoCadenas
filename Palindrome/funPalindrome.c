#include <stdio.h>
#include "protPalindrome.h"

int isPalindrome(const char *s)
{
    const char *first = s,
               *last = s;

    while(*last)
        last ++;

    last --;

    while(first < last)
    {
        if(*first == *last)
        {
            first ++;
            last --;
        }
        else
        {
            switch(isEmptyOrNot(first,last))
            {
            case 0:
                {
                    return 0;
                }

            case 1:
                {
                    first ++;
                    break;
                }

            case 2:
                {
                    last --;
                    break;
                }
            }
        }
    }
    return 1;
}

int isEmptyOrNot(const char *const f, const char *const l)
{
    if(isEmpty(*f))
        return 1;

    if(isEmpty(*l))
        return 2;
    return 0;
}
