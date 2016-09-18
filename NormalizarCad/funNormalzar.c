#include <stdio.h>
#include <string.h>
#include "protNormalizar.h"

void normalizarCadena(const char *cad)
{
    char *pri = cad,
         *fin = cad;

    while(*fin)
    {
        while(esBlanco(*fin))
            fin ++;
        if(*fin)
        {
            *pri =esMayor(*fin);
            pri++;
            fin++;
            while(*fin && !esBlanco(*fin))
            {
                *pri = esMenor(*fin);
                pri++;
                fin++;
            }
            if(*pri)
            {
              *pri = ' ';
              pri++;
            }

        }
    }

    if(esBlanco(*(pri - 1)))
        *(pri - 1) = '\0';
}
