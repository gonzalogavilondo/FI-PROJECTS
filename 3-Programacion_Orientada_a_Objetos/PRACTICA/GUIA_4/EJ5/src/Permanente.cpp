#include "Permanente.h"

/***
    Constructor
***/
Permanente::Permanente()
{
    valorHora = 30.0;
    cntHoras = 0;
    antiguedad = 0.0;
}

Permanente::Permanente(Empleado& emp): Empleado(emp)
{
    valorHora = 30.0;
    cntHoras = 0;
    antiguedad = 0.0;
}

/***
    Destructor
***/
Permanente::~Permanente()
{
    //dtor
}

/***
    Getters y setters
***/
float Permanente::GetValorHora()
{
     return valorHora;
}

void Permanente::SetValorHora(float val)
{
     valorHora = val;
}

int Permanente::GetCntHoras()
{
     return cntHoras;
}

void Permanente::SetCntHoras(int val)
{
     cntHoras = val;
}

float Permanente::GetAntiguedad()
{
     return antiguedad;
}

void Permanente::SetAntiguedad(float val)
{
     antiguedad = val;
}

/***
    Funciones de permanente
***/
float Permanente::CalcularSueldo()
{
    float resultado = 0.0;

    if(casado)
    {
        resultado = ((cntHoras*valorHora) + (antiguedad*10) + (cntHijos*20) + 10);
    }
    else
    {
        resultado = ((cntHoras*valorHora) + (antiguedad*10) + (cntHijos*20));
    }

    return resultado;
}
