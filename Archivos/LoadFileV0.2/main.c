#include <stdio.h>
#include <stdlib.h>
#include "protLoadFile.h"

int main()
{
    FILE *fp;
    //employee reg;
    int pos,sizeVec;
    long tableKey[101];

    printf("\t\t\t\t\t\tModificar archivo con acceso directo");

    if(!openFile(&fp,"r+b",FileUpdate,WITH_WITHOUT_MSSG))
    {
        createFileEmployee();

        if(!openFile(&fp,"r+b",FileUpdate,WITH_WITHOUT_MSSG))
            return 1;
    }

    createTableOfKey(&fp,tableKey,&sizeVec);
    puts("\t\t\t\t\t\tArchivo sin modificar");
    showFileEmployee(&fp);
    while((pos = searchBuyKey(tableKey,&sizeVec)) >= 0)//toma mucho tiempo de ejecucion.
        changeBuyKey(&fp,pos);

    puts("\t\t\t\t\t\tArchivo modificado");
    showFileEmployee(&fp);

    fclose(fp);

    return 0;
}
