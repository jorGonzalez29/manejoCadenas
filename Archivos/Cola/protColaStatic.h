#ifndef PROTCOLASTATIC_H_INCLUDED
#define PROTCOLASTATIC_H_INCLUDED
#define TAM_COLA 5
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
}person, tInfo;
//Cola estatica
typedef struct
{
    tInfo train[TAM_COLA];
    int first,
        last,
        quantity;
}tqueue;

void createTrain(const tqueue *p);
int queueFull(const tqueue *p);
int queueEmpty(const tqueue *p);
int pushInqueue(const tqueue *p, tInfo *d);
int pullOfQueue(const tqueue *p, tInfo *d);
int showFirstInQueue(const tqueue *p, tInfo *d);
void emptyQueue(const tqueue *p);

#endif // PROTCOLASTATIC_H_INCLUDED
