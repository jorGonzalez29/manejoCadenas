#include <iostream>
#include <stdbool.h>
#include "ClassTime.h"

using namespace std;

Time::Time(int hours, int minutes, int seconds){
        this->hours = hours;
        this->minutes = minutes;
        this->seconds = seconds;
}
/**Sobre carga operador <<**/
ostream& operator << (ostream& out, const Time &obj){
    out << obj.hours << ":" << obj.minutes << ":" << obj.seconds;
    return out;
}
/**Sobrecarga operador (Pre incremento ++)**/
Time& Time::operator ++(){
    seconds ++;
    if(seconds > TAMSEC){
        minutes ++;
        seconds = 0;
        if(minutes > TAMMIN){
            minutes = 0;
            hours ++;
            if(hours > TAMHOURS)
                hours = 0;
        }
    }
    return *this;
}
/**Sobrecarga operador (Pos incremento ++)**/
Time Time::operator++(int){
    Time aux = Time(*this);
    seconds ++;
    if(seconds > TAMSEC){
        minutes ++;
        seconds = 0;
        if(minutes > TAMMIN){
            minutes = 0;
            hours ++;
            if(hours > TAMHOURS)
                hours = 0;
        }
    }
    return aux;
}

/**Sobrecarga operador (Pre decremento ++)**/

Time& Time::operator--(){
    seconds --;
    if(seconds < 0){
        seconds = TAMSEC;
        minutes --;
        if(minutes < 0){
            minutes = TAMMIN;
            hours --;
            if(hours == 0)
                hours = TAMHOURS;
        }
    }
    return *this;
}
/**Sobrecarga operador (Pos decremento ++)**/
Time Time::operator--(int){
    Time aux = Time(*this);
    seconds --;
    if(seconds < 0){
        seconds = TAMSEC;
        minutes --;
        if(minutes < 0){
            minutes = TAMMIN;
            hours --;
            if(hours < 0)
                hours = TAMHOURS;
        }
    }
    return aux;
}

Time Time::operator+(const Time& obj1)const{
    Time aux = Time();

     aux.seconds = (seconds + obj1.seconds) % TAMSEC;
     aux.minutes = (seconds + obj1.seconds) / TAMSEC;
     aux.minutes += (minutes + obj1.minutes) % TAMMIN;
     aux.hours = (minutes + obj1.minutes) / TAMMIN;
     aux.hours += (hours + obj1.hours);

     return aux;
}

Time Time::operator -(const Time& obj)const{
     Time aux = Time();

     aux.seconds = (seconds - obj.seconds) < 0 ? (seconds - obj.seconds) + TAMSEC : (seconds - obj.seconds);
     aux.minutes = (minutes - obj.minutes) < 0 ? (minutes - obj.minutes) + TAMMIN : (minutes - obj.minutes);
     aux.hours = (hours - obj.hours);

     return aux;
}

Time& Time::operator+=(const Time& obj){
    Time aux = *this;


     seconds = (aux.seconds + obj.seconds) % TAMSEC;
     minutes = (aux.seconds + obj.seconds) / TAMSEC;
     minutes += (aux.minutes + obj.minutes) % TAMMIN;
     hours = (aux.minutes + obj.minutes) / TAMMIN;
     hours += (aux.hours + obj.hours);

    return *this;
}

Time& Time::operator -= (const Time& obj){
    Time aux = *this;

     seconds = (aux.seconds - obj.seconds) < 0 ? (aux.seconds - obj.seconds) + TAMSEC : (aux.seconds - obj.seconds);
     minutes = (aux.minutes - obj.minutes) < 0 ? (aux.minutes - obj.minutes) + TAMMIN : (aux.minutes - obj.minutes);
     hours = (aux.hours - obj.hours);

     return *this;
}

Time Time::operator+(const int& sec){
    Time aux = *this;
    int minute;
    seconds += sec;
    if(seconds > TAMSEC){
         aux.seconds = seconds % TAMSEC;
         aux.minutes += sec / TAMMIN;
         minute = aux.minutes;
         aux.minutes = minute % TAMMIN;
         aux.hours += minute / TAMMIN;
    }
    return aux;
}

Time& Time::operator += (const int& sec){

    int minute;
    seconds += sec;
    if(seconds > TAMSEC){
         seconds = seconds % TAMSEC;
         minutes += sec / TAMMIN;
         minute = minutes;
         minutes = minute % TAMMIN;
         hours += minute / TAMMIN;
    }
    return *this;
}

bool Time::operator == (const Time& obj)const{
    int cmp = seconds - obj.seconds;

    if(cmp)
        return false;
    cmp = minutes - obj.minutes;
    if(cmp)
        return false;
    cmp = hours - obj.hours;
    if(cmp)
        return false;

    return true;
}

bool Time::operator > (const Time& obj)const{
    if(hours > obj.hours)
        return true;
    if(minutes > obj.minutes)
        return true;
    if(seconds > obj.seconds)
        return true;
    return false;
}
bool Time::operator < (const Time& obj)const{
    if(hours < obj.hours)
        return true;
    if(minutes < obj.minutes)
        return true;
    if(seconds < obj.seconds)
        return true;
    return false;
}
bool Time::operator != (const Time& obj)const{
    return (seconds != obj.seconds || minutes != obj.minutes || hours != obj.hours);
}
