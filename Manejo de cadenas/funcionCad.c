#include <stdio.h>
#include <string.h>
#include "protCad.h"

char *siEsSubCadena(const char *s1,const char *s2)
{
    char *cad1 = s1,
         *cad2 = s2;
    int cant = 0;
    while(*cad2)
    {
        cad2++;
        cant++;
    }
    cad2 -= cant;

    while(*cad1 && *cad2)
    {
        if(*cad1 == *cad2 && *cad2){
            cad1++;
            cad2++;
        }
        else{
            cad1++;
            cad2 = s2;
        }
    }

    return *cad2  != '\0' ? NULL : cad1 - cant;
}
