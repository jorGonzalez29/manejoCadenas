#include <stdio.h>
#include <string.h>
#include "prototipos.h"

char* i_toa(int num,char *s, int base)
{
    char *pri = s,
         *fin = s,
         c;
    static char numChar[] = {"0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZ"};

    if(base == 10 && num < 0)
    {
        *fin = '-';
        num *= -1;
        fin ++;
    }

    while(num)
    {
        *fin = numChar[(num % base)];
        num /= base;
        fin ++;
    }
    *fin = '\0';
    fin --;

    while(pri <= fin)
    {
        c = *fin;
        *fin = *pri;
        *pri = c;

        pri ++;
        fin --;
    }
    return s;
}
