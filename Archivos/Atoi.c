#include <stdio.h>


int a_toi(char *s)
{
    int num = 0,
        sig = 1;

    if(*s)
    {
        if(*s == '-')
        {
            sig *= -1;
            s ++;
        }
        while(*s)
        {
            num = (*s - '0') + num *10;
            s ++;
        }
    }
    return num * sig;
}

int main()
{
char numPtr[] = {"82434"};
printf( "Convirtiendo la cadena \"%s\" en un numero: %d\n", numPtr, a_toi(numPtr));
}
