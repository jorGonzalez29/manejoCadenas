#include <stdio.h>
#include <stdlib.h>
#include "protEncriptar.h"
int main()
{
    char cad1 [101] = {"La Era del Hielo fue en el Pleistoceno hace mas de 12490 años"},
         cad2 [101] = {"2L 2rE l3d 0l31H 34f n3 l3 0n3c07s13lP 3c2h s2m 3d o9uai s0ñ2"};

    printf("Prueba encriptar cadena\n");

    printf("La cadena 1: %s\n",cad1);
    printf("La cadena 1 encriptada: %s\n",encryptingString(cad1));
    printf("La cadena 2: %s\n",cad2);
    printf("La cadena 2 desencriptada: %s\n",encryptingString(cad2));

    return 0;
}
