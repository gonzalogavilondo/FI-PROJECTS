#include "persona.h"
#include <ctime>

/**
    Clase fecha
**/

fecha::fecha()
{
    time_t t = time(0);   // get time now
    struct tm * now = localtime( & t );
    Day = now->tm_mday;
    Month = (now->tm_mon + 1);
    Year = (now->tm_year + 1900);
}

fecha::fecha(int d, int m, int a)
{
    Day = d;
    Month = m;
    Year = a;
}

ostream& operator<< (ostream& co, fecha& fe)
{
    co << fe.Day << '/'
       << fe.Month << '/'
       << fe.Year << "\n\n";

    return co;
}

/**
    Clase persona
**/

persona::persona(string nombre, unsigned numero, fecha ddmmaa)
{
    Name = nombre;
    Document = numero;
    BirthDate = ddmmaa;
}

persona::~persona()
{
    return ;
}

void persona::SetName(string nombre)
{
    Name = nombre;
}

bool persona::SetDocument(unsigned numero)
{
    Document = numero;

    return true;
}

bool persona::SetBirthDate(fecha ddmmaa)
{
    BirthDate = ddmmaa;

    return true;
}

bool persona::SetBirthDate(int dia, int mes, int anio)
{
    BirthDate.Day = dia;
    BirthDate.Month = mes;
    BirthDate.Year = anio;

    return true;
}

string persona::GetName()
{
    return Name;
}

unsigned persona::GetDocument()
{
    return Document;
}

fecha persona::GetBirthDate()
{
    return BirthDate;
}

void print(persona &per) //Pasamos una referencia a persona para ganar tiempo y que no haga una copia de toda una clase, ahorramos tiempo y memoria
{
    cout << per.GetName() << endl;
    cout << per.GetDocument() << endl;
    cout << per.GetBirthDate().Day << '/'
         << per.GetBirthDate().Month << '/'
         << per.GetBirthDate().Year << "\n\n";
}

ostream& operator<< (ostream& co, persona &per) //Funcion amiga sobrecargando el operador << (indireccion)
{
    co << per.Name << endl; //Como es una funcion amiga, no hacen falta los getters.
    co << per.Document << endl;
    co << per.BirthDate; //Sabe como imprimir una fecha porque hay una funcion amiga sobrecargando
                         //tambien el operador << (indireccion) en la clase fecha como en este metodo.
    return co;
}
