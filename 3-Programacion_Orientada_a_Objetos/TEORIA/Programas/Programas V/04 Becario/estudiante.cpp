#include "estudiante.h"

estudiante::estudiante(string nombre, unsigned doc, fecha nac,
                       string carrera, fecha ingreso, int cant, float prom):
    persona(nombre, doc, nac),
    stCarrera(carrera), fechaIngreso(ingreso), iMaterias(cant), fPromedio(prom)
{
    ;
}

estudiante::estudiante()
{
    ;
}

estudiante::~estudiante()
{
    //dtor
}

void estudiante::SetName(string nombre)
{
    Name = nombre;
}

bool estudiante::SetDocument(unsigned numero)
{
    Document = numero;

    return true;
}

bool estudiante::SetBirthDate(fecha ddmmaa)
{
    BirthDate.Day = ddmmaa.Day;
    BirthDate.Month = ddmmaa.Month;
    BirthDate.Year = ddmmaa.Year;

    return true;
}

bool estudiante::SetBirthDate(int dia, int mes, int anio)
{
    BirthDate.Day = dia;
    BirthDate.Month = mes;
    BirthDate.Year = anio;

    return true;
}

string estudiante::stGetCarrera()
{
    return stCarrera;
}

void estudiante::vSetCarrera(string val)
{
    stCarrera = val;
}

fecha estudiante::fechaGetIngreso()
{
    return fechaIngreso;
}

void estudiante::vSetIngreso(fecha val)
{
    fechaIngreso = val;
}

void estudiante::vSetIngreso(int dd, int mm, int aa)
{
    fechaIngreso.Day = dd;
    fechaIngreso.Month = mm;
    fechaIngreso.Year = aa;
}

int estudiante::iGetMaterias()
{
    return iMaterias;
}

void estudiante::vSetMaterias(int val)
{
    iMaterias = val;
}

float estudiante::fGetPromedio()
{
    return fPromedio;
}

void estudiante::vSetPromedio(float val)
{
    fPromedio = val;
}

void vPrint(estudiante &est)
{
    cout << "Nombre = " << est.GetName() << endl
         << "Documento = " << est.GetDocument() << endl
         << "Fecha nacimiento = " << est.GetBirthDate().Day << '/'
         << est.GetBirthDate().Month << '/' << est.GetBirthDate().Year << endl
         << "Carrera = Ing. " << est.stGetCarrera() << endl
         << "Fecha ingreso = " << est.fechaGetIngreso().Day << '/'
         << est.fechaGetIngreso().Month << '/' << est.fechaGetIngreso().Year << endl
         << "Cantidad de materias aprobadas = " << est.iGetMaterias() << endl
         << "Promedio = " << est.fGetPromedio() << "\n\n";
}

ostream& operator<< (ostream& co, estudiante &est)
{
    co   << "Nombre = " << est.GetName() << endl
         << "Documento = " << est.GetDocument() << endl
         << "Fecha nacimiento = " << est.GetBirthDate().Day << '/'
         << est.GetBirthDate().Month << '/' << est.GetBirthDate().Year << endl
         << "Carrera = Ing. " << est.stGetCarrera() << endl
         << "Fecha ingreso = " << est.fechaGetIngreso().Day << '/'
         << est.fechaGetIngreso().Month << '/' << est.fechaGetIngreso().Year << endl
         << "Cantidad de materias aprobadas = " << est.iGetMaterias() << endl
         << "Promedio = " << est.fGetPromedio() << "\n\n";

    return co;
}
