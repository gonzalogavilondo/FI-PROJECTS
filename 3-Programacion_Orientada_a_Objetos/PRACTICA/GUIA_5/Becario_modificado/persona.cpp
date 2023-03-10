#include "persona.h"
#include <ctime>

/***
    Constructores de Fecha
***/

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

/***
    Sobrecarga del operador de insercion para Fecha
***/

ostream& operator << (ostream& co, const fecha& fe)
{
    co << fe.Day   << '/'
       << fe.Month << '/'
       << fe.Year;

    return co;
}

/***
    Constructores de persona
***/
persona::persona(string nombre, unsigned numero, fecha ddmmaa)
{
    Name = nombre;
    Document = numero;
    BirthDate.Day = ddmmaa.Day;
    BirthDate.Month = ddmmaa.Month;
    BirthDate.Year = ddmmaa.Year;
}
persona::~persona()
{
    return ;
}

/***
    Setters
***/
void persona::SetName(string name)
{
    Name = name;
}

void persona::SetDocument(unsigned doc)
{
   Document = doc;
}

void persona::SetBirthDate(fecha ddmmaa)
{
    BirthDate.Day = ddmmaa.Day;
    BirthDate.Month = ddmmaa.Month;
    BirthDate.Year = ddmmaa.Year;
}

void persona::SetBirthDate(int dia, int mes, int anio)
{
    BirthDate.Day = dia;
    BirthDate.Month = mes;
    BirthDate.Year = anio;
}


/***
    Getters
***/

string persona::GetName()
{
    return Name;
}

unsigned persona::GetDocument()
{
    return Document;
}

fecha& persona::GetBirthDate()
{
    return BirthDate;
}


/***
    Sobrecarga del operador de insercion para los datos de persona
***/
ostream& operator<< (ostream& co, const persona &per)
{
    co << "Nombre = " << per.Name << endl;
    co << "Documento = " << per.Document << endl;
    co << "Fecha de nacimiento = " << per.BirthDate << endl;

    return co;
}

/***
    Impresion
***/
void Print(persona &per)
{
    cout << per.GetName() << endl;
    cout << per.GetDocument() << endl;
    cout << per.GetBirthDate() << endl << endl;
}
