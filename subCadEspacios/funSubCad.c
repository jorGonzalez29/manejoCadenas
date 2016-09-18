#include <stdio.h>
#include <string.h>
#include "protCadEspacios.h"

int subCadConEspacios(char *cad, char *sub)
{
    while(*cad && *sub)
    {
        if(!esBlanco(*cad) && !esBlanco(*sub))
        {
            if(*cad == *sub)
            {
                cad ++;
                sub ++;
            }
            else
                cad ++;
        }
        if(esBlanco(*cad))
            cad ++;
        else
            sub ++;
    }
    while(esBlanco(*sub))
        sub ++;

    return *sub == '\0';
}
