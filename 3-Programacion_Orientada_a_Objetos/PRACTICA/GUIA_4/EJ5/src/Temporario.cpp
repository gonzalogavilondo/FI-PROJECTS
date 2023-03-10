#include "Temporario.h"

/***
    Constructor
***/
Temporario::Temporario()
{
    cntHoras = 0;
    valorHora = 20.0;
}

Temporario::Temporario(Empleado& emp)
{
    cntHoras = 0;
    valorHora = 20.0;
    nombre = emp.GetNombre();
    telefono = emp.GetTelefono();
    mail = emp.GetMail();
    categoria = emp.GetCategoria();
    ingreso = emp.GetIngreso();
    salario = emp.GetSalario();
    cntHijos = emp.GetCntHijos();
    casado = emp.GetCasado();
}

/***
    Destructor
***/
Temporario::~Temporario()
{
    //dtor
}

/***
    Getters y setters
***/
float Temporario::GetValorHora()
{
     return valorHora;
}

void Temporario::SetValorHora(float val)
{
     valorHora = val;
}

int Temporario::GetCntHoras()
{
     return cntHoras;
}

void Temporario::SetCntHoras(int val)
{
     cntHoras = val;
}

/***
    Funciones de temporario
***/
float Temporario::CalcularSueldo()
{
    float resultado = 0.0;

    if(casado)
    {
        resultado = ((cntHoras*valorHora) + (cntHijos*20) + 10);
    }
    else
    {
        resultado = ((cntHoras*valorHora) + (cntHijos*20));
    }

    return resultado;
}
