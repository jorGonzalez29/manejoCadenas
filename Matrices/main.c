#include <stdio.h>
#include <stdlib.h>
#include "prototipos funciones.h"
int main()
{
    int m[FILAS][COLUMNAS] = {{1,4,1},
                              {0,0,1},
                              {1,2,1}};
    printf("Matrices\n");
    if(matrizIdentidad(m))
        puts("Es matriz identidad");
    else
        puts("No es matriz identidad");

    if(matrizSimetica(m))
        puts("Es matriz simetrica");
    else
        puts("No es matriz simetrica");

    transponerMatriz(m);
    mostrarMatriz(m);
    return 0;
}
