#ifndef PROTPILADIM_H_INCLUDED
#define PROTPILADIM_H_INCLUDED
#define TAM_PILA 30
#define MSJ "Ingrese opcion a procesar \n A- Cargar informacion a pila\n B-Ver tope de pila\n C-Sacar de la pila\n D-Salir"
#define OPTIONS "ABCD"
#define CON_SIN_MSJ 1
#define DATOS "datos"

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
}person, tInfo;

typedef struct
{
    tInfo pila[TAM_PILA];
    int top;
}tPile;
void createStack(tPile *p);
int fullStack(tPile *p);
int pushingOnStack(tPile *p, tInfo *d);
int showTop(tPile *p, tInfo *d);
int takeOfStack(tPile *p, tInfo *d);
int ifEmptyStack(tPile *p);
void emptyStack(tPile *p);
//Manejo de Archivos
void createFile();
int openFile(FILE **fp,char *nameFile,char *mode,int CON_SIN);
char menu(char *msj,char *options);
void showFile(FILE **fp);
void showData(person *p);


#endif // PROTPILADIM_H_INCLUDED
