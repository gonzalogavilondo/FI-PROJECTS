#include "Empleado.h"
/***
    Constructores
***/
Empleado::Empleado()
{
    //ctor
}

/***
    Destructor
***/
Empleado::~Empleado()
{
    //dtor
}

/***
    Getters y setters
***/
string Empleado::GetNombre()
{
     return nombre;
}

void Empleado::SetNombre(string val)
{
     nombre = val;
}

string Empleado::GetTelefono()
{
     return telefono;
}

void Empleado::SetTelefono(string val)
{
     telefono = val;
}

string Empleado::GetMail()
{
     return mail;
}

void Empleado::SetMail(string val)
{
     mail = val;
}

string Empleado::GetCategoria()
{
     return categoria;
}

void Empleado::SetCategoria(string val)
{
     categoria = val;
}

Fecha Empleado::GetIngreso()
{
     return ingreso;
}

void Empleado::SetIngreso(Fecha val)
{
     ingreso = val;
}

float Empleado::GetSalario()
{
     return salario;
}

void Empleado::SetSalario(float val)
{
     salario = val;
}

int Empleado::GetCntHijos()
{
     return cntHijos;
}

void Empleado::SetCntHijos(int val)
{
     cntHijos = val;
}

bool Empleado::GetCasado()
{
     return casado;
}

void Empleado::SetCasado(bool val)
{
    casado = val;
}

/***
    Sobrecarga del operador de insercion
***/
ostream& operator << (ostream& co, Empleado& empleado)
{
    co << "Nombre: " << empleado.nombre << endl
       << "Telefono: " << empleado.telefono << endl
       << "Mail: " << empleado.mail << endl
       << "Fecha de ingreso: " << empleado.ingreso << endl
       << "Cantidad de hijos: " << empleado.cntHijos << endl
       << "Casado: " << empleado.casado << endl
       << "Categoria: " << empleado.categoria << endl
       << "Salario: " << empleado.salario << "$" <<endl;

    return co;
}
