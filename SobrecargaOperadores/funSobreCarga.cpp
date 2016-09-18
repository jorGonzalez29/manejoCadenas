#include <iostream>
#include <istream>
#include "protSobreCarga.h"
using namespace std;
/*Punto::Punto(){
    coordX = 0;
    coordY = 0;
}
Punto::Punto(const Punto &obj){
    coordX = obj.coordX;
    coordY = obj.coordY;
}
Punto::Punto(int X){
    if(X < 0)
        X = 1024 - X;
    if(X > 1024)
        X = X - 1024;
    coordX = X;
    coordY = (X * (float)4/3);
}
Punto::Punto(int X,int Y){
    if(X < 0)
        X = 1024 - X;
    if(X > 1024)
        X = X - 1024;
    if(Y < 0)
        Y = 1024 - Y;
    if(Y > 1024)
        Y = Y - 1024;
    coordX = X;
    coordY = Y;
}*/
Punto::Punto(int X, int Y){
    if(X < 0)
        X = 1024 - X;
    if(X > 1024)
        X = X - 1024;
    if(Y < 0)
        Y = 1024 - Y;
    if(Y > 1024)
        Y = Y - 1024;
    coordX = X;
    coordY = Y;
}
void Punto::Mostrar(){
    cout<<"("<<coordX<<","<<coordY<<")"<<endl;
}
Punto Punto :: operator + (const Punto &a)const{
    Punto aux = Punto();
    aux.coordX = coordX + a.coordX;
    aux.coordY = coordY + a.coordY;
    return aux;
}
Punto Punto :: operator - (const Punto &a)const{
    Punto aux = Punto();
    aux.coordX = coordX - a.coordX;
    aux.coordY = coordY - a.coordY;
    return aux;
}
Punto Punto :: operator + (const int &a)const{
    Punto aux = Punto(coordX + a,coordY + a);
    return aux;
}
Punto operator + (const int &a, const Punto &obj){
    Punto aux = Punto(a + obj.coordX,a + obj.coordY);
    return aux;
}

Punto& Punto::operator = (const Punto &obj){
    coordX = obj.coordX;
    coordY = obj.coordY;

    return *this;
}

ostream& operator << (ostream &sal, const Punto &obj){
    sal <<"("<< obj.coordX <<";"<< obj.coordY <<")";
    return sal;
}
istream& operator >> (istream &entrada, Punto &obj){
    cout << "ingrese coordenadas"<<endl;
    entrada >> obj.coordX;
    entrada >> obj.coordY;
    return entrada;
}
//pos incremento
Punto Punto :: operator ++ (int){
    Punto aux = Punto(*this);
    coordX ++;
    coordY ++;

    return aux;
}
//pre incremento
Punto& Punto :: operator ++ (void){
    coordX ++;
    coordY ++;

    return *this;
}
//pos decremento
Punto Punto :: operator -- (int){
    Punto aux = Punto(*this);
    coordX --;
    coordY --;

    return aux;
}
//pre decremento
Punto& Punto :: operator -- (void){
    coordX --;
    coordY --;

    return *this;
}
#ifdef DEPURAR
        Punto::~Punto(){
            cout<<"EJECUTANDO DESTRUCTOR"<<endl;
        }
#endif // DEPURAR
