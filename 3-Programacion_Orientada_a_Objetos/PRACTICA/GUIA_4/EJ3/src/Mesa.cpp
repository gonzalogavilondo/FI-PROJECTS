#include "Mesa.h"

/***
    Constructor
***/
Mesa::Mesa(float initAltura, int initCntPatas)
{
    altura = initAltura;
    cntPatas = initCntPatas;
}

/***
    Getters y Setters
***/
float Mesa::GetAltura()
{
     return altura;
}

void Mesa::SetAltura(float val)
{
     altura = val;
}

int Mesa::GetCntPatas()
{
    return cntPatas;
}

void Mesa::SetCntPatas(int val)
{
    cntPatas = val;
}

/***
    Sobrecargamos el operador de insercion de mesa
***/
ostream& operator<< (ostream& co, const Mesa& mesa)
{
    co << "Altura = " << mesa.altura << endl
       << "Cantidad de patas = " << mesa.cntPatas << endl
       << "Alto = " << mesa.alto() << endl;

    return co;

}
/***
    Metodos propios de Mesa
***/
float Mesa::alto() const
{
    float alto = 0.0;

    return alto;
}
