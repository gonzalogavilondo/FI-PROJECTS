#ifndef CRACIONAL_H
#define CRACIONAL_H

#include <iostream>
#include <math.h>
using namespace std;

class CRacional
{
    public:
        ///Constructores
        CRacional(int num = 0, int den = 1);
        CRacional(const CRacional&);

        ///Getters
        int GetNum();
        int GetDen();

        ///Setters
        void SetNum(int);
        void SetDen(int);

        ///Sobrecarga del operador de extraccion y de insercion
        friend istream& operator>> (istream&, CRacional&);
        friend ostream& operator<< (ostream&, const CRacional&);

        ///Sobrecarga de operadores aritméticos
        CRacional operator+ (const CRacional&);
        CRacional operator- (const CRacional&);
        CRacional operator* (const CRacional&);
        CRacional operator/ (const CRacional&);
        CRacional operator- () const; //Numero negativo (ej: Quiero obtener el racional de -a).
                                      //Tiene el const porque no quiero cambiar el valor del objeto que llama a la funcion (a)

        CRacional& operator+= (const CRacional&);
        CRacional& operator-= (const CRacional&);

        CRacional& operator++ (); //Preincremento
        CRacional operator++ (int); //Postincremento
        CRacional& operator-- (); //Predecremento
        CRacional operator-- (int);//Postdecremento

        friend CRacional operator+ (const int&, const CRacional&);

        ///Sobrecarga de operadores de comparacion
        bool operator!= (const CRacional&);
        bool operator== (const CRacional&);
        bool operator< (const CRacional&);
        bool operator> (const CRacional&);
        bool operator<= (const CRacional&);
        bool operator>= (const CRacional&);
        bool operator! ();

        ///Funcion que simplifica la fraccion
        int mcd(int, int);
        friend void simplificar(CRacional&);


    protected:

    private:
        int num;
        int den;

};

#endif // CRACIONAL_H
