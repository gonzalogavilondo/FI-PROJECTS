#include "CRacional.h"

/**
    Constructores
**/
CRacional::CRacional(int numerador, int denominador)
{
    num = numerador;
    den = denominador;
}

CRacional::CRacional(const CRacional& copia)
{
    num = copia.num;
    den = copia.den;
}

/**
    Getters y Setters
**/
int CRacional::GetNum()
{
     return num;
}

void CRacional::SetNum(int val)
{
     num = val;
}

int CRacional::GetDen()
{
     return den;
}

void CRacional::SetDen(int val)
{
     den = val;
}

/**
    Sobrecarga del operador de extraccion y de insercion
**/
istream& operator>> (istream& ci, CRacional& rac)
{
    char c;

    ci >> rac.num;
    ci.get(c);

    switch (c)
    {
        case '/':
            ci >> rac.den;
            break;
        case '\n':
            rac.den = 1;
            break;
        default:
            cout << endl << "Error. Recuerde ingresar el valor de a de la forma <num/den>: ";
            ci.ignore(); //Limpiamos el buffer
            ci >> rac;
            break;
    }
    simplificar(rac); //Simplificamos el numero racional

    return ci;
}

ostream& operator<< (ostream& co, const CRacional& rac)
{
    if(rac.den != 1)
    {
        co << rac.num << '/' << rac.den;
    }
    else
    {
        co << rac.num;
    }

    return co;
}

/**
    Sobrecarga de operadores aritméticos
**/
CRacional CRacional::operator+ (const CRacional& rac)
{
    CRacional suma;

    suma.den = den * rac.den;
    suma.num = (num * rac.den) + (den * rac.num);
    simplificar(suma); //Simplificamos el numero racional

    return suma;
}

CRacional CRacional::operator- (const CRacional& rac)
{
    CRacional resta;

    resta.den = den * rac.den;
    resta.num = (num * rac.den) - (den * rac.num);
    simplificar(resta); //Simplificamos el numero racional

    return resta;
}

CRacional CRacional::operator* (const CRacional& rac)
{
    CRacional multiplicacion;

    multiplicacion.den = (den * rac.den);
    multiplicacion.num = (num * rac.num);
    simplificar(multiplicacion); //Simplificamos el numero racional

    return multiplicacion;
}

CRacional CRacional::operator/ (const CRacional& rac)
{
    CRacional division;

    division.num = (num * rac.den);
    division.den = (den * rac.num);
    simplificar(division); //Simplificamos el numero racional

    return division;
}

CRacional CRacional::operator- () const
{
    CRacional opuesto(*this);

    opuesto.num *= -1;

    return opuesto;
}

CRacional& CRacional::operator+= (const CRacional& rac)
{
    num = (num * rac.den) + (den * rac.num);
    den = den * rac.den;

    simplificar(*this);

    return(*this);
}

CRacional& CRacional::operator-= (const CRacional& rac)
{
    num = (num * rac.den) - (den * rac.num);
    den = den * rac.den;

    simplificar(*this);

    return(*this);
}

CRacional& CRacional::operator++()                   // pre-incremento
{
    num += den;

    simplificar(*this);

    return (*this);
}

CRacional CRacional::operator++ (int dummy)          // post-incremento
{
    CRacional aux(*this);

    ++(*this);

    return (aux);
}

CRacional& CRacional::operator-- ()                   // pre-decremento
{
    num -= den;

    simplificar(*this);

    return (*this);
}

CRacional CRacional::operator-- (int dummy)          // post-decremento
{
    CRacional aux(*this);

    --(*this);

    return (aux);
}

CRacional operator+ (const int& r, const CRacional& rac) //Entero + racional
{
    CRacional suma;

    suma.den = rac.den;
    suma.num = (r * rac.den) + (rac.num);
    simplificar(suma); //Simplificamos el resultado

    return suma;
}

/**
    Sobrecarga de operadores de comparacion
**/
bool CRacional::operator!= (const CRacional& rac)
{
    if((num != rac.num) || (den != rac.den))
    {
        return true;
    }
    else
    {
        return false;
    }
}

bool CRacional::operator== (const CRacional& rac)
{
    if((num == rac.num) && (den == rac.den))
    {
        return true;
    }
    else
    {
        return false;
    }
}

bool CRacional::operator< (const CRacional& rac)
{
    if(num/(float)den < rac.num/(float)rac.den)
    {
        return true;
    }
    else
    {
        return false;
    }
}

bool CRacional::operator> (const CRacional& rac)
{
    if(num/(float)den > rac.num/(float)rac.den)
    {
        return true;
    }
    else
    {
        return false;
    }
}

bool CRacional::operator<= (const CRacional& rac)
{
    if(num/(float)den <= rac.num/(float)rac.den)
    {
        return true;
    }
    else
    {
        return false;
    }
}

bool CRacional::operator>= (const CRacional& rac)
{
    if(num/(float)den >= rac.num/(float)rac.den)
    {
        return true;
    }
    else
    {
        return false;
    }
}

bool CRacional::operator! () //Un racional es nulo si el numerador es 0 y el denominador cualquier numero distinto de 0
{
    if((num == 0) && (den != 0))
    {
        return true;
    }
    else
    {
        return false;
    }
}

/**
    Funcion que simplifica la fraccion
**/
int mcd(int num, int den)
{
    int u = abs(num);
    int v = abs(den);
    if(v == 0)
    {
      return u;
    }
    int r;
    while(v != 0)
    {
      r = u % v;
      u = v;
      v = r;
    }
    return u;
}

void simplificar(CRacional& rac)
{
    int dividir = mcd(rac.num, rac.den);

    rac.num = (rac.num / dividir);
    rac.den = (rac.den / dividir);
}
