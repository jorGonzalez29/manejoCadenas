#include <stdio.h>
#include <stdlib.h>
#include "protPalindrome.h"

int main()
{
    char cad[51] = {"   la ruta nos apor      to otro paso nat   ural"};
    printf("Prueba palindromo\n");

    if(isPalindrome(cad))
        puts("La palabra o frace es palindromo");
    else
        puts("La palabra o frace no es palindromo");

    return 0;
}
