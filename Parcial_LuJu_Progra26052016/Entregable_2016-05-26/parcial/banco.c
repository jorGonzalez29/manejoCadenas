#include<banco.h>
#include<lista.h>
#include<utilitarias.h>
#include<string.h>
#include<stdlib.h>

void actualizar_cuentas(FILE * arch_ctas, FILE * arch_movs, FILE * arch_err, t_lista *plista)
{
    ///Inserte el código aquí
}

int validar_nro_cuenta(const t_movimiento_banco * c1)
{
    char cadena[9];
    int contador = 0;

    while(contador < 9)
    {
        cadena[contador] =  *c1.cod_cta;
        contador++;
        c1++;
    }

    printf("cod mov %s", &(*c1->cod_cta));

    return 1;
    /*char *aux = c1;

    FILE *fp;
    int contador = 0,
        bandera = 0,
        c = 0;

    while(contador <= 6 && bandera == 0)
    {
        c = (int)(*c1);

        if(es_digito(c))
        {
            c++;
            contador++;
            bandera = 0;
        }
        else
            bandera = 1;
    }

    if(bandera == 1)
    {
       fp = fopen("error_nro_cta.txt", "r+t");
    }
    return 1;*/
}
