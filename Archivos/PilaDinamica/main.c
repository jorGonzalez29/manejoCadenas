#include <stdio.h>
#include <stdlib.h>
#include "protPilaDim.h"

int main()
{
    tPile pile;
    tInfo data;
    FILE *fp;
    char option;
    printf("Prueba Pila dinamica\n");

    if(!openFile(&fp,DATOS,"r+b",!CON_SIN_MSJ))
    {
        createFile();
        if(!openFile(&fp,DATOS,"r+b",CON_SIN_MSJ))
            return 0;
    }
    showFile(&fp);
    puts("Cargando archivo en la pila... ");
    createStack(&pile);
    fread(&data,1,sizeof(person),fp);
    while(!feof(fp) && !fullStack(&pile))
    {
        pushingOnStack(&pile,&data);
        fread(&data,1,sizeof(tInfo),fp);
    }

    fclose(fp);
    /**/
    option = menu(MSJ,OPTIONS);
    while(option != 'D')
    {
        switch(option)
        {
        case 'A':
            printf("Ingrese registro: ");
            fflush(stdin);
            scanf("%ld",&data.dni);
            fflush(stdin);
            scanf("%s",&data.firstName);
            fflush(stdin);
            scanf("%s",&data.surName);
            fflush(stdin);
            scanf("%c",&data.sex);
            data.sex = toupper(data.sex);
            fflush(stdin);
            scanf("%2d/%2d/%4d",&data.fec.day,&data.fec.month,&data.fec.year);
            fflush(stdin);
            scanf("%f",&data.qualification);
            fflush(stdin);
            scanf("%f",&data.salary);

            puts(" ");
            puts("Cargando nuevo dato...");

            if(!pushingOnStack(&pile,&data))
                puts("Dato no pudo ser procesado, pila llena");
            break;

        case 'B':
            puts("Viendo tope...");
            if(!showTop(&pile,&data))
                puts("Imposible ver tope, pila vacia");
            else
                showData(&data);
            break;
        case 'C':
            puts("Sacando contenido de pila");
            while(!ifEmptyStack(&pile))
            {
                takeOfStack(&pile,&data);
                showData(&data);
            }
            break;
        }
        option = menu(MSJ,OPTIONS);
    }
    emptyStack(&pile,&data);
    puts("Saliendo del programa...");
    return 0;
}
