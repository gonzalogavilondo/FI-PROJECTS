#include "becario.h"

becario::becario()
{
    //ctor
}

becario::~becario()
{
    //dtor
}

becario::becario(string nombre, unsigned doc, fecha fe,
                 string carrera, fecha ing, int cant, float pro,
                 string cat, fecha ding, float sueldo,
                 string tipo, int dur, string lab, string dir) :
//    estudiante(nombre, doc, fe, carrera, ing, cant, pro),
    empleado(nombre, doc, fe, cat, ding, sueldo),
    estudiante(nombre, doc, fe, carrera, ing, cant, pro),
    stTipo(tipo), iDuracion(dur), stLaboratorio(lab), stDirector(dir)
{
    ;
}

void becario::SetName(string nombre)
{
    Name = nombre;
}

string becario::stGetTipo()
{
    return stTipo;
}

bool becario::SetDocument(unsigned numero)
{
    Document = numero;

    return true;
}

bool becario::SetBirthDate(fecha ddmmaa)
{
    BirthDate.Day = ddmmaa.Day;
    BirthDate.Month = ddmmaa.Month;
    BirthDate.Year = ddmmaa.Year;

    return true;
}

bool becario::SetBirthDate(int dia, int mes, int anio)
{
    BirthDate.Day = dia;
    BirthDate.Month = mes;
    BirthDate.Year = anio;

    return true;
}

void becario::vSetTipo(string val)
{
    stTipo = val;
}

int becario::iGetDuracion()
{
    return iDuracion;
}

void becario::vSetDuracion(int val)
{
    iDuracion = val;
}

string becario::stGetLaboratorio()
{
    return stLaboratorio;
}

void becario::vSetLaboratorio(string val)
{
    stLaboratorio = val;
}

string becario::stGetDirector()
{
    return stDirector;
}

void becario::vSetDirector(string val)
{
    stDirector = val;
}

void vPrint(becario &bec)
{
    cout << "Nombre = " << bec.estudiante::GetName() << endl
         << "Documento = " << bec.estudiante::GetDocument() << endl
         << "Fecha Nacimiento = " << bec.estudiante::GetBirthDate().Day << '/'
         << bec.estudiante::GetBirthDate().Month << '/'
         << bec.estudiante::GetBirthDate().Year << endl
         << "Categoria = " << bec.stGetCategoria() << endl
         << "Fecha Ingreso = " << bec.empleado::fechaGetIngreso().Day << '/'
         << bec.empleado::fechaGetIngreso().Month << '/'
         << bec.empleado::fechaGetIngreso().Year << endl
         << "Sueldo = " << bec.fGetSueldo() << endl
         << "Carrera = " << bec.stGetCarrera() << endl
         << "Fecha Ingreso = " << bec.estudiante::fechaGetIngreso().Day << '/'
         << bec.estudiante::fechaGetIngreso().Month << '/'
         << bec.estudiante::fechaGetIngreso().Year << endl
         << "Cantidad de materias = " << bec.iGetMaterias() << endl
         << "Promedio = " << bec.fGetPromedio() << endl
         << "Tipo de beca = " << bec.stGetTipo() << endl
         << "Duracion = " << bec.iGetDuracion() << endl
         << "Lugar trabajo = " << bec.stGetLaboratorio() << endl
         << "Nombre director = " << bec.stGetDirector() << "\n\n";
}

ostream& operator<< (ostream& co, becario &bec)
{
    co   << "Nombre = " << bec.Name << endl
         << "Documento = " << bec.Document << endl
         << "Fecha Nacimiento = " << bec.estudiante::GetBirthDate().Day << '/'
         << bec.estudiante::GetBirthDate().Month << '/'
         << bec.estudiante::GetBirthDate().Year << endl
         << "Categoria = " << bec.stGetCategoria() << endl
         << "Fecha Ingreso = " << bec.empleado::fechaGetIngreso().Day << '/'
         << bec.empleado::fechaGetIngreso().Month << '/'
         << bec.empleado::fechaGetIngreso().Year << endl
         << "Sueldo = " << bec.fGetSueldo() << endl
         << "Carrera = " << bec.stGetCarrera() << endl
         << "Fecha Ingreso = " << bec.estudiante::fechaGetIngreso().Day << '/'
         << bec.estudiante::fechaGetIngreso().Month << '/'
         << bec.estudiante::fechaGetIngreso().Year << endl
         << "Cantidad de materias = " << bec.iGetMaterias() << endl
         << "Promedio = " << bec.fGetPromedio() << endl
         << "Tipo de beca = " << bec.stGetTipo() << endl
         << "Duracion = " << bec.iGetDuracion() << endl
         << "Lugar trabajo = " << bec.stGetLaboratorio() << endl
         << "Nombre director = " << bec.stGetDirector() << "\n\n";

    return co;
}
