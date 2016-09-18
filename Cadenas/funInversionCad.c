#include <stdio.h>
#include <string.h>
#include "protInversionCad.h"

void invertirCad(const char *cad)
{
    char c;
    char *pri = cad,
         *fin = cad;
    while(*fin)
        fin++;
    fin --;
    while(pri <= fin)
    {
        c = *fin;
        *fin = *pri;
        *pri = c;
        pri ++;
        fin --;
    }
}
