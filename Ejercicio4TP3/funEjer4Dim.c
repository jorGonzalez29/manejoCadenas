#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>
#include "protEjer4.h"

void createStack(Pile *p)
{
    *p = NULL;
}

int isStackEmpty(Pile *p)
{
    return *p == NULL;
}

int isStackFull(Pile *p)
{
    void *aux = malloc(sizeof(tNode));
    free(aux);
    return aux == NULL;
}
int putInStack(Pile *p,const tInfo *d)
{
    tNode *newNode = (tNode*) malloc(sizeof(tNode));
    if(newNode == NULL)
        return PILA_LLENA;
    newNode->info = *d;
    newNode->next = *p;
    *p = newNode;
    return O_K;
}

int takeOfStack(Pile *p,tInfo *d)
{
    tNode *aux;
    if(*p == NULL)
        return PILA_VACIA;
    aux = *p;
    *d = aux->info;
    *p = aux->next;
    free(aux);
    return O_K;
}

int showTop(Pile *p,tInfo *d)
{
    if(*p == NULL)
        return PILA_VACIA;
    *d = (*p)->info;
    return O_K;
}
void emptyStack(Pile *p)
{
    tNode *aux;
    if(*p != NULL)
    {
         while(*p)
        {
            aux = *p;
            p = &(*p)->next;
            free(aux);
        }
    }
}
void createFile()
{
    FILE *file = fopen(FILENAME,"w+b");
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
    if(file)
        fwrite(vec,1,sizeof(vec),file);
    showFile(&file);
    fclose(file);
}
void newInfo(tInfo *d)
{
    puts("\t\t\t\tIngrese nueva informacion");
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
int openFile(FILE **fp, char *mode, char *nameFile, int CON_SIN)
{
    *fp = fopen(nameFile,mode);

    if(!*fp)
    {
        if(CON_SIN)
        {
            fprintf(stderr,"No se a podido abrir el archivo %s en modo %s",nameFile,mode);
        }
        return 0;
    }
    return 1;
}

char menuOption(const char *msj,const char *options)
{
    char op;
    puts(msj);
    do
    {
        fflush(stdin);
        scanf("%c",&op);
        op = toupper(op);
    }while(!strchr(options,op));

    return op;
}

void showFile(FILE **fp)
{
    long posAct = ftell(*fp);
    tInfo info;
    rewind(*fp);
    fread(&info,1,sizeof(tInfo),*fp);
    while(!feof(*fp))
    {
        showInfo(&info);
        fread(&info,1,sizeof(tInfo),*fp);
    }
    fseek(*fp,posAct,SEEK_SET);
}
 void showInfo(tInfo *p)
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

void putInTheEndFile(FILE **fp, tInfo *d)
{

    fseek(*fp,0L,SEEK_END);
    fwrite(d,1,sizeof(tInfo),*fp);
    fseek(*fp,0L,SEEK_END);
}
