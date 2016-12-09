#include <stdio.h>
#include "protItoa.h"

char* i_toa(int num, int base, char *s)
{
    static const char vec[] = {"0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZ"};
    char *first = s,
         *last = s,
         c;
    unsigned n = (unsigned)num;
    /*unsigned n = (unsigned) num; por que no me lo castea como corresponde?  me tira cualquier numero*/

    if(base == 10 && num < 0)
    {
        *last = '-';
        first ++;
        last ++;
        n = - num;
    }

    while(n)
    {
        *last = vec[n % base];
        n /= base;
        last ++;

    }
    *last = '\0';
    last --;
    while(first < last)
    {
        c = *last;
        *last = *first;
        *first = c;

        first ++;
        last --;
    }
    return s;

}
