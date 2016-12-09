#include <stdio.h>
#include "filePrototipe.h"

void createFile()
{
    FILE *fp;
    info reg[] = {{87143658L, "Allende","Miguel",7.5},
                 {30589425L,"Brito","Claudio",8},
                 {46558892L,"Cena","Marcelo",8.9},
                 {79815612L,"Dominguez","Diego",6.89},
                 {46868278L,"Franzoi","Maximiliano",4.36},
                 {32589614L,"Herrera","Cristobal",7.5},
                 {47896425L,"Merlo","Micaela",8.55},
                 {98713469L,"Oviedo","Cesar",6},
                 {16887451L,"Pagnutti","Jose",8.98},
                 {91649487L,"Perez","Leandro",7.39},
                 {81659417L,"Recalde","Jose",7.28},
                 {87952123L,"Recalde","Camila",5.56},
                 {32139745L,"Rodriguez","Fabiana",7},
                 {97962146L,"Romero","Johana",8.78},
                 {34562501L,"Solla","Tamara",7.29},
                 {16549654L,"Sosa","Federico",4.89},
                 {66547893L,"Spinelli","Ezequiel",6.78},
                 {21656154L,"Tapia","Jorge",8.56},
                 {54514964L,"Torres","Mario",7.89},
                 {22366985L,"Vizzoni","Daniela",6.56}};


    fp = fopen(FILE_DATA,"wb");
    if(fp)
    {
        fwrite(reg,1,sizeof(reg),fp);
    }
    fclose(fp);
}

int openFile(FILE **fp,const char *name,const char *mode,int CON_SIN)
{
    *fp = fopen(name,mode);

    if(!*fp)
    {
        if(CON_SIN)
            fprintf(stderr,"No se pudo abrir %s, en modo %s",name,mode);
        return 0;
    }
    return 1;
}

void showFile(FILE **st)
{
    info reg;
    long actualPos = ftell(*st);
    rewind(*st);
    fread(&reg,1,sizeof(reg),*st);
    showData(NULL);
    while(!feof(*st))
    {
       showData(&reg);
       fread(&reg,1,sizeof(reg),*st);
    }

    fseek(*st,actualPos,SEEK_SET);
}

void showData(info *d)
{
    if(!d)
        printf("DNI        NOMBRE          APELLIDO       PROMEDIO\n");
    else
        printf("%ld        %s               %s            %f\n",d->dni,d->surName,d->name,d->average);
}
