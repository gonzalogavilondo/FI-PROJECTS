#include "Fecha.h"
#include <ctime>
#include <string.h>

/**
    Constructor
**/

Fecha::Fecha()
{
    time_t t = time(0);   // get time now
    struct tm * now = localtime( & t );
    day = now->tm_mday;
    month = (now->tm_mon + 1);
    year = (now->tm_year + 1900);  // No hace falta validar porque es la fecha actual

    name = NULL;

}

/**
    Destructor
**/
Fecha::~Fecha()
{
    if(name != NULL)
    {
        delete [] name;
    }
}

/**
    Getters y Setters
**/

int Fecha::GetDay()
{
     return day;
}

void Fecha::SetDay(int val)
{
    if(val >= 1 && val <= 31)
    {
        day = val;
    }
    else
    {
        cout << "Ingreso un dia incorrecto" << endl;
        exit(1);
    }
}

int Fecha::GetMonth()
{
    return month;
}

void Fecha::SetMonth(int val)
{
    if(val >= 1 && val <= 12)
    {
        month = val;
    }
    else
    {
        cout << "Ingreso un mes incorrecto" << endl;
        exit(2);
    }
}

int Fecha::GetYear()
{
     return year;
}

void Fecha::SetYear(int val)
{
     if(val >= 1 && val <= 2021)
    {
        year = val;
    }
    else
    {
        cout << "Ingreso un anio incorrecto" << endl;
        exit(3);
    }
}

void Fecha::SetFecha(int in_day, int in_month, int in_year)
{
    SetDay(in_day);
    SetMonth(in_month);
    SetYear(in_year);
    ValidarFecha();
}

/**
    Funciones del problema
**/

void Fecha::IngresarFecha()
{
    int in_day,
        in_month,
        in_year;

    cout << "Ingrese el dia: ";
    cin >> in_day;

    cout << "Ingrese el mes: ";
    cin >> in_month;

    cout << "Ingrese el anio: ";
    cin >> in_year;

    SetFecha(in_day, in_month, in_year);
}

void Fecha::Imprimir_la()
{
    cout << day << '/' << month << '/' << year << endl;
}

void Fecha::Imprimir_us()
{
    cout << month << '/' << day << '/' << year << endl;
}

void Fecha::Imprimir_letras()
{

}

char* Fecha::MesLetras(int month)
{
    string monthName;

    switch(month)
    {
        case 1:
        {
            monthName = "Enero";
        }
        break;
        case 2:
        {
            monthName = "Febrero";
        }
        break;
        case 3:
        {
            monthName = "Marzo";
        }
        break;
        case 4:
        {
            monthName = "Abril";
        }
        break;
        case 5:
        {
            monthName = "Mayo";
        }
        break;
        case 6:
        {
            monthName = "Junio";
        }
        break;
        case 7:
        {
            monthName = "Julio";
        }
        break;
        case 8:
        {
            monthName = "Agosto";
        }
        break;
        case 9:
        {
            monthName = "Septiembre";
        }
        break;
        case 10:
        {
            monthName = "Octubre";
        }
        break;
        case 11:
        {
            monthName = "Noviembre";
        }
        break;
        case 12:
        {
            monthName = "Diciembre";
        }
        break;
    }
    name = new char[monthName.length() + 1];
    strcpy(name, monthName.c_str());

    return name;
}

bool Fecha::ValidarFecha()
{

    return true;
}
