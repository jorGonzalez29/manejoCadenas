#include <stdio.h>
#include "protFileTxt.h"

void createFileEstudent()
{
    FILE *fp;
    student reg[] = {{87143658L, "Allende","Miguel",7.50},
                 {30589425L,"Brito","Claudio",8.00},
                 {46558892L,"Cena","Marcelo",8.90},
                 {79815612L,"Dominguez","Diego",6.89},
                 {46868278L,"Franzoi","Maximiliano",4.36},
                 {32589614L,"Herrera","Cristobal",7.50},
                 {47896425L,"Merlo","Micaela",8.55},
                 {98713469L,"Oviedo","Cesar",6.00},
                 {16887451L,"Pagnutti","Jose",8.98},
                 {91649487L,"Perez","Leandro",7.39},
                 {81659417L,"Recalde","Jose",7.28},
                 {87952123L,"Recalde","Camila",5.56},
                 {32139745L,"Rodriguez","Fabiana",7.00},
                 {97962146L,"Romero","Johana",8.78},
                 {34562501L,"Solla","Tamara",7.29},
                 {16549654L,"Sosa","Federico",4.89},
                 {66547893L,"Spinelli","Ezequiel",6.78},
                 {21656154L,"Tapia","Jorge",8.56},
                 {54514964L,"Torres","Mario",7.89},
                 {22366985L,"Vizzoni","Daniela",6.56}};

    fp = fopen(FileStudent,"wb");
    if(fp)
    {
        fwrite(reg,1,sizeof(reg),fp);
    }
    fclose(fp);
}


int openFile(FILE **file,const char *nameFile,const char *mode,int CON_SIN)
{
    *file = fopen(nameFile,mode);

    if(!*file)
    {
        if(CON_SIN)
            fprintf(stderr,"Error - No se pudo abrir el archivo %s en modo %s",nameFile,mode);
        return 0;
    }
    return 1;
}
