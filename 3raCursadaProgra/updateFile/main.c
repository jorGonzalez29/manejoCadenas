#include <stdio.h>
#include <stdlib.h>
#include "updateFilePrototipe.h"

int main()
{
    FILE *fpEmployee,
         *fpStudent;
    student regStud;
    long tableKey[20];

    printf("Test Update File\n");

    if(!openFile(&fpStudent,FileStudent,"r+b",!CON_SIM_MSJ))
    {
        createFileEstudent();
        if(!openFile(&fpStudent,FileStudent,"r+b",CON_SIM_MSJ))
            return 1;
    }
    if(!openFile(&fpEmployee,FileEmployee,"r+b",!CON_SIM_MSJ))
    {
        createFileEmployee();
        if(!openFile(&fpEmployee,FileEmployee,"r+b",CON_SIM_MSJ))
        {
           fclose(fpStudent);
           return 1;
        }
    }

    createTablekeyEmployee(fpEmployee,tableKey);
    showFileStudent(&fpStudent);
    showFileEmployee(&fpEmployee);

    fread(&regStud,1,sizeof(regStud),fpStudent);
    while(!feof(fpStudent))
    {
        if(regStud.average >= 7)
            updateEmployee(searchKey(regStud.dni,tableKey),fpEmployee);

        fread(&regStud,1,sizeof(regStud),fpStudent);
    }
    fseek(fpStudent,0L,SEEK_SET);

    showFileStudent(&fpStudent);
    showFileEmployee(&fpEmployee);

    fclose(fpStudent);
    fclose(fpEmployee);
    return 0;
}
