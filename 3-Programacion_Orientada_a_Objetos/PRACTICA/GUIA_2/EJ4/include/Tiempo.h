#ifndef TIEMPO_H
#define TIEMPO_H

#include <iostream>
#include <string>
using namespace std;

class Tiempo
{
    public:
        Tiempo();
        Tiempo(int, int, int);

        int Gethora();
        void Sethora(int);
        int Getminutos();
        void Setminutos(int);
        int Getsegundos();
        void Setsegundos(int);

        void setDatos(int, int, int);
        void ingresarDatos();
        void muestra_fmt_estandard();
        void muestra_fmt_universal();

    protected:

    private:
        int hora;
        int minutos;
        int segundos;
};

#endif // TIEMPO_H
