#ifndef TXTABIN_H
#define TXTABIN_H

#include <Fecha.h>
//#include <Tipos.h>


void txt_a_bin(const char* path_txt, const char* path_bin);
void txt_a_bin_res(const char* path_txt, const char* path_bin);
void mostrar_reg(const void* pvreg);
void mostrar_clave_reg(const void* pvreg);
int cmp_reg_res(const void* pv1, const void* pv2);


#endif // TXTABIN_H
