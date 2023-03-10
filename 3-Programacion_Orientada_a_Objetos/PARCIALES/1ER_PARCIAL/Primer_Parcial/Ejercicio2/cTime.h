#ifndef CTIME_H_INCLUDED
#define CTIME_H_INCLUDED

#include <iostream>
#include <iomanip>
using namespace std;

class cTime
{
    private:
        unsigned int hora;
        unsigned int minuto;
        unsigned int segundo;

    public:
        cTime(unsigned int hh = 0, unsigned int mm = 0, unsigned int ss = 0);
        //Constructor de copia y destructor por defecto

        unsigned int getHora();
        void setHora(unsigned int);
        unsigned int getMinuto();
        void setMinuto(unsigned int);
        unsigned int getSegundo();
        void setSegundo(unsigned int);

        friend ostream& operator<< (ostream&, const cTime&);

        cTime& operator++(int dummy);

};

#endif // CTIME_H_INCLUDED
