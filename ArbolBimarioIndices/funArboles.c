#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <math.h>
#include <stdlib.h>
#include "protArboles.h"
//Funciones de archivos
void createFile()
{
    FILE *fp = fopen(nameFile,"w+b");
    tInfo vec[] = {{87143658L, "Allende","Miguel",'M',{12,03,1996},7.5,9000},
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
    if(fp)
        fwrite(vec,1,sizeof(vec),fp);
    fclose(fp);
}
int openFile(FILE**fp, char *mod, char *File, int CON_MSJ)
{
    *fp = fopen(File,mod);
    if(!*fp)
    {
        if(CON_MSJ)
            fprintf(stderr,"No se pudo abrir el archivo \%s\ en modo %s",File,mod);
        return 0;
    }
    return 1;
}
void showFile(FILE **fp)
{
    long posAct = ftell(*fp);
    tInfo reg;
    rewind(*fp);
    fread(&reg,1,sizeof(reg),*fp);
    while(!feof(*fp))
    {
        showInfo(&reg);
        fread(&reg,1,sizeof(reg),*fp);
    }
    fseek(*fp,posAct,SEEK_SET);
}
void showInfo(tInfo *d)
{
    if(d)
    {
        printf("%08ld   %-*s  %-*s  %c    %2d/%2d/%2d     %.2f        %.2f\n",
                d->dni,
                sizeof(d->surName)-1, d->surName,
                sizeof(d->firstName)-1,d->firstName,
                d->sex,
                d->fec.day,
                d->fec.month,
                d->fec.year,
                d->qualification,
                d->salary);
    }
    else
    {
        printf(" %-*s    %-*s %-*s SEXO     FECHA    CALIFICACION   SUELDO\n",sizeof(d->dni),"D.N.I",sizeof(d->surName),"APELLIDO(S)",sizeof(d->firstName),"NOMBRE(S)");
    }
}

void putAtTheEnd(FILE **fp,tInfo *d)
{
    long posAct = ftell(*fp);
    fseek(*fp,0,SEEK_END);
    fwrite(d,1,sizeof(tInfo),*fp);
    fseek(*fp,posAct,SEEK_SET);
}

char menuOption(char *msj,char *option)
{
    char op;
    puts(msj);
    do{
        scanf("%c",&op);
    }while(!strchr(option,toupper(op)));

    return toupper(op);
}
void newInfo(tInfo *d)
{
    puts("\t\t\t\t\tIngrese los campos a guardar");
    fflush(stdin);
    printf("DNI:");
    scanf("%ld",&d->dni);
    fflush(stdin);
    printf("Nombre/s:");
    gets(d->firstName);
    printf("Apellido:");
    gets(d->surName);
    printf("Sexo:");
    scanf("%c",&d->sex);
    printf("Fecha:");
    scanf("%2d/%2d/%4d",&d->fec.day,&d->fec.month,&d->fec.year);
    fflush(stdin);
    printf("Calificacion:");
    scanf("%f",&d->qualification);
    fflush(stdin);
    printf("Salario:");
    scanf("%f",&d->salary);
}
//Funciones de arboles

void createTree(Arbol *p)
{
    *p = NULL;
}

int isTreeEmpty(Arbol *p)
{
    return *p == NULL;
}
int isTreeFull(Arbol *p)
{
    void *aux = malloc(sizeof(tNode));
    free(aux);

    return aux == NULL;
}
int putInTree(Arbol *p,tInfo *d,int *cont, int (*compear)(long*,long*))
{
    tNode *newNode;
    while(*p)
    {
        int cmp = compear(&(*p)->dni,&d->dni);

        if(!cmp)
            return CLAV_DUP; //tener en cuenta cuando no se debe agregar al arbol ni en el archiivo
        if(cmp < 0)
            p = &(*p)->rigth;
        else
            p = &(*p)->left;
    }
    newNode = (tNode*) malloc(sizeof(tNode));
    if(newNode == NULL)
        return SIN_MEM;
    newNode->reg = (*cont) ++;
    newNode->dni = d->dni;
    newNode->left = NULL;
    newNode->rigth = NULL;
    *p = newNode;
    return O_K;
}

int compearByDni(long *d1, long *d2)
{
    return *d1 - *d2;
}
int searchInTree(Arbol *p, tInfo *d, int (*compear)(long*,long*))
{
    if(*p)
    {
        int cmp = compear(&(*p)->dni,&d->dni);
        if(!cmp)
            return (*p)->reg;
        if(cmp < 0)
            return searchInTree(&(*p)->rigth,d,compear);
        else
            return searchInTree(&(*p)->left,d,compear);
    }
    return -1;
}

void order(Arbol *p,FILE **fp)
{
    if(*p)
    {
        order(&(*p)->left,fp);
        showInfoByKey(fp,(*p)->reg);
        order(&(*p)->rigth,fp);
    }
}
void preOrder(Arbol *p,FILE **fp)
{
    if(*p)
    {
        showInfoByKey(fp,(*p)->reg);
        preOrder(&(*p)->left,fp);
        preOrder(&(*p)->rigth,fp);
    }
}
void posOrder(Arbol *p,FILE **fp)
{
    if(*p)
    {
        posOrder(&(*p)->left,fp);
        posOrder(&(*p)->rigth,fp);
        showInfoByKey(fp,(*p)->reg);
    }
}
void showInfoByKey(FILE **fp, int key)
{
    tInfo reg;
    if(key > 0)
    {
        fseek(*fp,key * 1L * sizeof(tInfo),SEEK_SET);
        fread(&reg,1,sizeof(tInfo),*fp);
        showInfo(&reg);
    }
    else
        puts("clave no encontrada");
}
void emptyTree(Arbol *p)//en posOrden
{
    if(*p)
    {
        emptyTree(&(*p)->left);
        emptyTree(&(*p)->rigth);
        free(*p);
    }
}

int countingNodes(Arbol *p)
{
    if(*p)
        return countingNodes(&(*p)->rigth) + countingNodes(&(*p)->left) + 1;
    return 0;
}
int sheetsCounting(Arbol *p)
{
    if(*p)
    {
        if((*p)->rigth == (*p)->left)
            return 1;
        return sheetsCounting(&(*p)->rigth) + sheetsCounting(&(*p)->left);
    }
    return 0;
}
int heigthTree(Arbol *p)
{
    if(*p)
    {
        int heigthRigth = heigthTree(&(*p)->rigth);
        int heigthLeft = heigthTree(&(*p)->left);

        return heigthRigth > heigthLeft ? heigthRigth + 1 : heigthLeft + 1;
    }
    return 0;
}
int completeTree(Arbol *p)
{
        return pow(2,heigthTree(p)) == countingNodes(p);
}
int balancedTree(Arbol *p)
{
    if(*p)
    {
        if(heigthTree(p) == 2)
            return 1;
        return balancedTree(&(*p)->rigth) && balancedTree(&(*p)->left);
    }
    return 0;
}
int isAVL(Arbol *p)
{
    if(*p)
    {
        if(abs(heigthTree(&(*p)->rigth) - heigthTree(&(*p)->left)) <= 1)
            return 1;
        return isAVL(&(*p)->rigth) && isAVL(&(*p)->left);
    }
    return 0;
}
