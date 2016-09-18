#include <stdio.h>
#include <stdlib.h>
#include "protArboles.h"
int main()
{
    FILE *fp;
    tInfo info;
    Arbol tree;
    int cont = 0;
    char op;
    printf("Ejercicio 2 Arbol Binario\n");
    if(!openFile(&fp,"r+b",nameFile,!CON_SIN_MSJ))
    {
        createFile();
        if(!openFile(&fp,"r+b",nameFile,CON_SIN_MSJ))
            return 0;
    }
    showFile(&fp);
    createTree(&tree);
    fread(&info,1,sizeof(tInfo),fp);
    while(!feof(fp) && !isTreeFull(&tree))
    {
        putInTree(&tree,&info,&cont,compear);
        fread(&info,1,sizeof(tInfo),fp);
    }
    op = menuOption(MSJ,OPTION);
    while(op != 'L')
    {
        switch(op)
        {
        case 'A':
            {
                newInfo(&info);
                if(!isTreeFull(&tree))
                {   if(putInTree(&tree,&info,&cont,compear) == CLAV_DUP)
                        puts("Informacion duplicada, no se pudo completar la accion");
                    else
                        putAtTheEnd(&fp,&info);
                }
                break;
            }
        case 'B':
            {
                printf("Ingrese clave:");
                fflush(stdin);
                scanf("%ld",&info.dni);
                showInfoByKey(&fp,searchInTree(&tree,&info,compear));
                break;
            }
        case 'C':
            {
                puts("Informacion en orden");
               order(&tree,&fp);
               break;
            }
        case 'D':
            {
                puts("Informacion en posOrden");
               posOrder(&tree,&fp);
               break;
            }
        case 'E':
            {
                puts("Informacion en preOrden");
               preOrder(&tree,&fp);
               break;
            }
        case 'F':
            {
                printf("Hojas: %d",sheetsCounting(&tree));
                break;
            }
        case 'G':
            {
               printf("Nodos: %d",countingNodes(&tree));
               break;
            }
        case 'H':
            {
                if(completeTree(&tree))
                    puts("Arbol completo");
                else
                    puts("Arbol no completo");
                break;
            }
        case 'I':
            {
                if(isAVL(&tree))
                    puts("Arbol es AVL");
                else
                    puts("Arbol no es AVL");
                break;
            }
        case 'J':
            {
                if(balancedTree(&tree))
                    puts("Arbol es balanceado");
                else
                    puts("Arbol no es balanceado");
                break;
            }
        }
        op = menuOption(MSJ,OPTION);
    }
    fclose(fp);
    emptyTree(&tree);
    return 0;
}
