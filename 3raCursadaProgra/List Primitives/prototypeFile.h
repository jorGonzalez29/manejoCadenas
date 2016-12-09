#ifndef PROTOTYPEFILE_H_INCLUDED
#define PROTOTYPEFILE_H_INCLUDED
#define SIZE_NAME 51
#define SIZE_SURNAME 51
#define FILE_NAME "dataFile"
#define MESSAGE_OR_NOT 1
typedef struct
{
    long dni;
    char surName[SIZE_NAME],
         name[SIZE_SURNAME];
    float average;
}person, info;

/** primitive functions FILE **/
void createFile();
int openFile(FILE **fp, const char *nameFile, const char *mode, int MESSAGE);
void showFile(FILE **fp);
void showData(info *d);

#endif // PROTOTYPEFILE_H_INCLUDED
