#ifndef QUEUEDINAMICPROTOTIPE_H_INCLUDED
#define QUEUEDINAMICPROTOTIPE_H_INCLUDED

#define SIZE_NAME 51
#define SIZE_SURNAME 51
#define EMPTY_QUEUE 0
#define FULL_QUEUE 1
#define O_K 2

typedef struct
{
    long dni;
    char name[SIZE_NAME],
         surName[SIZE_SURNAME];
    float average;
}person, info;

typedef struct node
{
    info data;
    struct node *next;
}node;

typedef struct
{
    node *first,
         *last;
}tQueue;

void createQueue(tQueue *q);
int emptyQueue(tQueue *q);
int fullQueue(tQueue *q);
int showFirstOnQueue(tQueue *q, info *d);
int putOnQueue(tQueue *q, info *d);
int takeOfQueue(tQueue *q, info *d);
void clearQueue(tQueue *q);

#endif // QUEUEDINAMICPROTOTIPE_H_INCLUDED
