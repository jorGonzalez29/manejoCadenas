#include <stdio.h>
#include "menuPrototipes.h"
#include <string.h>
#include <ctype.h>

char menu(char *msj, char *option)
{
    char op;
    int b = 0;
    puts(msj);

    do
    {
        if(b)
            puts("Error - La opcion ingresada no es correcta, vuelva a ingresar una opcion valida");
        b = 1;

        fflush(stdin);
        scanf("%c",&op);
        op = tolower(op);
    }while(!strchr(option,op));
    return op;
}
