#ifndef PROTCOLA_H_INCLUDED
#define PROTCOLA_H_INCLUDED
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

typedef struct sNode
{
    tInfo info;
    struct sNode *next;
}tNode;

typedef struct
{
    tNode *first,
          *last;
}tqueue;


#endif // PROTCOLA_H_INCLUDED
