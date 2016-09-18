#include <iostream>
#include "protSobreCarga.h"
using namespace std;

int main()
{
    cout << "Prueba C++" <<endl;
    cout << "Constructor Punto" <<endl;
    Punto coordenadas = Punto();
    coordenadas.Mostrar();
    cout << "Constructor de copia Punto" <<endl;
    Punto coordenadas2 = coordenadas;
    coordenadas2.Mostrar();
    cout << "Constructor de copia generado Punto" <<endl;
    Punto coordenadas3 = Punto(coordenadas);
    coordenadas3.Mostrar();
    cout << "Constructor de un solo parametro" <<endl;
    Punto coordenadas4 = Punto(102);
    coordenadas4.Mostrar();
    cout << "Constructor con 2 parametro" <<endl;
    Punto coordenadas5 = Punto(1028,1028);
    coordenadas5.Mostrar();
    cout << "Constructor con 2 parametro con valores por defecto" <<endl;
    Punto coordenadas6 = Punto();
    coordenadas6.Mostrar();
    coordenadas = coordenadas2 = coordenadas4;
    coordenadas.Mostrar();
    coordenadas2.Mostrar();
    cout <<"Operador asignacion"<<endl;
    coordenadas4 = coordenadas5;
    coordenadas4.Mostrar();
    cout <<"Operador << sobrecargado"<<endl;
    cout <<coordenadas4<<endl;
    cout <<"Operador >> sobrecargado"<<endl;
    cin >> coordenadas4;
    cout << coordenadas4 << endl;
    cout <<"Operador ++ (pos) sobrecargado"<<endl;
    coordenadas2 = coordenadas4 ++;
    cout <<"coodenadas2 :" <<coordenadas2 << endl;
    cout <<"coordenadas4 :" << coordenadas4 << endl;
    cout <<"Operador ++ (pre) sobrecargado"<<endl;
    coordenadas3 = ++coordenadas4;
    cout <<"coodenadas3 :" <<coordenadas3 << endl;
    cout <<"coordenadas4 :" << coordenadas4 << endl;
    cout <<"Operador + sobrecargado"<<endl;
    coordenadas6 = coordenadas2 + coordenadas5;
    cout <<"coordenadas6 :"<<coordenadas6<<endl;
    cout <<"Operador - sobrecargado"<<endl;
    coordenadas5 = coordenadas6 - coordenadas2;
    cout <<"coordenadas5 :"<<coordenadas5<<endl;
    cout <<"Operador + sobrecargado con otro objeto a la derecha"<<endl;
    coordenadas2 = coordenadas5 + 7;
    cout <<"coordenadas2 :"<<coordenadas2<<endl;
    cout <<"Operador + sobrecargado con otro objeto a la izquierda"<<endl;
    coordenadas2 = 7 + coordenadas5;
    cout <<"coordenadas2 :"<<coordenadas2<<endl;
    return 0;
}
