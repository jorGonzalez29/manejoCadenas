#ifndef PROTLIST_H_INCLUDED
#define PROTLIST_H_INCLUDED
#define COMPEARDATE(A,B,C,D,E,F) ((A)-(B) == 0 ? ((C)-(D) == 0 ? (E)-(F): (C)-(D)):(A)-(B))
#define compear compearByNameSurnameSexDateDni
#define upDate upDateSalary
#define O_K 0
#define DUPLICATE_KEY 1
#define NO_MEMORY 2
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
//Cola estatica
typedef struct sNode
{
    tInfo info;
    sNode *next;
}tNode, *List;


#endif // PROTLIST_H_INCLUDED
