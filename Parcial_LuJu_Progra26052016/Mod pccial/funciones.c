#include <stdio.h>
#include <stdlib.h>
#include "funciones.h"
#include <string.h>

char *decodificar(char *cad)
{
    int contador = 0,
        d = 0,
        num = 0,
        acumulador = 0; /*linea de mas*/

    char *aux = cad,
         *aux2 = cad,
         *aux3 = cad,
         copia,
         c,
         auxiliar1,
         auxiliar2;

    while(*cad != '\0')
    {
        copia = *cad;

        num = (int)atoi(&copia);

        d = esDigito(num);

        /*lineas de mas*/
        if(d == 1)
            acumulador++;
        else
            acumulador = 0;
       if(acumulador >1)
       {
           return cad;
       }

        if(d == 0)
        {
            cad++;
            aux++;
        }
        else
        {
            contador = 1;

            aux += num;

            c = *aux;

            while(num != 0)
            {
                c -= contador;
                *aux = c;

                num--;
                aux--;
                contador++;

                c = *aux;
            }

            contador--;
            num = contador;
            contador = 0;
            aux += num;

            c = *aux;

            aux2 = cad;
            aux3 = aux;
            cad++;

            auxiliar1 = *aux;
            auxiliar2 = *cad;

            while(contador < num)
            {
                *cad = auxiliar1;
                *aux = auxiliar2;

                cad++;
                contador++;
                num--;
                aux--;

                if(contador < num)
                {
                    auxiliar1 = *aux;
                    auxiliar2 = *cad;
                }
            }
            cad = aux2;
            aux = cad+1;

            while(*aux != '\0')
            {
                *cad = *aux;

                aux++;
                cad++;
            }

            *cad = '\0';

            cad = aux2;
            aux = aux2;

            acumulador = 1; /*linas de mas*/
        }
    }

    return cad;
}

char *strlenght(char *cadena)
{
    if(*cadena=='\0')
        return 0;

    return strlenght(cadena+1)+1;
}

char *modificar(char *cadena, int a)
{
    int b = 0,
        contador = 0;

    b = (int)strlenght(cadena);

    if(a > b)
    {
        printf("\nValor fuera de rango\n"
               "\nLa cadena posee %d caracteres\n"
               "\nEl numero es: %d\n",b,a);
        return 0;
    }

    while(cadena && a >= contador)
    {
        cadena++;
        contador++;
    }

    *cadena = '\0';

    return cadena;
}

char *borraCaracteres(char *cadena, char *datos, int *contador)
{
    char *aux = cadena;

    while(*datos != '\0')
    {
        while(*cadena != '\0')
        {
            if(*cadena == *datos)
            {
                *cadena = ' ';

                cadena ++;

                *contador += 1;
            }
            else
                cadena ++;
        }

        if(*cadena == '\0')
            cadena = aux;

        datos++;
    }

    return cadena;

}
