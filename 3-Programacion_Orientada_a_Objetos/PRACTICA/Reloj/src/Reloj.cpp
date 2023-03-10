#include "Reloj.h"

/***
    Constructor
***/
Reloj::Reloj()
{
    time_t now = time(0);
    tm *time = localtime(&now); // Estructura de datos tm para personalizar la hora
    hour = time->tm_hour;
    min = time->tm_min;
    sec = time->tm_sec;
}

/***
    Destructor
***/
Reloj::~Reloj()
{
    //dtor
}

/***
    Getters y setters
***/
int Reloj::getHour()
{
     return hour;
}

void Reloj::setHour(int val)
{
     hour = val;
}

int Reloj::getMin()
{
     return min;
}

void Reloj::setMin(int val)
{
     min = val;
}

int Reloj::getSec()
{
     return sec;
}

void Reloj::setSec(int val)
{
     sec = val;
}


/***
    Sobrecarga los operadores de insercion
***/
istream& operator >> (istream& ci, Reloj& creloj)
{
    ci >> creloj.hour;
    ci >> creloj.min;
    ci >> creloj.sec;

    return ci;
}

ostream& operator << (ostream& co, Reloj& creloj)
{
    co << creloj.hour << ":";
    co << creloj.min << ":";
    co << creloj.sec;

    return co;
}


/***
    Metodos propios de la clase reloj
***/
void Reloj::printRelojActualizandose(ostream& co)
{
    // Ahora convertimos a string para que aparezca por ej: 01 minutos
    while(true) //Bucle infinito para actualizar la hora a la hora de imprimir
    {
        time_t now = time(0);
        tm *time = localtime(&now); // Estructura de datos tm para personalizar la hora
        hour = time->tm_hour;
        min = time->tm_min;
        sec = time->tm_sec;

        ostringstream h;
        ostringstream m;
        ostringstream s;
        h << hour;
        m << min;
        s << sec;

        // Horas
        string horas;
        if(h.str().size() == 1) // Si solo contiene un digito -> formateamos
        {
            horas = "0" + h.str();
        }
        else // Si no contiene solo un digito, lo mantenemos igual
        {
            horas = h.str();
        }

        // Minutos
        string minutos;
        if(m.str().size() == 1)
        {
            minutos = "0" + m.str();
        }
        else
        {
            minutos = m.str();
        }

        // Segundos
        string segundos;
        if(s.str().size() == 1)
        {
            segundos = "0" + s.str();
        }
        else
        {
            segundos = s.str();
        }
        co << horas << ":" << minutos << ":" << segundos;
        Sleep(1000); // Para que se actualice cada 1000 ms = 1 seg
        system("cls"); // Limpiar el contenido de la consola

    }
}

void Reloj::printReloj(ostream& co)
{
    co << hour << ":"
       << min << ":"
       << sec << endl;
}
