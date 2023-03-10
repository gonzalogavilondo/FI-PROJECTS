#include "MesaRedonda.h"

/***
    Constructores
***/

//MesaRedonda::MesaRedonda()
//{
//    color = 1; // 1 es el marron
//}

MesaRedonda::MesaRedonda(float initRadio, //Atributo de Circulo
                         float initAltura, int initCntPatas, //Atributos de Mesa
                         int initColor) :
//Llamo a los constructores para inicializar
Circulo(initRadio),
Mesa(initAltura, initCntPatas)
{
    //Inicializo aca adentro los atributos propios de color
    color = initColor;
}

/***
    Destructor
***/
MesaRedonda::~MesaRedonda()
{
    //dtor
}

/***
    Getters y Setters
***/
int MesaRedonda::GetColor()
{
     return color;
}

void MesaRedonda::SetColor(int val)
{
     color = val;
}

/***
    Sobrecargamos el operador de insercion
***/
ostream& operator<< (ostream& co, const MesaRedonda& mesaRedonda)
{
    co << Circulo(mesaRedonda)
       << Mesa(mesaRedonda)
       << "Color = " << mesaRedonda.color << endl << endl;

    return co;
}
/***
    Metodos propios de MesaRedonda
***/

int MesaRedonda::Color() const
{
    int color = 1;

    return color;
}
