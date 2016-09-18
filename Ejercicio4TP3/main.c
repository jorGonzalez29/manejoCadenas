#include <stdio.h>
#include <stdlib.h>
#include "protEjer4.h"
int main()
{
    FILE *fp;
    Pile pile;
    tInfo info;
    char op;
    printf("\t\t\tEjercicio 4 tp3 Pila estatica\n");

    if(!openFile(&fp,"r+b",FILENAME,!CON_SIN_MSJ))
    {
        createFile();
        if(!openFile(&fp,"r+b",FILENAME,CON_SIN_MSJ))
            return 0;
    }
    createStack(&pile);
    fread(&info,1,sizeof(tInfo),fp);
    while(!feof(fp) && !isStackFull(&pile))
    {
        putInStack(&pile,&info);
        fread(&info,1,sizeof(tInfo),fp);
    }
    fclose(fp);
    op = menuOption(MSJ,OPTION);
    while(op != 'D')
    {
        switch(op)
        {
        case 'A':
            {
                newInfo(&info);
                if(putInStack(&pile, &info) == PILA_LLENA)
                    puts("pila llena no se pudo cargar la nueva informacion");
                break;
            }
        case 'B':
            {
                puts("Viendo tope de la pila: ");
                if(showTop(&pile,&info) != PILA_VACIA)
                    showInfo(&info);
                else
                    puts("Pila vacia, no se puede ver tope");
                break;
            }
        case 'C':
            {
                puts("Sacando de pila...");
                if(takeOfStack(&pile,&info) != PILA_VACIA)
                    showInfo(&info);
                else
                    puts("No se puede sacar de pila, pila vacia");

                break;
            }
        }
        op = menuOption(MSJ,OPTION);
    }
    if(!openFile(&fp,"r+b",FILENAME,CON_SIN_MSJ))
    {
        puts("Vaciando pila...");
        emptyStack(&pile);
        return 0;
    }
    while(!isStackEmpty(&pile))
    {
        takeOfStack(&pile,&info);
        putInTheEndFile(&fp,&info);
    }
    emptyStack(&pile);
    fclose(fp);
    return 0;
}
