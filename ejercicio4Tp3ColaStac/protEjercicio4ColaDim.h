#ifndef PROTEJERCICIO4COLADIM_H_INCLUDED
#define PROTEJERCICIO4COLADIM_H_INCLUDED
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

typedef struct sNode
{
    tInfo info;
    struct sNode *next;
}sNode;

typedef struct
{
    sNode *first,
          *last;
}Queue;

void createQueue(Queue *q);
int isQueueEmpty(const Queue *q);
int isQueueFull(const Queue *q);
int putInQueue(Queue *q, const tInfo *d);
int takeOfQueue(Queue *q, tInfo *d);
int showFirstInQueue(const Queue *q, tInfo *d);
void emptyQueue(Queue *q);

#endif // PROTEJERCICIO4COLADIM_H_INCLUDED
