#include <stdio.h>
#include <stdlib.h>
#include "ListDynamicPrototipes.h"
int main()
{
    FILE *file;
    List listDynamic;
    info reg;
    char option;
    printf("/t/t/t/tPrueba Lista Dinamica\n");
    if(!openFile(&file,FILE_NAME,"r+b",!MESSAGE_OR_NOT))
    {
        createFile();
        if(!openFile(&file,FILE_NAME,"r+b",MESSAGE_OR_NOT))
            return 0;
    }
    showFile(&file);
    createList(&listDynamic);

    fread(&reg,1,sizeof(info),file);
    while(!feof(file))
    {
        putTheTopOfTheList(&listDynamic,&reg);
        fread(&reg,1,sizeof(info),file);
    }
    fseek(file,0L,SEEK_SET);

    option = menu(MESS,OPTIONS);

    while(option != 'i')
    {
        switch(option)
        {
        case 'b':
            {
                bubbleSortList(&listDynamic);
                puts("Lista ordenada por DNI");
                break;
            }
        case 'c':
            {
                puts("Ingrese el DNI del nodo a eliminar:");
                fflush(stdin);
                scanf("%08ld",&reg.dni);
                if(removeFromList(&listDynamic,&reg,compear) == NOT_FOUND)
                    puts("Nodo no encontrado");
                break;
            }
        case 'd':
            {
                /**DNI**/
                printf("DNI:");
                fflush(stdin);
                scanf("%08ld",&reg.dni);
                puts("");
                if(searchNode(&listDynamic,&reg,compear) == O_K)
                    showData(&reg);
                else
                    puts("Nodo no encontrado");
                break;
            }
        case 'f':
            {
                /**DNI**/
                printf("DNI:");
                fflush(stdin);
                scanf("%08ld",&reg.dni);
                puts("");
                /**APELLIDO**/
                printf("APELLIDO:");
                fflush(stdin);
                scanf("%s",reg.surName);
                puts("");
                /**NOMBRE**/
                printf("NOMBRE:");
                fflush(stdin);
                scanf("%s",reg.name);
                puts("");
                /**PROMEDIO**/
                printf("PROMEDIO:");
                fflush(stdin);
                scanf("%f",&reg.average);
                puts("");

                if(putTheTopOfTheList(&listDynamic,&reg) == WITHOUT_MEMORY)
                    puts("Sin memoria");
                break;
            }
        case 'g':
            {
                /**DNI**/
                printf("DNI:");
                fflush(stdin);
                scanf("%08ld",&reg.dni);
                puts("");
                /**APELLIDO**/
                printf("APELLIDO:");
                fflush(stdin);
                scanf("%s",reg.surName);
                puts("");
                /**NOMBRE**/
                printf("NOMBRE:");
                fflush(stdin);
                scanf("%s",reg.name);
                puts("");
                /**PROMEDIO**/
                printf("PROMEDIO:");
                fflush(stdin);
                scanf("%f",&reg.average);
                puts("");

                if(putAnEndTheList(&listDynamic,&reg) == WITHOUT_MEMORY)
                    puts("Sin memoria");
                break;
            }
        case 'h':
            {
                /**DNI**/
                printf("DNI:");
                fflush(stdin);
                scanf("%08ld",&reg.dni);
                puts("");
                /**APELLIDO**/
                printf("APELLIDO:");
                fflush(stdin);
                scanf("%s",reg.surName);
                puts("");
                /**NOMBRE**/
                printf("NOMBRE:");
                fflush(stdin);
                scanf("%s",reg.name);
                puts("");
                /**PROMEDIO**/
                printf("PROMEDIO:");
                fflush(stdin);
                scanf("%f",&reg.average);
                puts("");

                if(putInOrder(&listDynamic,&reg,compear,accumulate) == WITHOUT_MEMORY)
                    puts("Sin memoria");
                break;
            }
        }
        option = menu(MESS,OPTIONS);
    }
    putListInFile(&listDynamic,&file);

    showFile(&file);
    fclose(file);
    clearList(&listDynamic);
    return 0;
}
