#ifndef STATICPOTOTYPEQUEUE_H_INCLUDED
#define STATICPOTOTYPEQUEUE_H_INCLUDED
#define TAM_QUEUE 21
#define EMPTY_QUEUE 0
#define O_K 1
#define FULL_QUEUE 2
#include "prototypeFile.h"
#define MESSAGE "Elija una opcion:\n A-Cargar info a la cola\nB-Ver primero en cola\nC-Sacar de la cola\nD-Salir\nOpcion:"
#define OPTIONS "abcd"

typedef struct
{
    info vecQueue[TAM_QUEUE];
    int first,
        last,
        quantity;
}Queue;

/**primitive static queue**/

void createQueue(Queue *q);
int emptyQueue(Queue *q);
int fullQueue(Queue *q);
int showFirstInQueue(Queue *q, info *d);
int putInQueue(Queue *q, const info *d);
int takeOfQueue(Queue *q, info *d);
void clearQueue(Queue *q);

/**primitive menu**/

int menu(char *msj, char *options);
#endif // STATICPOTOTYPEQUEUE_H_INCLUDED
