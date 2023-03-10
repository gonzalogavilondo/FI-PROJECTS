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
        int GetDay();
        void SetDay(int);
        int GetMonth();
        void SetMonth(int);
        int GetYear();
        void SetYear(int);
        int GetFecha();
        void SetFecha(int, int, int);

        //Funciones
        void IngresarFecha();
        void Imprimir_la();
        void Imprimir_us();
        void Imprimir_letras();
        char* MesLetras(int);
        bool ValidarFecha();


    protected:

    private:
        int day;
        int month;
        int year;
};

#endif // FECHA_H
