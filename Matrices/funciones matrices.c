#include <stdio.h>
#include "prototipos funciones.h"

int matrizIdentidad(int m[][COLUMNAS])
{
    int i = 0,
        j;

    while(i < FILAS)
    {
        j = 0;
        while(j < COLUMNAS)
        {
            if(i == j)
            {
                if(m[i][j] != 1)
                    return 0;
            }
            else
            {
                if(m[i][j] != 0)
                    return 0;
            }
            j ++;
        }
        i ++;
    }
    return 1;
}

int matrizSimetica(int m[][COLUMNAS])
{
    int f,
        c = 0;

    while(c < COLUMNAS)
    {
        f = c + 1;
        while(f < FILAS)
        {
            if(m[f][c] != m[c][f])
                return 0;
            f ++;
        }
        c ++;
    }
    return 1;
}

void transponerMatriz(int m[][COLUMNAS])
{
    int f,
        c = 0,
        n;

    while(c < COLUMNAS)
    {
        f = c + 1;
        while(f < FILAS)
        {
            n = m[f][c];
            m[f][c] = m[c][f];
            m[c][f] = n;
            f ++;
        }
        c ++;
    }
}

void mostrarMatriz(int m[][COLUMNAS])
{
    int f = 0,
        c;

    for(; f < FILAS ; f ++)
    {
        puts("");
        for(c = 0; c < COLUMNAS ; c ++)
            printf("%d",m[f][c]);
    }
}
