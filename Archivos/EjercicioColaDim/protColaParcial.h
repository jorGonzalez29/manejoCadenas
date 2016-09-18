#ifndef PROTCOLAPARCIAL_H_INCLUDED
#define PROTCOLAPARCIAL_H_INCLUDED
#define DATA "Pasajeros sin asignar"
#define CON_SIN_MSJ 1
#define EVENTOS "SA*"
#define DNI_VALIDO(X) (X) < 2000000
typedef struct
{
    char eventCod;
    long id;
}passengers, tInfo;

typedef struct sNode
{
    tInfo info;
    struct sNode *next;
}tNode;

typedef struct
{
    tNode *first,
          *last;
}tQueue;
//Primitivas de pila
void createQueue(tQueue *p);
int queueEmpty(tQueue *p);
int queueFull(tQueue *p);
int pushingInQueue(tQueue *p, tInfo *d);
int takeOfQueue(tQueue *p, tInfo *d);
int showFirstInQueue(tQueue *p, tInfo *d);
void emptyQueue(tQueue *p);

//Manejo de archivos
int openFile(FILE **fp,char *nameFile,char *mode, int CON_SIN);
void showFile(FILE **fp);
void showData(tInfo *d);

#endif // PROTCOLAPARCIAL_H_INCLUDED
