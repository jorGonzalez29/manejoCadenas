#ifndef UPDATEFILEPROTOTIPE_H_INCLUDED
#define UPDATEFILEPROTOTIPE_H_INCLUDED

#define FileEmployee "employee"
#define FileStudent  "student"
#define CON_SIM_MSJ 1
#define TAM_TABLE 20
typedef struct
{
    long dni;
    char name[51],
         surName[51];
    double salary;
}employee;

typedef struct
{
    long dni;
    char name[51],
         surName[51];
    float average;
}student;

void createFileEmployee();
void createFileEstudent();
int openFile(FILE **fp,const char *name,const char *mode,int CON_SIN);
void createTablekeyEmployee(FILE *em,long *vec);
int searchKey(const long key, long vec[]);
void updateEmployee(const int key,FILE *em);
void showFileEmployee(FILE **em);
void showEmployee(employee *d);
void showFileStudent(FILE **st);
void showStudent(student *d);

#endif // UPDATEFILEPROTOTIPE_H_INCLUDED
