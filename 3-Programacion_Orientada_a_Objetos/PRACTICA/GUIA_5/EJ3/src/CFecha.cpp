#include "CFecha.h"
#include <ctime>
/***
    Constructores de CFecha
***/

CFecha::CFecha()
{
    time_t t = time(0);   // get time now
    struct tm * now = localtime( & t );
    day = now->tm_mday;
    month = (now->tm_mon + 1);
    year = (now->tm_year + 1900);
}

CFecha::CFecha(int d, int m, int a)
{
    day = d;
    month = m;
    year = a;
}

/***
    Sobrecarga del operador de insercion para CFecha
***/

ostream& operator << (ostream& co, CFecha& fe)
{
    co << fe.day   << '/'
       << fe.month << '/'
       << fe.year;

    return co;
}

/***
    Getters y setters
***/

int CFecha::GetDay()
{
     return day;
}

void CFecha::SetDay(int val)
{
     day = val;
}

int CFecha::GetMonth()
{
     return month;
}

void CFecha::SetMonth(int val)
{
     month = val;
}

int CFecha::GetYear()
{
     return year;
}

void CFecha::SetYear(int val)
{
     year = val;
}
