#include <stdio.h>
#include "prototypeFile.h"

void createFile()
{
    FILE *fp = fopen(FILE_NAME,"wb");
    info vec[] = {{87143658L, "Allende","Miguel",7.5},
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
     if(fp)
         fwrite(vec,1,sizeof(vec),fp);

     fclose(fp);
}

int openFile(FILE **fp, const char *nameFile, const char *mode, int MESSAGE)
{
    *fp = fopen(nameFile, mode);

    if(!*fp)
    {
        if(MESSAGE)
        {
            fprintf(stderr, "Error - Error al intentar abrir %s, en modo %s", nameFile, mode);
        }
        return 0;
    }
    return 1;
}

void showFile(FILE **fp)
{
    long actPos = ftell(*fp);
    info reg;
    rewind(*fp);

    fread(&reg,1,sizeof(info),*fp);
    showData(NULL);
    while(!feof(*fp))
    {
        showData(&reg);
        fread(&reg,1,sizeof(info),*fp);
    }
    fseek(*fp,actPos,SEEK_SET);
}

void showData(info *d)
{
    if(!d)
    {
        printf("DNI      APELLIDO              NOMBRE              PROMEDIO\n");
    }
    else
    {
        printf("%08ld         %s                 %s              %2.2f\n", d->dni, d->surName, d->name, d->average);
    }
}
