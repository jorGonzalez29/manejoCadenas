#ifndef PROTLOADFILE_H_INCLUDED
#define PROTLOADFILE_H_INCLUDED
#define WITH_WITHOUT_MSSG 1
#define CENTRALVALUE(X,Y) (( X + Y) / 2)
#define FileUpdate "employee"
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
}employee;

int openFile(FILE **fp,char *mode,char *nameFile,int WITH_WITHOUT);
void showFileEmployee(FILE **fp);
void showEmployee(employee *p);
void createFileEmployee();
void createTableOfKey(FILE **fp,long *vec,int *sizeV);
int searchBuyKey(long vec[],int *sizeV);
void changeBuyKey(FILE **fp,int posReg);

#endif // PROTLOADFILE_H_INCLUDED
