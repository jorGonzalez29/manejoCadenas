#include <stdio.h>
#include <string.h>

char * i_toa(int num, char *s, int base)
{
    char *pri = s,
         *fin = s,
         c;

    if(base == 10 && num < 0)
    {
        *fin = '-';
        fin ++;
    }

    while(num)
    {
        *fin = (num % base) + '0';
        num /= base;
        fin ++;
    }
    *fin = '\0';
    fin --;

    while(pri <= fin)
    {
        c = *fin;
        *fin = *pri;
        *pri = c;

        pri ++;
        fin --;
    }
    return s;
}

int main()
{
    int n,base;
    char vec[31];
    printf("\t\t\tFuncion i_toa\n");

    printf("Ingrese entero a transformar y base : ");
    fflush(stdin);
    scanf("%d",&n);
    printf("\n");
    scanf("%d",&base);
    puts(i_toa(n,vec,base));

    return 0;
}
