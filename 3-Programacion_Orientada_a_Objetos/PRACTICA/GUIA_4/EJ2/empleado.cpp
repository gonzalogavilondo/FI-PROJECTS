#include "empleado.h"

/***
    Constructores
***/
empleado::empleado()
{
    //ctor
}

empleado::empleado(string nombre, unsigned doc, fecha nac,
                   string cat, fecha ingreso, float sueldo) :
    //Inicializamos fuera del campo del constructor a la persona
    persona(nombre, doc, nac)
{
    //Atributos solo del empleado
    Categoria = cat;
    FechaIngreso = ingreso;
    Sueldo = sueldo;
}

empleado::empleado(string nombre, unsigned doc, int dia, int mes, int anio,
                   string cat, int ding, int ming, int aing, float sueldo):
    //Inicializo a persona con su constructor
    persona(nombre, doc, fecha(dia, mes, anio))
{
    //Datos solo del empleado.
    Categoria = cat;
    FechaIngreso.Day = ding;
    FechaIngreso.Month = ming;
    FechaIngreso.Year = aing;
    Sueldo = sueldo;
}

/***
    Destructor
***/
empleado::~empleado()
{
    //dtor
}

/***
    Setters de la clase persona, por eso tengo que utilizar el puntero "this"
***/
void empleado::SetName(string nombre)
{
    this->Name = nombre;
}

void empleado::SetDocument(unsigned numero)
{
    this->Document = numero;

}

void empleado::SetBirthDate(fecha ddmmaa)
{
    this->BirthDate.Day = ddmmaa.Day;
    this->BirthDate.Month = ddmmaa.Month;
    this->BirthDate.Year = ddmmaa.Year;

}

void empleado::SetBirthDate(int dia, int mes, int anio)
{
    this->BirthDate.Day = dia;
    this->BirthDate.Month = mes;
    this->BirthDate.Year = anio;
}

/***
    Setters de la clase empleado, no necesito el puntero this.
***/
void empleado::SetCategoria(string val)
{
    Categoria = val;
}

void empleado::SetIngreso(fecha val)
{
    FechaIngreso = val;
}

void empleado::SetIngreso(int dd, int mm, int aa)
{
    FechaIngreso.Day = dd;
    FechaIngreso.Month = mm;
    FechaIngreso.Year = aa;
}

void empleado::SetSueldo(float val)
{
    Sueldo = val;
}

/***
    Getters
***/
string empleado::GetCategoria()
{
    return Categoria;
}

fecha& empleado::FechaGetIngreso()
{
    return FechaIngreso;
}

float empleado::GetSueldo()
{
    return Sueldo;
}

/***
    Sobrecarga del operador de insercion
***/

ostream& operator<< (ostream& co, const empleado &emp)
{
    co   << persona(emp)
         << "Categoria = " << emp.Categoria << endl
         << "Fecha ingreso (empleado) = " << emp.FechaIngreso << endl
         << "Sueldo = " << emp.Sueldo << "\n\n";

    return co;
}

/***
    Impresion
***/
void vPrint(empleado &emp)
{
    cout << emp.GetName() << endl;
    cout << emp.GetDocument() << endl;
    cout << emp.GetBirthDate() << endl
         << emp.GetCategoria() << endl
         << emp.FechaGetIngreso() << endl
         << emp.GetSueldo() << "\n\n";
}
