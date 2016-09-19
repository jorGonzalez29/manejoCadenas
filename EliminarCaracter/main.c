#include <stdio.h>
#include <stdlib.h>
#include "protEliminar.h"
int main()
{
    char s1[] = {"algo que se me ocurrió"},
         s2[] = {"aeiou"};
    int cant;
    printf("Prueba eliminar caraacter\n");

    puts(s1);
    puts(s2);
    cant = deleteChar(s1,s2);
    printf("La cadena modificada es: %s",s1);
    printf("Cantidad de caracteres eliminados: %d",cant);

    return 0;
}
