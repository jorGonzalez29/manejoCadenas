#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include "protColaParcial.h"

int main()
{
    FILE *fp;
    tInfo reg;
    tQueue cola;
    long numPas;
    int bandera = 0;
    puts("\t\t\t\t\t\t\tPrueba ejercicio cola dinamica");
    if(!openFile(&fp,DATA,"r+b",!CON_SIN_MSJ))
    {
        if(!openFile(&fp,DATA,"w+b",CON_SIN_MSJ))
            return 0;
    }
    createQueue(&cola);
    printf("Ingrese evento a solicitar: ");
    do
    {
        if(bandera)
            puts("Opcion no valida, vuelva a ingresar opcion");
        else
            bandera = 1;
        fflush(stdin);
        scanf("%c",&reg.eventCod);
        reg.eventCod = toupper(reg.eventCod);
    }while(strchr(EVENTOS,reg.eventCod) == NULL);

    while(reg.eventCod != '*')
    {
        if(reg.eventCod == 'S')
        {
            bandera = 0;
            printf("\nIngrese DNI del pasajero en espera: ");
            do
            {
                if(bandera)
                    puts("DNI invalido, vuelva a ingresarlo");
                else
                    bandera = 1;
                fflush(stdin);
                scanf("%ld",&reg.id);
            }while(DNI_VALIDO(reg.id));

            if(!pushingInQueue(&cola,&reg))
                puts("Cola llena, imposible ingresar datos");
        }
        else
        {
            bandera = 0;
            printf("\nIngrese Nro de pasaje del pasajero en espera: ");
            do
            {
                if(bandera)
                    puts("Nro de pasaje invalido, vuelva a ingresarlo");
                else
                    bandera = 1;
                fflush(stdin);
                scanf("%ld",&numPas);
            }while(DNI_VALIDO(numPas));

            if(!takeOfQueue(&cola,&reg))
                puts("Cola vacia, imposible sacar datos");
            else
            {
                printf("%ld\t",numPas);
                showData(&reg);
            }
        }


        printf("Ingrese evento a solicitar: ");
        bandera = 0;
        do
        {
            if(bandera)
                puts("Opcion no valida, vuelva a ingresar opcion");
            else
                bandera = 1;
            fflush(stdin);
            scanf("%c",&reg.eventCod);
            reg.eventCod = toupper(reg.eventCod);
        }while(strchr(EVENTOS,reg.eventCod) == NULL);
    }

    while(takeOfQueue(&cola,&reg))
        fwrite(&reg,1,sizeof(reg),fp);

    showFile(&fp);

    fclose(fp);
    return 0;
}
