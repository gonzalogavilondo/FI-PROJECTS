#ifndef CALCULADORA_H_INCLUDED
#define CALCULADORA_H_INCLUDED

#include "complejos.h"
#include <iostream>
#include <limits>
#include <iomanip>
#include <string>

using namespace std;

template <class T = double> class CCalculadora //declaracion
{
    private:
        T obj1;
        T obj2;

    public:
        ///Constructor
        CCalculadora();

        ///Destructor
        ~CCalculadora();

        ///Getters y Setters
        void SetObj1(T);
        void SetObj2(T);
        void SetearObjetos();
        T GetObj1();
        T GetObj2();

        ///Funciones genericas
        T suma(T, T);
        T resta(T, T);
        T multiplicacion(T, T);
        T division(T, T);

        ///Menu
        void Menu();
        int CrearMenu(const char* [], int);
};

#include "calculadora.h_c.txt" //NO SE INCLUYE EL ARCHIVO EN EL PROYECTO


#endif // CALCULADORA_H_INCLUDED
