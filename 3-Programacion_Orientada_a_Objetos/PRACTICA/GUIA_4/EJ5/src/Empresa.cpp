#include "Empresa.h"

/***
    Constructor
***/
Empresa::Empresa()
{
    nombre = "";
    cntEmpleadosPerm = 0;
    cntEmpleadosTemp = 0;
    cntEmpleadosGer = 0;
    inicioActividades = Fecha();
    temporarios = NULL;
    permanentes = NULL;
    gerentes = NULL;
}

/***
    Destructor
***/
Empresa::~Empresa()
{
    free(temporarios);
    free(permanentes);
    free(gerentes);
}

string Empresa::GetNombre()
{
     return nombre;
}

/***
    Setters y Getters
***/
void Empresa::SetNombre(string val)
{
     nombre = val;
}

Fecha Empresa::GetInicioActividades()
{
     return inicioActividades;
}

void Empresa::SetInicioActividades(Fecha val)
{
     inicioActividades = val;
}

int Empresa::GetCntEmpleadosTemp()
{
     return cntEmpleadosTemp;
}

void Empresa::SetCntEmpleadosTemp(int val)
{
     cntEmpleadosTemp = val;
}

int Empresa::GetCntEmpleadosPerm()
{
     return cntEmpleadosPerm;
}

void Empresa::SetCntEmpleadosPerm(int val)
{
     cntEmpleadosPerm = val;
}

int Empresa::GetCntEmpleadosGer()
{
     return cntEmpleadosGer;
}

void Empresa::SetCntEmpleadosGer(int val)
{
     cntEmpleadosGer = val;
}

/***
    Sobrecarga del operador de insercion
***/
ostream& operator << (ostream& co, Empresa& empresa)
{
    co << "Nombre: " << empresa.nombre << endl
       << "Fecha de fundacion: " << empresa.inicioActividades << endl
       << "Cantidad de empleados temporales: " << empresa.cntEmpleadosTemp << endl
       << "Cantidad de empleados permanentes: " << empresa.cntEmpleadosPerm << endl
       << "Cantidad de gerentes: " << empresa.cntEmpleadosGer << endl;
       //<< "Monto total a pagar: " << empresa.MontoTotal() << endl;

    return co;

}

/***
    Funciones de Empresa
***/
Empresa& Empresa::SetEmpresa(Empresa &empresa)
{
    Fecha fecha1(1, 4, 1952);

    empresa.nombre = ("Musimundo");
    empresa.cntEmpleadosGer = (2);
    empresa.cntEmpleadosPerm = (8);
    empresa.cntEmpleadosTemp = (12);
    empresa.inicioActividades = fecha1;

    return empresa;
}

Empleado& Empresa::ContratarEmpleado(Empleado &emp)
{
    emp.SetNombre("Carlos");
    emp.SetTelefono("2236830702");
    emp.SetMail("CarlosPirulo@gmail.com");
    emp.SetIngreso(Fecha(23, 10, 1997));
    emp.SetCntHijos(2);
    emp.SetCasado(true);
    emp.SetCategoria("Permanente");

    if(emp.GetCategoria() == "Permanente")
    {
        Permanente empPerm = (Permanente)emp;
        //Permanente empPerm(emp); //Es lo mismo que lo de arriba.
        emp.SetSalario(empPerm.CalcularSueldo());
    }
    else
    {
        Temporario empTemp = (Temporario)emp;
        emp.SetSalario(empTemp.CalcularSueldo());
    }

    return emp;
}

float Empresa::MontoTotal()
{
    float resultado = 0.0;

    //Calculamos el total a pagar por los empleados permanentes
    for(int i = 0; i < cntEmpleadosPerm; i++)
    {
        resultado += permanentes[i].CalcularSueldo();
    }

    //Calculamos el total a pagar por los empleados temporarios
    for(int i = 0; i < cntEmpleadosTemp; i++)
    {
        resultado += temporarios[i].CalcularSueldo();
    }

    //Calculamos el total a pagar por los gerentes
    for(int i = 0; i < cntEmpleadosGer; i++)
    {
        resultado += gerentes[i].CalcularSueldo();
    }

    return resultado;
}
