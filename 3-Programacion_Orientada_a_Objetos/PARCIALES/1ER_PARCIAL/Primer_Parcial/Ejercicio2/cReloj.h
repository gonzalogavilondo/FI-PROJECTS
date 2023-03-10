#ifndef CRELOJ_H_INCLUDED
#define CRELOJ_H_INCLUDED

#include "cTime.h"
#include <cstring>
#include <cstdlib>

class cReloj
{
    protected:
        cTime time;
        char *marca;

    public:
        cReloj(unsigned int hh = 0, unsigned int mm = 0, unsigned int ss = 0);
        cReloj(cTime&);
        cReloj(cReloj&);
        ~cReloj();

        void setTiempo(unsigned int, unsigned int, unsigned int);
        cTime getTiempo();
        void setMarca(const char*);
        const char* getMarca();

        void incrementarTiempo();  //De a 1 segundo
};

#endif // CRELOJ_H_INCLUDED
