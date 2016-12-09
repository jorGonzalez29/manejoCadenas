#include <stdio.h>
#include <stdlib.h>
#include "protDecodificar.h"

int main()
{
    char vec[] = {"ex2tua6kjveqtstim3dnvnte"};
    printf("Prueba decodificar\n");
    printf("La cadena original es: %s\n",vec);
    printf("La cadena decodificada es:%s\n",decode(vec));
    return 0;
}
