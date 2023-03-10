#ifndef FECHA_H
#define FECHA_H
#include <iostream>
#include <stdlib.h>
#include <stdio.h>

using namespace std;

class Fecha
{
    public:
        Fecha();
        ~Fecha();
        char* name;

        //Setters y getters
        int Getday();
        void Setday(int);
        int Getmonth();
        void Setmonth(int);
        int Getyear();
        void Setyear(int);
        int Getfecha();
        void Setfecha(int, int, int);

        //Funciones
        void ingresarFecha();
        void imprimir_la();
        void imprimir_us();
        void imprimir_letras();
        char* mesLetras(int);
        bool validarFecha();


    protected:

    private:
        int day;
        int month;
        int year;
};

#endif // FECHA_H
