#include <stdio.h>
#include <stdlib.h>

int main()
{
    char *cadena = {"  hola  como estas  "},
         *subCad = {"  co mo  "};
    printf("SUBCADENAS CON ESPACIOS\n");

    if(subCadConEspacios(cadena,subCad))
        printf("La subcadena %s pertenece a la cadena %s",subCad,cadena);
    else
        printf("La subcadena %s no pertenece a la cadena %s",subCad,cadena);
    return 0;
}
