#ifndef CLASSTIME_H_INCLUDED
#define CLASSTIME_H_INCLUDED
#define TAMSEC 60
#define TAMMIN 60
#define TAMHOURS 24
#include <stdbool.h>
using namespace std;

class Time{
private:
    int hours,
        minutes,
        seconds;
public:
    Time(int hours = 0, int minutes = 0, int seconds = 0);
    /**Sobre carga operador <<**/
    friend ostream& operator << (ostream& out, const Time &obj);
    /**Sobrecarga operador (Pre incremento ++)**/
    Time& operator ++ ();
    /**Sobrecarga operador (Pos incremento ++)**/
    Time operator ++ (int);
    /**Sobrecarga operador (Pre decremento ++)**/
    Time& operator -- ();
    /**Sobrecarga operador (Pos decremento ++)**/
    Time operator -- (int);
    /**Sobrecarga operador (Suma) + **/
    Time operator + (const Time& obj1)const;
    /**Sobrecarga operator (Resta) - **/
    Time operator - (const Time& obj)const;
    /**Sobrecarga operador (suma-asignacion)+= **/
    Time& operator += (const Time& obj);
    /**Sobrecarga operador (resta-asignacion)-= **/
    Time& operator -= (const Time& obj);
    /**Sobrecarga operador (Suma) + con un entero**/
    Time operator + (const int& sec);
    /**Sobrecarga operador (suma-asignacion)+= con un entero**/
    Time& operator += (const int& sec);
    /**Sobrecarga operador (igual-igual) == **/
    bool operator == (const Time& obj)const;
    /**Sobrecarga operador (distinto) != **/
    bool operator != (const Time& obj)const;
    /**Sobrecarga operador (mayor) > **/
    bool operator > (const Time& obj)const;
    /**Sobrecarga operador (menor) < **/
    bool operator < (const Time& obj)const;


};

#endif // CLASSTIME_H_INCLUDED
