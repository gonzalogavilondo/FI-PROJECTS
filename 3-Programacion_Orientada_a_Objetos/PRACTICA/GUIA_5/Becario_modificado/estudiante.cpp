#include "estudiante.h"

/***
    Constructores
***/
estudiante::estudiante(string nombre, unsigned doc, fecha nac,
                       string carrera, fecha ingreso, int cant, float prom) :
    //Inicializamos fuera del campo del constructor a la persona llamando a su propio constructor
    persona(nombre, doc, nac)
{
    //Atributos solo de estudiante
    Carrera = carrera;
    FechaIngreso = ingreso;
    Materias = cant;
    Promedio = prom;
}

estudiante::estudiante(string nombre, unsigned doc, int dia, int mes, int anio,
                       string carrera, int ding, int ming, int aing, int cant, float prom) :
    //Inicializamos fuera del campo del constructor a la persona llamando a su propio constructor
    persona(nombre, doc, fecha(dia, mes, anio))
{
    //Atributos solo de estudiante
    Carrera = carrera;
    FechaIngreso.Day = ding;
    FechaIngreso.Month = ming;
    FechaIngreso.Year = aing;
    Materias = cant;
    Promedio = prom;
}

estudiante::estudiante()
{
    ;
}

/***
    Destructor
***/
estudiante::~estudiante()
{
    //dtor
}

/***
    Setters
***/
void estudiante::SetName(string nombre)
{
    Name = nombre;
}

void estudiante::SetDocument(unsigned numero)
{
    Document = numero;
}

void estudiante::SetBirthDate(fecha ddmmaa)
{
    BirthDate.Day = ddmmaa.Day;
    BirthDate.Month = ddmmaa.Month;
    BirthDate.Year = ddmmaa.Year;
}

void estudiante::SetBirthDate(int dia, int mes, int anio)
{
    BirthDate.Day = dia;
    BirthDate.Month = mes;
    BirthDate.Year = anio;
}

void estudiante::SetCarrera(string val)
{
    Carrera = val;
}

void estudiante::SetIngreso(fecha val)
{
    FechaIngreso = val;
}

void estudiante::SetIngreso(int dd, int mm, int aa)
{
    FechaIngreso.Day = dd;
    FechaIngreso.Month = mm;
    FechaIngreso.Year = aa;
}

void estudiante::SetMaterias(int val)
{
    Materias = val;
}

void estudiante::SetPromedio(float val)
{
    Promedio = val;
}

/***
    Getters
***/
string estudiante::GetCarrera()
{
    return Carrera;
}

fecha &estudiante::GetFechaIngreso()
{
    return FechaIngreso;
}

int estudiante::GetMaterias()
{
    return Materias;
}

float estudiante::GetPromedio()
{
    return Promedio;
}

/***
    Sobrecarga del operador de insercion
***/
ostream& operator<< (ostream& co, const estudiante &est)
{
    co   << "Nombre = " << est.Name << endl
         << "Documento = " << est.Document << endl
         << "Fecha de nacimiento = " << est.BirthDate << endl
         << "Carrera = Ing. " << est.Carrera << endl
         << "Fecha ingreso (estudiante) = " << est.FechaIngreso << endl
         << "Cantidad de materias aprobadas = " << est.Materias << endl
         << "Promedio = " << est.Promedio << endl;

    return co;
}

/***
    Impresion
***/
void vPrint(estudiante &est)
{
    cout << "Nombre = " << est.GetName() << endl
         << "Documento = " << est.GetDocument() << endl
         << "Fecha nacimiento = " << est.GetBirthDate()<< endl
         << "Carrera = Ing. " << est.GetCarrera() << endl
         << "Fecha ingreso = " << est.GetFechaIngreso() << endl
         << "Cantidad de materias aprobadas = " << est.GetMaterias() << endl
         << "Promedio = " << est.GetPromedio() << "\n\n";
}
