#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "funciones.h"

int main()
{
    char cadena[] = "ex2tua6kjveqtstim3dnvnte",
         cadena2[] = "3szl49994",
         cadena3[] = "artesano",
         cadena4[] = "Algo que se me ocurrio",
         cadena5[] = "aeiou";

    int a = 0,
        contador = 0;

    borraCaracteres(cadena4,cadena5,&contador);

    printf("\nLa cadena quedo: %s \n\ny la cantidad de caracteres borrados son %d\n",cadena4,contador);

    a = (int)strlenght(cadena);

    printf("\nLa cadena a modificar es: %s\n",cadena3);

    modificar(cadena3,4);

    printf("\nLa nueva cadena es: %s\n",cadena3);

    printf("\nLa cantidad es: %d\n",a);

    decodificar(cadena);


    printf("\nLa cadena es: %s\n",cadena);
    fflush(stdin);
    decodificar(cadena2);
    fflush(stdin);
    printf("\nLa cadena2 es: %s\n",cadena2);
    return 0;
}
