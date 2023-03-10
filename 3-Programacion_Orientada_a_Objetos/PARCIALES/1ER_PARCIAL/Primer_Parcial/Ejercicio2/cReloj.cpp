#include "cReloj.h"

cReloj::cReloj(unsigned int hh, unsigned int mm, unsigned int ss)
{
    time = cTime(hh, mm, ss);
    marca = NULL;
}

cReloj::cReloj(cTime& tiempo)
{
    time = tiempo;
    marca = NULL;
}

cReloj::cReloj(cReloj& reloj)
{
    time = reloj.getTiempo();
    setMarca(reloj.getMarca());
}

cReloj::~cReloj()
{
    free(marca);
}

void cReloj::setTiempo(unsigned int hh, unsigned int mm, unsigned int ss)
{
    time = cTime(hh, mm, ss);
}

cTime cReloj::getTiempo()
{
    return time;
}

void cReloj::setMarca(const char* nuevaMarca)
{
    if(nuevaMarca == NULL)
        marca = NULL;
    else
    {
        free(marca);
        marca = (char*)malloc(sizeof(strlen(nuevaMarca)+1));
        strncpy(marca, nuevaMarca, strlen(nuevaMarca)+1);
    }
}

const char* cReloj::getMarca()
{
    return marca;
}

void cReloj::incrementarTiempo()
{
    time++;
}
