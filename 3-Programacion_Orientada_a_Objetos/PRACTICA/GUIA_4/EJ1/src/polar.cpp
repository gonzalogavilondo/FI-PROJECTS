#include "polar.h"

/**
    Constructores
**/

polar::polar()
{
    modulo = 0.0;
    fase = 0.0;
}

polar::polar(complejo& comp) : complejo(comp) //Aca se llama al complejo y queda inicializado con el valor real e imaginario de comp (llama al ctor de copia)
{
    modulo = CalModulo(comp);
    fase = CalFase(comp);
}

polar::polar(float r, float i, bool modo) : complejo(r, i)
{
    if(modo)
    {
        modulo = r;
        fase = i;
        ToRect();
    }
    else
    {
        modulo = CalModulo(*this);
        fase = CalFase(*this);
    }

}


/**
    Getters y Setters
**/

float polar::GetModulo()
{
     return modulo;
}

void polar::SetModulo(float val)
{
    modulo = val;
}

float polar::GetFase()
{
     return fase;
}

void polar::SetFase(float val)
{
    fase = val;
}

/**
    Funciones para calcular: Modulo y Fase
**/

float polar::CalModulo(complejo& val)
{
    modulo = sqrt( pow(val.GetReal(), 2) + pow(val.GetImag(), 2) );

    return modulo;
}

float polar::CalFase(complejo& val)
{
    fase = atan2(val.GetImag(), val.GetReal()) * 180.0 / 3.1415927;

    return fase;
}

/**
    Funciones para pasar a forma: Polar y Rectangular
**/

void polar::ToRect()
{
    real = modulo * cos(fase * 3.1415927 / 180.0);
    imag = modulo * sin(fase * 3.1415927 / 180.0);
}

void polar::ToPolar()
{
    modulo = CalModulo(*this);
    fase = CalFase(*this);
}

/**
    Sobrecarga del operador de insercion
**/

ostream& operator<< (ostream& co, const polar& pol)
{
    co << pol.modulo << "/" << pol.fase << " grados";

    return co;
}

/**
    Sobrecarga de operadores aritmeticos
**/

polar polar::operator+ (const polar& pol)
{
    polar aux;

    aux.real = real + pol.real;
    aux.imag = imag + pol.imag;
    aux.ToPolar();

    return aux;
}

polar polar::operator- (const polar& pol)
{
    polar aux;

    aux.real = real - pol.real;
    aux.imag = imag - pol.imag;
    aux.ToPolar();

    return aux;

}

polar polar::operator* (const polar& pol)
{
    polar aux;

    aux.real = real*pol.real - imag*pol.imag;
    aux.imag = real*pol.imag + imag*pol.real;

    aux.ToPolar();

    return aux;
}

polar polar::operator/ (const polar& pol)
{
    polar aux;
    double deno;

    deno = pol.real*pol.real + pol.imag*pol.imag;
    aux.real = (real*pol.real + imag*pol.imag) / deno;
    aux.imag = (-real*pol.imag + imag*pol.real) / deno;

    aux.ToPolar();

    return aux;
}

polar operator* (double factor, const polar& pol)
{
    polar aux(pol);

    aux.modulo *= factor;

    return aux;
}

//double operator* (const polar& pol1, const polar& pol2)
//{
//    polar aux;
//
//    aux.modulo = (pol1.modulo * pol2.modulo);
//    aux.fase = (pol1.fase + pol2.fase);
//
//    double???
//
//    return aux;
//}

polar& polar::operator+= (polar& pol)
{
    real += pol.real;
    imag += pol.imag;
    this->ToPolar();

    return(*this);
}

polar& polar::operator*= (double factor)
{
    real *= factor;
    imag *= factor;
    this->ToPolar();

    return (*this);
}

