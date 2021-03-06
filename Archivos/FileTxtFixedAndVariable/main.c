#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "protFileTxt.h"


int main()
{
    FILE *fpData,
         *fpDataFixed,
         *fpDataVariable,
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
        //Preguntar por %-*s
        fprintf(fpTextFixed,"%08ld%-51s%-51s%-7.2f\n",reg.dni,reg.name,reg.surName,reg.average);

        fprintf(fpTextVariable,"%ld|%-s|%-s|%.2f\n",reg.dni,reg.name,reg.surName,reg.average);

        fread(&reg,1,sizeof(reg),fpData);
    }
    if(!openFile(&fpDataFixed,FileStudentFixed,"r+b",!CON_SIN_MSJ))
    {
        if(!openFile(&fpDataFixed,FileStudentFixed,"w+b",CON_SIN_MSJ))
        {
            fclose(fpData);
            fclose(fpTextFixed);
            fclose(fpTextVariable);
            return 0;
        }
    }
    if(!openFile(&fpDataVariable,FileStudentVariable,"r+b",!CON_SIN_MSJ))
    {
        if(!openFile(&fpDataVariable,FileStudentVariable,"w+b",CON_SIN_MSJ))
        {
            fclose(fpData);
            fclose(fpTextFixed);
            fclose(fpTextVariable);
            fclose(fpDataFixed);
            return 0;
        }
    }
    while(fgets(line,sizeof(line),fpTextFixed))
    {
        if(!(aux = strchr(line,'\n')))
        {
            fprintf(stderr,"Error - No se pudo procesar archivo %s", FILE_TEXT_FIXED);
            fclose(fpData);
            fclose(fpTextFixed);
            fclose(fpTextVariable);
            fclose(fpDataFixed);
            fclose(fpDataVariable);
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

        fwrite(line,1,sizeof(line),fpDataFixed);
    }

    fclose(fpData);
    fclose(fpTextFixed);
    fclose(fpTextVariable);
    fclose(fpDataFixed);
    fclose(fpDataVariable);

    return 0;
}
