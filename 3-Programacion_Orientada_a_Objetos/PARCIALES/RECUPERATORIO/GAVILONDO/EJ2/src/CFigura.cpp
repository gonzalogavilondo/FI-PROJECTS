#include "CFigura.h"

/***
    Constructor
***/
CFigura::CFigura()
{
    base = 0;
    altura = 0;
}

/***
    Destructor
***/
CFigura::~CFigura()
{

}

/***
    Setters
***/
void CFigura::setTipo(string val)
{
    tipoDeFigura = val;
}

void CFigura::setForeColor(CColor val)
{
    foreColor = val;
}

void CFigura::setBackColor(CColor val)
{
    backColor = val;
}

void CFigura::setBase(float val)
{
    base = val;
}

void CFigura::setAltura(float val)
{
    altura = val;
}

/***
    Getters
***/
string CFigura::getTipo()
{
    return tipoDeFigura;
}


CColor CFigura::getForeColor()
{
    return foreColor;
}

CColor CFigura::getBackColor()
{
    return backColor;
}

float CFigura::getBase()
{
    return base;
}

float CFigura::getAltura()
{
    return altura;
}

/***
    Sobrecarga de operadores
***/

ostream& operator << (ostream& co, CFigura& obj)
{
    if (typeid(co) == typeid(cout))
    {
        co << "Soy un " << obj.getTipo()
           << " con color " << obj.foreColor
           << " sobre " << obj.backColor << "\n\t";
    }
    else
    {
        co << obj.getTipo() << ';'
           << obj.foreColor << ';'
           << obj.backColor << ';';
    }

    obj.printFigura(co);

    return co;
}

istream& operator >> (istream& ci, CFigura& obj)
{
    ci >> obj.foreColor;
    ci.ignore();
    ci >> obj.backColor;
    ci.ignore();
    obj.setFigura(ci);

    return ci;
}

