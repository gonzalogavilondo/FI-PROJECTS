#include "CFigura.h"

CFigura::CFigura()
{
    //ctor
}

CFigura::~CFigura()
{
    //dtor
}

/***
    Getters y settters
***/

CColor CFigura::getFore_color()
{
     return fore_color;
}

void CFigura::setFore_color(CColor val)
{
     fore_color = val;
}

CColor CFigura::getBack_color()
{
     return back_color;
}

void CFigura::setBack_color(CColor val)
{
     back_color = val;
}

tipoDeFigura CFigura::getTipoDeFigura()
{
    return tipo;
}

void CFigura::setTipoDeFigura(tipoDeFigura val)
{
    tipo = val;
}

float CFigura::getBase()
{
    return base;
}

void CFigura::setBase(float val)
{
    base = val;
}

float CFigura::getAltura()
{
    return altura;
}

void CFigura::setAltura(float val)
{
    altura = val;
}

/***
    Metodos propios de CFigura
***/
void CFigura::imprimir(ostream& co)
{
    switch (tipo)
    {
        case Rectangulo:
            co << "Soy un Rectangulo" << endl;
            break;
        case Circulo:
            co << "Soy un Circulo" << endl;
            break;
        case Triangulo:
            co << "Soy un Triangulo" << endl;
    }

    co << " con color "
       << fore_color
       << " sobre "
       << back_color;

}
