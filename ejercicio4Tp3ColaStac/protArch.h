#ifndef PROTARCH_H_INCLUDED
#define PROTARCH_H_INCLUDED
#define MSJ "Por favor ingrese una opcion: \n A-Cargar info a la cola \n B-Ver primero en cola \n C-Sacar de cola \n D-Salir"
#define OPTION "ABCD"
#define CON_SIN_MSJ 1
#define FILENAME "Datos"
#include "protEjercicio4ColaDim.h"
//Manejo Archivos
void createFile();
int openFile(FILE **fp, char *mode, char *nameFile, int CON_SIN);
void showFile(FILE **fp);
void showInfo(tInfo *p);
void putInTheEndFile(FILE **fp, tInfo *d);
char menuOption(const char *msj,const char *options);
void newInfo(tInfo *d);


#endif // PROTARCH_H_INCLUDED
