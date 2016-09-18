#ifndef PROTEJER4_H_INCLUDED
#define PROTEJER4_H_INCLUDED
#define TAM_VEC 51
#define PILA_LLENA 1
#define PILA_VACIA 2
#define O_K 0
#define FILENAME "Datos"
#define CON_SIN_MSJ 1
#define MSJ "Por favor ingrese una opcion \n A-Cargar info a la pila \n B-Ver tope de pila \n C-Sacar de la pila \n D-Salir"
#define OPTION "ABCD"
typedef struct
{
    int day,
        month,
        year;
}date;

typedef struct
{
    long dni;
    char surName[50],
         firstName[50],
         sex;
    date fec;
    float qualification;
    float salary;
}employee, tInfo;
/*
typedef struct
{
    tInfo vec [TAM_VEC];
    int tope;
}Pile;*/

typedef struct sNode
{
    tInfo info;
    struct sNode *next;
}tNode, *Pile;

//Manejo Pila
void createStack(Pile *p);
int isStackEmpty(Pile *p);
int isStackFull(Pile *p);
int putInStack(Pile *p, const tInfo *d);
int takeOfStack(Pile *p, tInfo *d);
int showTop(Pile *p, tInfo *d);
void emptyStack(Pile *p);

//Manejo Archivos
void createFile();
int openFile(FILE **fp, char *mode, char *nameFile, int CON_SIN);
void showFile(FILE **fp);
void showInfo(tInfo *p);
void putInTheEndFile(FILE **fp, tInfo *d);
char menuOption(const char *msj,const char *options);
void newInfo(tInfo *d);
#endif // PROTEJER4_H_INCLUDED
