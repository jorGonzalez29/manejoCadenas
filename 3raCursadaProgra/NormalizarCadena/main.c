#include <stdio.h>
#include <stdlib.h>
#include "ProtNormalizarCad.h"
int main()
{
    char vec[] = {"   jEsSicA   A  "};
    printf("Prueba normaliza cadena\n");
    normalizeString(vec);
    puts(vec);
    return 0;
}
