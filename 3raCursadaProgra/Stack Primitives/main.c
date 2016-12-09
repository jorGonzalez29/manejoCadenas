#include <stdio.h>
#include "stackDinamicPrototipe.h"
#include "filePrototipe.h"
#include "menuPrototipes.h"

int main()
{
    pile pile;
    FILE *fileData;
    info reg;
    char optionSelected;

    printf("Prueba Pila estatica\n");

    if(!openFile(&fileData,FILE_DATA,"r+b",!CON_SIN_MSJ))
    {
        createFile();
        if(!openFile(&fileData,FILE_DATA,"r+b",CON_SIN_MSJ))
            return 1;
    }
    createStack(&pile);
    optionSelected = menu(MENSAJE_MENU,OPTION_MENU);
    while(optionSelected != 'x')
    {
        switch(optionSelected)
        {
        case 'a':
            {
                if(emptyStack(&pile))
                {
                    fread(&reg,1,sizeof(reg),fileData);
                    while(!feof(fileData))
                    {
                        if(putOnStack(&pile,&reg) == FULL_STACK)
                            puts("Error - Pila llena\n Asegurese de que el tamaño de la pila sea el adecuado\n para cargar el archivo");

                        fread(&reg,1,sizeof(reg),fileData);
                    }
                    showFile(&fileData);
                    fclose(fileData);
                }
                else
                    puts("Error - La pila ya fue cargada con el archivo, proceda al ingreso manual para la nueva informacion");
                break;
            }
        case 'b':
            {
                if(!fullStack(&pile))
                {
                    /**DNI**/
                    fflush(stdin);
                    printf("DNI: ");
                    scanf("%ld",&reg.dni);
                    puts("");
                    /**NAME**/
                    fflush(stdin);
                    printf("NOMBRE/s: ");
                    scanf("%s",&reg.name);
                    puts("");
                    /**SURNAME**/
                    fflush(stdin);
                    printf("APELLIDO/s: ");
                    scanf("%s",&reg.surName);
                    puts("");
                    /**AVERAGE**/
                    fflush(stdin);
                    printf("PROMEDIO/s: ");
                    scanf("%f",&reg.average);
                    puts("");

                    if(putOnStack(&pile,&reg) == FULL_STACK)
                        puts("Error - Pila llena\n Asegurese de que el tamaño de la pila sea el adecuado");
                }
                break;
            }
        case 'c':
            {
                if(showTop(&pile,&reg) == EMPTY_STACK)
                    puts("Error - Pila vacia\n Asegurese de cargar la pila con informacion antes de ingresar esta opcion");
                else
                    showData(&reg);
                break;
            }
        case 'd':
            {
                if(takeOfStack(&pile,&reg) == EMPTY_STACK)
                    puts("Error - Pila vacia\n Asegurese de cargar la pila con informacion antes de ingresar esta opcion");
                else
                {
                    puts("Bloque de informacion extraido exitosamente");
                    showData(&reg);
                }
                break;
            }
        case 'e':
            {
                if(!emptyStack(&pile))
                {
                    if(!openFile(&fileData,FILE_DATA,"wb",CON_SIN_MSJ))
                    {
                        cleanStack(&pile);
                        return 1;
                    }
                    while(takeOfStack(&pile,&reg) != EMPTY_STACK)
                        fwrite(&reg,1,sizeof(reg),fileData);
                    fclose(fileData);
                }
                break;
            }
        }
        if(optionSelected == 'e')
            optionSelected = 'x';
        else
            optionSelected = menu(MENSAJE_MENU,OPTION_MENU);
    }

    return 0;
}
