#ifndef CLASS_H_INCLUDED
#define CLASS_H_INCLUDED
using namespace std;
class Fecha{
    int dia,
        mes,
        anio;
public:
    Fecha(int dia = 0,int mes = 0,int anio = 0);
    friend ostream& operator << (ostream&, const Fecha &obj);
    friend istream& operator >> (istream&, Fecha &obj);
    //pos incremento
    Fecha operator ++ (int);
    //pre incremento
    Fecha& operator ++ ();
    int EsBisiesto(int);
    Fecha operator + (const Fecha&)const;
};


#endif // CLASS_H_INCLUDED
