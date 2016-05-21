#include <stdio.h>
#include "protLoadFile.h"

int openFile(FILE **fp,char *mode,char *nameFile,int WITH_WITHOUT)
{
    *fp = fopen(nameFile,mode);//devuelve una direccion de memoria

    if(!*fp)
    {
        if(WITH_WITHOUT_MSSG == WITH_WITHOUT)
            fprintf(stderr,"Error-abriendo\"%s\" en modo \"%s\"\n",nameFile,mode);

        return 0;
    }

    return 1;
}

void showFileEmployee(FILE **fp)
{
   employee reg;
   long actualPos = ftell(*fp);
   rewind(*fp);
   showEmployee(NULL);
   fread(&reg,sizeof(employee),1,*fp);
   while(!feof(*fp))
   {
       showEmployee(&reg);
       fread(&reg,sizeof(employee),1,*fp);
   }
   fseek(*fp,actualPos,SEEK_SET);
}

void showEmployee(employee *p)
{
    if(p)
    {
        printf("%08ld   %-*s  %-*s  %c    %2d/%2d/%2d     %.2f        %.2f\n",
                p->dni,
                sizeof(p->surName)-1, p->surName,
                sizeof(p->firstName)-1,p->firstName,
                p->sex,
                p->fec.day,
                p->fec.month,
                p->fec.year,
                p->qualification,
                p->salary);
    }
    else
    {
        printf(" %-*s    %-*s %-*s SEXO     FECHA    CALIFICACION   SUELDO\n",sizeof(p->dni),"D.N.I",sizeof(p->surName),"APELLIDO(S)",sizeof(p->firstName),"NOMBRE(S)");
    }
}


void createFileEmployee()
{
    FILE *file = fopen(FileUpdate,"wb");
    employee vec[] = {{87143658L, "Allende","Miguel",'M',{12,03,1996},7.5,9000},
                      {30589425L,"Brito","Claudio",'M',{4,9,2002},8,9000},
                      {46558892L,"Cena","Marcelo",'M',{23,12,1990},8.9,9000},
                      {79815612L,"Dominguez","Diego",'M',{21,01,1990},6.89,9000},
                      {46868278L,"Franzoi","Maximiliano",'M',{22,01,1990},4.36,5000},
                      {32589614L,"Herrera","Cristobal",'M',{5,11,2003},7.5,5000},
                      {47896425L,"Merlo","Micaela",'F',{24,02,1990},8.55,7000},
                      {98713469L,"Oviedo","Cesar",'M',{9,03,2004},6,5000},
                      {16887451L,"Pagnutti","Jose",'M',{26,04,1992},8.98,3000},
                      {91649487L,"Perez","Leandro",'M',{27,05,1993},7.39,3000},
                      {81659417L,"Recalde","Jose",'M',{28,06,1993},7.28,3000},
                      {87952123L,"Recalde","Camila",'F',{29,07,1993},5.56,3000},
                      {32139745L,"Rodriguez","Fabiana",'F',{30,8,1993},7,9000},
                      {97962146L,"Romero","Johana",'F',{3,8,1993},8.78,6000},
                      {34562501L,"Solla","Tamara",'F',{13,03,1993},7.29,6000},
                      {16549654L,"Sosa","Federico",'M',{5,03,1993},4.89,6000},
                      {66547893L,"Spinelli","Ezequiel",'M',{6,01,1994},6.78,6000},
                      {21656154L,"Tapia","Jorge",'M',{7,05,1995},8.56,6000},
                      {54514964L,"Torres","Mario",'M',{8,06,1996},7.89,9000},
                      {22366985L,"Vizzoni","Daniela",'F',{9,07,1997},6.56,9000}};
    if(file)
        fwrite(vec,1,sizeof(vec),file);
    fclose(file);
}

/*recorre el archivo apuntado por **fp, para crar una tabla
de valores, referenciado por vec.*/
void createTableOfKey(FILE **fp,long vec[],int *sizeV)
{
    employee reg;
    int i = 0;
    long acPosition = ftell(*fp);
    rewind(*fp);

    fread(&reg,1,sizeof(employee),*fp);
    while(!feof(*fp))
    {
        vec[i] = reg.dni;                  //Podria hacer que el vector tome memoria en ejecucion segun la cantidad de reg. ingresados
        i ++;
        fread(&reg,1,sizeof(employee),*fp);
    }
    *sizeV = i - 1;

    fseek(*fp,acPosition,SEEK_SET);
}

/*retorna la posicion del registro buscado dentro
 del archivo, según una tabla de valores(vec).*/
int searchBuyKey(long vec[],int *sizeV)
{
    long dni;
    int posReg;
    puts("Ingrese el D.N.I del empleado a buscar:");
    printf("D.N.I: ");
    fflush(stdin);
    scanf("%ld",&dni);

//    while(low <= high)
//    {
//        centralV = CENTRALVALUE(low,high);
//        if(vec[centralV] == dni)
//            return centralV;
//        else
//        {
//            if(dni < vec[centralV])
//                high = centralV - 1;
//            else
//                low = centralV + 1;
//        }
//    }

    while(posReg <= *sizeV && vec[posReg] != dni)
    {
        posReg ++;
    }

    return (posReg <= *sizeV) ? posReg : -1;
}

//Se posiciona y modifica el registro definido por posReg dentro del archivo fp.
void changeBuyKey(FILE **fp,int posReg)
{
    employee reg;
    long actPosition = ftell(*fp); // m devuelve -1
    rewind(*fp);

    fseek(*fp,posReg * sizeof(employee),SEEK_SET);
    fread(&reg,1,sizeof(employee),*fp);
    reg.salary *= 1.103;
    fseek(*fp,-1L * sizeof(employee),SEEK_CUR);

    fwrite(&reg,1,sizeof(employee),*fp);
    fseek(*fp,actPosition,SEEK_SET);
}
