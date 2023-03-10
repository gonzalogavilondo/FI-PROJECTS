// fichero complejos.h
// declaración de la clase complejo

#ifndef COMPLEJOS_H_INCLUDED
#define COMPLEJOS_H_INCLUDED

#include <iostream>

using namespace std;

class complejo
{
    protected:
        double real;
        double imag;

    public:
        /// Constructores
        complejo(double re = 0, double im = 0);

        /// Setters
        void SetData(void);
        void SetReal(double);
        void SetImag(double);

        /// Getters
        double GetReal();
        double GetImag();

        /// Sobrecarga del operador de extraccion y de insercion
        friend ostream& operator<< (ostream&, const complejo&);
        friend istream& operator>> (istream&, complejo&);

        /// Sobrecarga de operadores aritméticos
        complejo operator+ (const complejo&);
        complejo operator- (const complejo&);
        complejo operator* (const complejo&);
        complejo operator/ (const complejo&);
        complejo operator- () const;

        complejo& operator+= (const complejo&);
        complejo& operator-= (const complejo&);

        complejo& operator++ ();        //Pre incremento
        complejo operator++ (int);      //Post incremento
        complejo& operator-- ();        //Pre decremento
        complejo operator-- (int);      //Post decremento

        friend complejo& operator+ (double, const complejo&);

        /// Sobrecarga del operador de asignación
        complejo& operator= (const complejo&);      // retorna una referencia para poder hacer a = b = c

        /// Sobrecarga de operadores de comparación
        bool operator== (const complejo&);
        friend bool operator!= (const complejo&, const complejo&);
};

#endif
