#include <stdio.h>
#include <stdlib.h>
#include "protArboles.h"

int main()
{
    tree tree;
    FILE *file;
    tInfo info;
    int h, c = 1;
    printf("Prueba arboles\n");
    if(!openFile(&file,"r+b",FILE_INFO,!CON_SIN_MSJ))
    {
        createFilePerson();
        if(!openFile(&file,"r+b",FILE_INFO,CON_SIN_MSJ))
            return 0;
    }
    createTree(&tree);
    puts("arbol creado...");
    puts("cargando archivo en arbol...");
    fread(&info,1,sizeof(tInfo),file);
    while(!feof(file) && !isFullTree(&tree))
    {
        tidyUp(&tree,&info,compear);
        fread(&info,1,sizeof(tInfo),file);
    }
    fclose(file);
    if(!ifEmptyTree(&tree))
    {
        puts("mostrando arbol en post-orden...");
        postOrder(&tree);
        puts("mostrando arbol en-orden...");
        inOrder(&tree);
        puts("mostrando arbol en pre-orden...");
        preOrder(&tree);
        puts("Obteniendo altura del arbol...");
        h = heigthTree(&tree);
        printf("Altura del arbol: %d",h);
        puts("Obteniendo cantidad de hojas...");
        printf("Hojas del arbol: %d\n",sheetsCounting(&tree));
        puts("Si arbol es AVL o no...");
        if(ifTreeAvl(&tree,heigth))
            puts("Es AVL");
        else
            puts("No es AVL");
        printf("Cantidad de nodos: %d\n",nodesCounting(&tree));
        if(balancedTree(&tree,h,c))
            puts("Esta balanceado");
        else
            puts("No esta balanceado");
    }
    return 0;
}
