#include <stdio.h>
#include <string.h>
#include "protDeco.h"

void decodificarCad(char *cad)
{
    char *pri = cad,
         *fin = cad,
         *aux;
    int cont,
        cont2;
    char c;
    while(*pri)
    {
        while(!esDigito(*fin) && *fin)
        {
            *pri = *fin;
            fin ++;
            pri ++;
        }
        if(*fin)
       {
            cont = 1;
            cont2 = *fin - '0';
            fin = fin + cont2;
            aux = fin + 1;
            cad = pri + cont2;
            while(pri <= fin)
            {
                 c = *fin - cont;
                 if(fin >= cad)
                 {
                     *fin = *pri;
                     *pri = c;
                 }
                 else
                 {
                     *fin = *pri - cont2;
                     *pri = c;
                     cont2 --;
                 }
                 cont ++;
                 pri ++;
                 fin --;

            }

            pri = cad;
            fin = aux;
       }
       else
        *pri = '\0';
    }

}
