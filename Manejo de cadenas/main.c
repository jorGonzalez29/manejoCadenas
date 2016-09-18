#include <stdio.h>
#include <stdlib.h>
#include "protCad.h"
int main()
{
    printf("\t\t\t\t Manejo cadenas\n");
    char cadena1[] = {"casa blanca, casa blanca"},
         cadena2[] = {" "};
    if(siEsSubCadena(cadena1,cadena2))
        printf("\n\n La subcadena \"%s\" esta en la cadena 1",cadena2);
    else
        printf("\n\n La subcadena \"%s\" no esta en la cadena 1",cadena2);


    return 0;
}
