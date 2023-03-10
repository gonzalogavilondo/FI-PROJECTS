#include "cTime.h"

cTime::cTime(unsigned int hh, unsigned int mm, unsigned int ss)
{
    hora = hh;
    minuto = mm;
    segundo = ss;
}

unsigned int cTime::getHora()
{
    return hora;
}

void cTime::setHora(unsigned int hh)
{
    hora = hh;
}

unsigned int cTime::getMinuto()
{
    return minuto;
}

void cTime::setMinuto(unsigned int mm)
{
    minuto = mm;
}

unsigned int cTime::getSegundo()
{
    return segundo;
}

void cTime::setSegundo(unsigned int ss)
{
    segundo = ss;
}

ostream& operator<< (ostream& os, const cTime& tiempo)
{
    os << setfill('0')
       << setw(2) << tiempo.hora << ":"
       << setw(2) << tiempo.minuto << ":"
       << setw(2) << tiempo.segundo
       << setfill(' ');
    return os;
}

cTime& cTime::operator++(int dummy)
{
    if(segundo < 59)
        segundo++;
    else
    {
        segundo = 0;
        if(minuto < 59)
            minuto++;
        else
        {
            minuto = 0;
            if(hora < 23)
                hora++;
            else
                hora = 0;
        }
    }

    return *this;
}
