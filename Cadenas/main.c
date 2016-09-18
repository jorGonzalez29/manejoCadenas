#include <stdio.h>
#include <stdlib.h>
#include "protInversionCad.h"
int main()
{
    char cadena[] = {"malla*s"};
    printf("\t\t\t\t\tInversion cadena\n");

    invertirCad(cadena);

    puts(cadena);

    return 0;
}
