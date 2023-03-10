// fichero complejos.h
// declaraci�n de la clase complejo

#ifndef COMPLEJOS_H_INCLUDED
#define COMPLEJOS_H_INCLUDED

#include <iostream>
#include <math.h>

using namespace std;

class complejo
{
    public:
        /// Constructores
        //complejo(void);
        complejo(double re = 0, double im = 0.0);
        //complejo(const complejo&);     // constructor de copia proporcionado por el sistema

        /// Sets
        void SetData(void);
        void SetReal(double);
        void SetImag(double);

        /// Gets
        double GetReal();
        double GetImag();

        /// Sobrecarga del operador de inserci�n en el stream de salida
        friend ostream& operator<< (ostream&, const complejo&);

        /// Sobrecarga de operadores aritm�ticos
        complejo operator+ (const complejo&);
        complejo operator- (const complejo&);
        complejo operator* (const complejo&);
        complejo operator/ (const complejo&);
        complejo operator+= (const complejo&);
        complejo& operator++();
        complejo& operator++(int);
        friend complejo operator+ (double, complejo);


        /// Sobrecarga del operador de asignaci�n
        complejo operator= (const complejo&);      // retorna una referencia para poder hacer a = b = c

        /// Sobrecarga de operadores de comparaci�n
        friend bool operator!= (const complejo&, const complejo&);   // mas amigable al utilizar 2 operandos en la comparacion
        // friend int operator== (const complejo&, const complejo&);
        bool operator== (const complejo&);           // sin utilizar el modificador friend

    protected:
        double m_real;
        double m_imag;
};

#endif
