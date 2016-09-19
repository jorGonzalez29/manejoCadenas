#ifndef PROTFILETXT_H_INCLUDED
#define PROTFILETXT_H_INCLUDED

#define FileStudent "Data"
#define FILE_TEXT_FIXED "txtFijo"
#define FILE_TEXT_VARIABLE "txtVariable"
#define CON_SIN_MSJ 1
#define TAM_LINE 101
#define AVERAGE 3
#define SURNAME 51
#define NAME 51
#define DNI 8
#define LINE AVERAGE + SURNAME + NAME + DNI

typedef struct
{
    long dni;
    char name[51],
         surName[51];
    float average;
}student;

int openFile(FILE **file,const char *nameFile,const char *mode,int CON_SIN);
void createFileEstudent();

#endif // PROTFILETXT_H_INCLUDED
