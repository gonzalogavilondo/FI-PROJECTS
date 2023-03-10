#include "becario.h"

/***
    Constructores
***/
becario::becario()
{
    //ctor
}

becario::becario(string nombre, unsigned doc, fecha fe,
                 string carrera, fecha ing, int cant, float pro,
                 string cat, fecha ding, float sueldo,
                 string tipo, int dur, string lab, string dir) :

    //Inicializamos fuera del campo del constructor
    empleado(nombre, doc, fe, cat, ding, sueldo), //Llamamos a los constructores en el orden en que los heredamos!
    estudiante(nombre, doc, fe, carrera, ing, cant, pro)
{
    //Atributos solo de becario
    Tipo = tipo;
    Duracion = dur;
    Laboratorio = lab;
    Director = dir;
}

/***
    Destructor
***/
becario::~becario()
{
    //dtor
}


/***
    Setters de becario: Tengo que poner por donde sube el becario (Puntero "this"), si por estudiante o por empleado
                        mediante el operador de resolucion.

    Nota: Es indistinto por donde sube.
***/
void becario::SetName(string nombre)
{
    this->estudiante::SetName(nombre);
}

void becario::SetDocument(unsigned numero)
{
    this->estudiante::SetDocument(numero);
}

void becario::SetBirthDate(fecha ddmmaa)
{
    this->estudiante::BirthDate.Day = ddmmaa.Day;
    this->estudiante::BirthDate.Month = ddmmaa.Month;
    this->estudiante::BirthDate.Year = ddmmaa.Year;
}

void becario::SetBirthDate(int dia, int mes, int anio)
{
    this->estudiante::BirthDate.Day = dia;
    this->estudiante::BirthDate.Month = mes;
    this->estudiante::BirthDate.Year = anio;
}

/***
    Setters de la clase becario, no necesito el puntero "this", ni el operador de resolucion para subir obviamente.
***/
void becario::SetTipo(string val)
{
    Tipo = val;
}

void becario::SetDuracion(int val)
{
    Duracion = val;
}

void becario::SetLaboratorio(string val)
{
    Laboratorio = val;
}

void becario::SetDirector(string val)
{
    Director = val;
}

/***
    Getters
***/
string becario::GetTipo()
{
    return Tipo;
}

int becario::GetDuracion()
{
    return Duracion;
}

string becario::GetLaboratorio()
{
    return Laboratorio;
}

string becario::GetDirector()
{
    return Director;
}

/***
    Sobrecarga del operador de insercion
***/
ostream& operator<< (ostream& co, const becario &bec)
{
    co << estudiante(bec)
       << "Categoria = " << bec.Categoria << endl
       << "Fecha Ingreso (empleado) = " << bec.empleado::FechaIngreso << endl
       << "Sueldo = " << bec.Sueldo << endl
       << "Tipo de beca = " << bec.Tipo << endl
       << "Duracion = " << bec.Duracion << endl
       << "Lugar trabajo = " << bec.Laboratorio << endl
       << "Nombre director = " << bec.Director << "\n\n";

    return co;
}

/***
    Impresion
***/

void vPrint(becario &bec)
{
    cout << "Nombre = " << bec.estudiante::GetName() << endl
         << "Documento = " << bec.estudiante::GetDocument() << endl
         << "Fecha Nacimiento = " << bec.estudiante::GetBirthDate() << endl
         << "Categoria = " << bec.GetCategoria() << endl
         << "Fecha Ingreso = " << bec.empleado::FechaGetIngreso() << endl
         << "Sueldo = " << bec.GetSueldo() << endl
         << "Carrera = " << bec.GetCarrera() << endl
         << "Fecha Ingreso = " << bec.estudiante::GetFechaIngreso() << endl
         << "Cantidad de materias = " << bec.GetMaterias() << endl
         << "Promedio = " << bec.GetPromedio() << endl
         << "Tipo de beca = " << bec.GetTipo() << endl
         << "Duracion = " << bec.GetDuracion() << endl
         << "Lugar trabajo = " << bec.GetLaboratorio() << endl
         << "Nombre director = " << bec.GetDirector() << "\n\n";
}
