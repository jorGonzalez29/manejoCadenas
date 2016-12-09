#include <stdio.h>
#include <stdlib.h>
#include "StaticPototypeQueue.h"

int main()
{
    FILE *fp;
    info reg;
    char option;
    Queue q;
    printf("Prueba cola estatica\n");

    if(!openFile(&fp,FILE_NAME,"r+b",!MESSAGE_OR_NOT))
    {
        createFile();
        if(!openFile(&fp,FILE_NAME,"r+b",MESSAGE_OR_NOT))
            return 1;
    }
    createQueue(&q);
    fread(&reg,1,sizeof(info),fp);
    while(!feof(fp))
    {
        putInQueue(&q,&reg);
        fread(&reg,1,sizeof(info),fp);
    }
    fseek(fp,0L,SEEK_SET);
    showFile(&fp);

    option = menu(MESSAGE,OPTIONS);
    while(option != 'd')
    {
        switch(option)
        {
        case 'a':
            {
                /**DNI**/
                printf("DNI:");
                fflush(stdin);
                scanf("%08ld",&reg.dni);
                /**APELLIDO**/
                printf("APELLIDO:");
                fflush(stdin);
                scanf("%s",reg.surName);
                /**NOMBRE**/
                printf("NOMBRE:");
                fflush(stdin);
                scanf("%s",reg.name);
                /**PROMEDIO**/
                printf("PROMEDIO:");
                fflush(stdin);
                scanf("%f",&reg.average);

                if(putInQueue(&q,&reg) ==  FULL_QUEUE)
                    puts("Sin memoria");
                break;
            }
        case 'b':
            {
                if(showFirstInQueue(&q,&reg) == EMPTY_QUEUE)
                    puts("Cola vacia");
                else
                    showData(&reg);
                break;
            }
        case 'c':
            {
                if(takeOfQueue(&q,&reg) == EMPTY_QUEUE)
                    puts("Cola vacia");
                else
                {
                    puts("Nodo removido de la cola");
                    showData(&reg);
                }
                break;
            }
        }

        option = menu(MESSAGE,OPTIONS);
    }

    while(takeOfQueue(&q, &reg) != EMPTY_QUEUE)
        fwrite(&reg,1,sizeof(reg),fp);
    showFile(&fp);
    fclose(fp);
    clearQueue(&q);

    return 0;
}
