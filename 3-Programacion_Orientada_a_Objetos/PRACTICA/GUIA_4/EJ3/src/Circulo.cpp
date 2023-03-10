#include "Circulo.h"

/***
    Constructor
***/
Circulo::Circulo(float initRadio)
{
    radio = initRadio;
}

Circulo::~Circulo()
{
    //dtor
}

/***
    Getters y Setters
***/
float Circulo::GetRadio()
{
     return radio;
}

void Circulo::SetRadio(float val)
{
     radio = val;
}

/***
    Sobrecargamos el operador de Circulo
***/
ostream& operator<< (ostream& co, const Circulo& circulo)
{
    co << "Radio = " << circulo.radio << endl
       << "Area = " << circulo.area() << endl;

    return co;
}

/***
    Metodos propios de Circulo
***/
float Circulo::area() const
{
    float area = 0.0;

    area = 3.1415927 * pow(radio, 2);

    return area;
}
