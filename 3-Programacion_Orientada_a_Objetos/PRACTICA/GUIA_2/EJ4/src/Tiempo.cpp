#include "Tiempo.h"

/**
    Constructores
**/

Tiempo::Tiempo()
{
    hora = 0;
    minutos = 0;
    segundos = 0;
}

Tiempo::Tiempo(int in_hora, int in_minutos, int in_segundos)
{
    setDatos(in_hora, in_minutos, in_segundos);
}

/**
    Setters y Getters
**/

int Tiempo::Gethora()
{
     return hora;
}

void Tiempo::Sethora(int val)
{
    if(val >= 1 && val <= 24)
    {
        hora = val;
    }
    else
    {
        cout << "Ha ingresado una hora invalida" << endl;
        exit(1);
    }
}

int Tiempo::Getminutos()
{
    return minutos;
}

void Tiempo::Setminutos(int val)
{
    if(val >= 1 && val <= 59)
    {
        minutos = val;
    }
    else
    {
        cout << "Ha ingresado minutos invalidos" << endl;
        exit(2);
    }
}

int Tiempo::Getsegundos()
{
     return segundos;
}

void Tiempo::Setsegundos(int val)
{
     if(val >= 1 && val <= 59)
    {
        segundos = val;
    }
    else
    {
        cout << "Ha ingresado segundos invalidos" << endl;
        exit(3);
    }
}

void Tiempo::setDatos(int in_hora, int in_minutos, int in_segundos)
{
    Sethora(in_hora);
    Setminutos(in_minutos);
    Setsegundos(in_segundos);
}

/**
    Metodos del problema en si
**/

void Tiempo::ingresarDatos()
{

}

void Tiempo::muestra_fmt_estandard()
{
    cout << "Tiempo = " << Gethora() << ":"
         << Getminutos() << ":"
         << Getsegundos() << " Hs" <<endl;

}

void Tiempo::muestra_fmt_universal()
{
    cout << "Tiempo = " << Gethora() << ":"
         << Getminutos() << ":"
         << Getsegundos() << " Hs" <<endl;
}

