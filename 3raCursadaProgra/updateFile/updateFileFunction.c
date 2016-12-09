#include <stdio.h>
#include "updateFilePrototipe.h"

void createFileEmployee()
{
    FILE *fp;
    employee reg[] = {{87143658L, "Allende","Miguel",7000},
                 {30589425L,"Brito","Claudio",8000},
                 {46558892L,"Cena","Marcelo",9005},
                 {79815612L,"Dominguez","Diego",6000},
                 {46868278L,"Franzoi","Maximiliano",4500},
                 {32589614L,"Herrera","Cristobal",7500},
                 {47896425L,"Merlo","Micaela",8055},
                 {98713469L,"Oviedo","Cesar",6750},
                 {16887451L,"Pagnutti","Jose",8980},
                 {91649487L,"Perez","Leandro",7039},
                 {81659417L,"Recalde","Jose",7828},
                 {87952123L,"Recalde","Camila",5556},
                 {32139745L,"Rodriguez","Fabiana",7236},
                 {97962146L,"Romero","Johana",8356},
                 {34562501L,"Solla","Tamara",7429},
                 {16549654L,"Sosa","Federico",4089},
                 {66547893L,"Spinelli","Ezequiel",6678},
                 {21656154L,"Tapia","Jorge",8756},
                 {54514964L,"Torres","Mario",7489},
                 {22366985L,"Vizzoni","Daniela",6456}};

    fp = fopen(FileEmployee,"wb");
    if(fp)
    {
        fwrite(reg,1,sizeof(reg),fp);
    }
    fclose(fp);
}

void createFileEstudent()
{
    FILE *fp;
    student reg[] = {{87143658L, "Allende","Miguel",7.5},
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


    fp = fopen(FileStudent,"wb");
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

void createTablekeyEmployee(FILE *em,long *vec)
{
    employee reg;
    long actualPos = ftell(em);

    fread(&reg,1,sizeof(reg),em);
    while(!feof(em) && vec)
    {
        *vec = reg.dni;
        vec ++;
        fread(&reg,1,sizeof(reg),em);
    }
    fseek(em,actualPos,SEEK_SET);
}

int searchKey(const long key, long vec[])
{
    int i = 0;
    while(vec[i] != key && i < TAM_TABLE)
    {
        i ++;
    }
    return vec ? i : -1;
}

void updateEmployee(const int key,FILE *em)
{
    employee reg;

    fseek(em,key * (long)sizeof(employee),SEEK_SET);
    fread(&reg,1,sizeof(reg),em);
    reg.salary *= 1.728;
    fseek(em,key * (long)sizeof(employee),SEEK_SET);
    fwrite(&reg,1,sizeof(reg),em);
    fseek(em,0L,SEEK_SET);
}

void showFileEmployee(FILE **em)
{
    employee reg;
    long actualPos = ftell(*em);

    fread(&reg,1,sizeof(reg),*em);
    showEmployee(NULL);
    while(!feof(*em))
    {
       showEmployee(&reg);
       fread(&reg,1,sizeof(reg),*em);
    }

    fseek(*em,actualPos,SEEK_SET);
}

void showEmployee(employee *d)
{
    if(!d)
        printf("DNI        NOMBRE          APELLIDO       SUELDO\n");
    else
        printf("%ld        %s               %s            %lf\n",d->dni,d->name,d->surName,d->salary);
}

void showFileStudent(FILE **st)
{
    student reg;
    long actualPos = ftell(*st);

    fread(&reg,1,sizeof(reg),*st);
    showStudent(NULL);
    while(!feof(*st))
    {
       showStudent(&reg);
       fread(&reg,1,sizeof(reg),*st);
    }

    fseek(*st,actualPos,SEEK_SET);
}

void showStudent(student *d)
{
    if(!d)
        printf("DNI        NOMBRE          APELLIDO       PROMEDIO\n");
    else
        printf("%ld        %s               %s            %f\n",d->dni,d->name,d->surName,d->average);
}
