#ifndef PROTARCH_H_INCLUDED
#define PROTARCH_H_INCLUDED
#define MSJ "Por favor ingrese una opcion: \n A-Cargar info \n B-Eliminar nodos duplicados \n C-Listas info \n D-Salir"
#define OPTION "ABCD"
#define CON_SIN_MSJ 1
#define FILENAME "Datos"
#define FILEERRORS "errores"
#include "protListas.h"
//Manejo Archivos
void createFile();
void createFileComercial(FILE **fp);
int openFile(FILE **fp, char *mode, char *nameFile, int CON_SIN);
void showFile(FILE **fp);
void showInfo(tInfo *p);
void showInfoComercial(const tInfo *d)
void putInTheEndFile(FILE **fp, tInfo *d);
char menuOption(const char *msj,const char *options);
void newInfo(tInfo *d);


#endif // PROTARCH_H_INCLUDED
