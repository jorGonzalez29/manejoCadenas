#include <stdio.h>
#include "protEncriptar.h"

char *encryptingString(char *s)
{
    char *first = s,
         *last = s,
         *next = NULL,
         c;

    while(*last)
    {
        while(!isEmpty(*last) && *last)
            last ++;

        next = last;
        last --;

        while(first <= last)
        {
            c = encrypt(*last);
            *last = encrypt(*first);
            *first = c;
            last --;
            first ++;
        }
        while(isEmpty(*next))
            next ++;
        first = next;
        last = next;
    }
    return s;
}

char encrypt(const char c)
{
    static char letters [][6] = {{"aeiout"},
                                 {"231047"}};
    int row = 0,
        colum = 0;
//se puede remplazar por dos for que recorran dos vectores, letras y numeros, preguntando si es igual a C
    while(row <= TAM_ROW)
    {
        while(colum <= TAM_COLUM)
        {
            if(!row)
            {
                if(letters[row][colum] == c)
                    return letters[row + 1][colum];
            }
            else
            {
                if(letters[row][colum] == c)
                    return letters[row - 1][colum];
            }
            colum ++;
        }
        row ++;
        colum = 0;
    }
    return c;
}
