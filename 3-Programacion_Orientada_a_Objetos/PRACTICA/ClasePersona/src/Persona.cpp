#include "Persona.h"

/***
    Constructor
***/
Persona::Persona(string _name, string _lastName, unsigned _document, Fecha _birthDate)
{
    name = _name;
    lastName = _lastName;
    document = _document;
    birthDate = _birthDate;
}

/***
    Destructor
***/
Persona::~Persona()
{
    //dtor
}

/***
    Getters y Setters
***/
string Persona::getName()
{
    return name;
}

void Persona::setName(string val)
{
     name = val;
}

string Persona::getLastName()
{
    return lastName;
}

void Persona::setLastName(string val)
{
    lastName = val;
}

unsigned Persona::getDocument()
{
     return document;
}

void Persona::setDocument(unsigned val)
{
     document = val;
}

Fecha Persona::getBirthDate()
{
     return birthDate;
}

void Persona::setBirthDate(Fecha val)
{
     birthDate = val;
}

/***
    Sobrecarga de operadores
***/
ostream& operator << (ostream& co, Persona& p)
{

    co << "Nombre: " << p.name << endl
       << "Apellido: " << p.lastName << endl
       << "Documento: " << p.document << endl
       << "Fecha de nacimiento: " << p.birthDate << endl;

    return co;
}

istream& operator>> (istream& ci, Persona& p)
{
    ci >> p.name;
    ci >> p.lastName;
    ci >> p.document;

    return ci;
}
