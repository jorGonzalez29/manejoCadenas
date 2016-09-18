#include <stdio.h>
#include <stdlib.h>
#include "protArch.h"
#include "protEjercicio4ColaDim.h"

int main()
{
    FILE *fp;
    Queue cola;
    tInfo info;
    char op;
    printf("\t\t\tEjercicio 9 tp3 cola estatica\n");

    if(!openFile(&fp,"r+b",FILENAME,!CON_SIN_MSJ))
    {
        createFile();
        if(!openFile(&fp,"r+b",FILENAME,CON_SIN_MSJ))
            return 0;
    }
    createQueue(&cola);
    fread(&info,1,sizeof(tInfo),fp);
    while(!feof(fp) && !isQueueFull(&cola))
    {
        putInQueue(&cola,&info);
        fread(&info,1,sizeof(tInfo),fp);
    }
    fclose(fp);
    op = menuOption(MSJ,OPTION);
    while(op != 'D')
    {
        system("cls");
        switch(op)
        {
        case 'A':
            {
                newInfo(&info);
                if(putInQueue(&cola, &info) == COLA_LLENA)
                    puts("cola llena no se pudo cargar la nueva informacion");
                break;
            }
        case 'B':
            {
                puts("Viendo primero de la cola: ");
                if(showFirstInQueue(&cola,&info) != COLA_VACIA)
                    showInfo(&info);
                else
                    puts("cola vacia, no se puede ver primero");
                break;
            }
        case 'C':
            {
                puts("Sacando de cola...");
                if(takeOfQueue(&cola,&info) != COLA_VACIA)
                    showInfo(&info);
                else
                    puts("No se puede sacar de cola, cola vacia");

                break;
            }
        }
        op = menuOption(MSJ,OPTION);
    }
    if(!openFile(&fp,"r+b",FILENAME,CON_SIN_MSJ))
    {
        puts("Vaciando cola...");
        emptyQueue(&cola);
        return 0;
    }
    while(!isQueueEmpty(&cola))
    {
        takeOfQueue(&cola,&info);
        putInTheEndFile(&fp,&info);
    }
    emptyQueue(&cola);
    fclose(fp);
    return 0;
}
