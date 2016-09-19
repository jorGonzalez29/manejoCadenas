#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "protFileTxt.h"


int main()
{
    FILE *fpData,
         *fpTextFixed,
         *fpTextVariable;
    student reg;
    char line[LINE],
         *aux;

    printf("\t\t\t\t Test File txt!\n");

    if(!openFile(&fpData,FileStudent,"r+b",!CON_SIN_MSJ))
    {
        createFileEstudent();
        if(!openFile(&fpData,FileStudent,"r+b",CON_SIN_MSJ))
            return 0;
    }
    if(!openFile(&fpTextFixed,FILE_TEXT_FIXED,"r+t",!CON_SIN_MSJ))
    {
        if(!openFile(&fpTextFixed,FILE_TEXT_FIXED,"w+t",CON_SIN_MSJ))
        {
            fclose(fpData);
            return 0;
        }
    }
    if(!openFile(&fpTextVariable,FILE_TEXT_VARIABLE,"r+t",!CON_SIN_MSJ))
    {
        if(!openFile(&fpTextVariable,FILE_TEXT_VARIABLE,"w+t",CON_SIN_MSJ))
        {
            fclose(fpData);
            fclose(fpTextFixed);
            return 0;
        }
    }

    fread(&reg,1,sizeof(reg),fpData);
    while(!feof(fpData))
    {
        fprintf(fpTextFixed,"%08ld%-*s%-*s%2.2f\n",reg.dni,reg.name,reg.surName,reg.average);

        fprintf(fpTextVariable,"%ld|%-*s|%-*s|%f\n",reg.dni,reg.name,reg.surName,reg.average);

        fread(&reg,1,sizeof(reg),fpData);
    }

    while(fgets(line,LINE,fpTextFixed))
    {
        if(aux = strchr(line,'\n'))
        {
            fclose(fpData);
            fclose(fpTextFixed);
            fclose(fpTextVariable);
            return 0;
        }
        *aux = '\0';

        //TODO: funcion para verificar los campos de los registros leidos por fgets

        /** promedio alumno **/
        aux -= AVERAGE;
        sscanf(aux,"%f",&reg.average);
        *aux = '\0';
        /** apellido alumno **/
        aux -= SURNAME;
        sscanf(aux,"%s",&reg.surName);
        *aux = '\0';
        /** nombre alumno **/
        aux -= NAME;
        sscanf(aux,"%s",&reg.name);
        *aux = '\0';
        /** dni alumno **/
        aux -= DNI;
        sscanf(aux,"%ld",&reg.dni);
        *aux = '\0';

        //TODO: escribir un 2do archivo binario para archivo de txt de longitud fija
    }

    fclose(fpData);
    fclose(fpTextFixed);
    fclose(fpTextVariable);

    return 0;
}
