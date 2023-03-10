#include "Empleado.h"

Empleado::Empleado()
{


}

Empleado::Empleado(string nom, string ap, Fecha fechaC, Fecha fechaN)
{
    nombres = nom;
    apellidos = ap;
    fechaContratacion = fechaC;
    fechaNacimiento = fechaN;
}

string Empleado::Getnombres()
{
     return nombres;
}

void Empleado::Setnombres(string val)
{
     nombres = val;
}

string Empleado::Getapellidos()
{
    return apellidos;
}

void Empleado::Setapellidos(string val)
{
     apellidos = val;
}

Fecha Empleado::GetfechaContratacion()
{
     return fechaContratacion;
}

void Empleado::SetfechaContratacion(Fecha val)
{
    fechaContratacion = val;
}

Fecha Empleado::GetfechaNacimiento()
{
     return fechaNacimiento;
}

void Empleado::SetfechaNacimiento(Fecha val)
{
     fechaNacimiento = val;
}

void Empleado::imprimir()
{
    cout << Getapellidos() << ", " << Getnombres() << endl;
    cout << "Contratado el: ";
    GetfechaContratacion().imprimir_la();
    cout << "Fecha de nacimiento: ";
    GetfechaNacimiento().imprimir_la();
    cout << endl;
}
