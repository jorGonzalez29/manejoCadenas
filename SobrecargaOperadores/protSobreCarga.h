#ifndef PROTSOBRECARGA_H_INCLUDED
#define PROTSOBRECARGA_H_INCLUDED
#define DEPURAR
using namespace std;

class Punto{

    int coordX,
        coordY;
public:
   /* Punto();
    Punto(const Punto &obj);
    Punto(int X);
    Punto(int X, int Y);*/
    Punto(int X = 0, int Y = 0);
    Punto& operator = (const Punto&);
    friend ostream& operator << (ostream&, const Punto&);
    friend istream& operator >> (istream&, Punto&);
    Punto operator + (const  Punto&)const;//el const al costado estoy haciendo referencia al otro objeto de tipo Punto que se va hacer la suma o resta el cual tiene q ser const.
    Punto operator - (const  Punto&)const;
    Punto operator + (const int &)const;
    friend Punto operator +(const int&, const Punto&);
    Punto operator ++ (int);
    Punto& operator ++ (void);
    Punto operator -- (int);
    Punto& operator -- (void);
    void Mostrar();
    #ifdef DEPURAR
    ~Punto();
    #endif // DEPURAR

};

#endif // PROTSOBRECARGA_H_INCLUDED
