#include "CCuenta.h"

/***
    Constructor
***/
CCuenta::CCuenta(int _numero, double _saldo, double _porcentajeDeInteres)
{
    numero = _numero;
    saldo = _saldo;
    porcentajeDeInteres = _porcentajeDeInteres;
}

/***
    Destructor
***/
CCuenta::~CCuenta()
{
    //dtor
}

/***
    Setters
***/
bool CCuenta::SetNumero(int val)
{
    if(val >= 0)
    {
        numero = val;
        return true;
    }
    else
    {
        cerr << "Error: cuenta no valida " << endl;
        return false;
    }
}

void CCuenta::SetSaldo(double val)
{
     saldo = val;
}

bool CCuenta::SetTipoDeInteres(double val)
{
    if(val >= 0)
    {
        porcentajeDeInteres = val;
        return true;
    }
    else
    {
        cerr << "Error: tipo no valido" << endl;
        return false;
    }
}

/***
    Getters
***/
int CCuenta::GetNumero()
{
     return numero;
}

double CCuenta::GetSaldo()
{
     return saldo;
}

double CCuenta::GetTipoDeInteres()
{
     return porcentajeDeInteres;
}

/***
    Sobrecarga de operadores
***/
CCuenta& CCuenta::operator=(const CCuenta& c)
{
    numero = c.numero;
    saldo = c.saldo;
    porcentajeDeInteres = c.porcentajeDeInteres;

    return (*this);
}

ostream& operator<< (ostream& co, const CCuenta& c)
{
       c.print(co);

    return co;
}

/***
    Metodos propios de la clase CCuenta
***/
bool CCuenta::Ingreso(double cantidad)
{
    if(cantidad >= 0)
    {
        saldo += cantidad;
        return true;
    }
    else
    {
        cerr << "Error: ingreso negativo" << endl;
        return false;
    }
}

