#ifndef FILEPROTOTIPE_H_INCLUDED
#define FILEPROTOTIPE_H_INCLUDED

#define FILE_DATA "Data"
#define SIZE_NAME 51
#define SIZE_SURNAME 51
#define CON_SIN_MSJ 1
typedef struct
{
    long dni;
    char surName[SIZE_NAME],
         name[SIZE_SURNAME];
    float average;
}person, info;

void createFile();
int openFile(FILE **fp,const char *name,const char *mode,int CON_SIN);
void showFile(FILE **st);
void showData(info *d);
#endif // FILEPROTOTIPE_H_INCLUDED
