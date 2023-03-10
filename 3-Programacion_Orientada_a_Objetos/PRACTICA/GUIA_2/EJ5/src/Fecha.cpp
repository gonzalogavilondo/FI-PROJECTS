#include "Fecha.h"
#include <ctime>
#include <string>
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
    //free(name);
    delete [] name;
}

/**
    Getters y Setters
**/

int Fecha::Getday()
{
     return day;
}

void Fecha::Setday(int val)
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

int Fecha::Getmonth()
{
    return month;
}

void Fecha::Setmonth(int val)
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

int Fecha::Getyear()
{
     return year;
}

void Fecha::Setyear(int val)
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

void Fecha::Setfecha(int in_day, int in_month, int in_year)
{
    Setday(in_day);
    Setmonth(in_month);
    Setyear(in_year);
    validarFecha();
}

/**
    Funciones del problema
**/

void Fecha::ingresarFecha()
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

    Setfecha(in_day, in_month, in_year);
}

void Fecha::imprimir_la()
{
    cout << day << '/' << month << '/' << year << endl;
}

void Fecha::imprimir_us()
{
    cout << month << '/' << day << '/' << year << endl;
}

void Fecha::imprimir_letras()
{

}

char* Fecha::mesLetras(int month)
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
//    name = (char*)malloc(sizeof(char)*(monthName.length() + 1));
//    strcpy(name, monthName.c_str());

    return name;
}

bool Fecha::validarFecha()
{

    return true;
}
