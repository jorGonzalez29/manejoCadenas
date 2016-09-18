#include <stdio.h>
#include <stdlib.h>
#include "protNormalizar.h"

int main()
{
    char cadena []={"   cEnTrO   sUd   JKUYKLO  "};
    printf("\t\t\t\tNormalizar cadena\n");
    normalizarCadena(cadena);

    puts(cadena);

    return 0;
}
