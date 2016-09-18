#ifndef PROTEJERCICIO4COLASTAC_H_INCLUDED
#define PROTEJERCICIO4COLASTAC_H_INCLUDED
#define TAM_COLA 51
#define COLA_LLENA 2
#define COLA_VACIA 1
#define O_K 0

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

typedef struct
{
    tInfo info[TAM_COLA];
    int pri,
        ult,
        cant;
}Queue;

void createQueue(Queue *q);
int isQueueEmpty(const Queue *q);
int isQueueFull(const Queue *q);
int putInQueue(Queue *q, const tInfo *d);
int takeOfQueue(Queue *q, tInfo *d);
int showFirstInQueue(const Queue *q, tInfo *d);
void emptyQueue(Queue *q);

#endif // PROTEJERCICIO4COLASTAC_H_INCLUDED
