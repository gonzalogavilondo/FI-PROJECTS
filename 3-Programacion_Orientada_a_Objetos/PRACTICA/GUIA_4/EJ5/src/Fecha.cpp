#include "Fecha.h"
#include <ctime>
/***
    Constructores de Fecha
***/

Fecha::Fecha()
{
    time_t t = time(0);   // get time now
    struct tm * now = localtime( & t );
    day = now->tm_mday;
    month = (now->tm_mon + 1);
    year = (now->tm_year + 1900);
}

Fecha::Fecha(int d, int m, int a)
{
    day = d;
    month = m;
    year = a;
}

/***
    Sobrecarga del operador de insercion para Fecha
***/

ostream& operator << (ostream& co, Fecha& fe)
{
    co << fe.day   << '/'
       << fe.month << '/'
       << fe.year;

    return co;
}

/***
    Getters y setters
***/

int Fecha::GetDay()
{
     return day;
}

void Fecha::SetDay(int val)
{
     day = val;
}

int Fecha::GetMonth()
{
     return month;
}

void Fecha::SetMonth(int val)
{
     month = val;
}

int Fecha::GetYear()
{
     return year;
}

void Fecha::SetYear(int val)
{
     year = val;
}
