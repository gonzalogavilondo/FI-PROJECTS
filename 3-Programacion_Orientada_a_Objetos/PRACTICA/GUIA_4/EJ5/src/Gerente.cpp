#include "Gerente.h"

/***
    Constructores
***/
Gerente::Gerente(): Permanente()
{
    valorHora = 40.0;
    sueldo = 0.0;
}

/***
    Destructor
***/
Gerente::~Gerente()
{
    //dtor
}

/***
    Getters y setters
***/
float Gerente::GetValorHora()
{
     return valorHora;
}

void Gerente::SetValorHora(float val)
{
     valorHora = val;
}

float Gerente::GetSueldo()
{
     return sueldo;
}

void Gerente::SetSueldo(float val)
{
     sueldo = val;
}

/***
    Funciones de gerente
***/
float Gerente::CalcularSueldo()
{
    float resultado = 0.0;

    if(casado)
    {
        resultado = sueldo + ((cntHoras*valorHora) + (antiguedad*15) + (cntHijos*20) + 10);
    }
    else
    {
        resultado = sueldo + ((cntHoras*valorHora) + (antiguedad*15) + (cntHijos*20));
    }

    return resultado;
}
