#ifndef POLINOMIO_H_INCLUDED
#define POLINOMIO_H_INCLUDED

#include <iostream>
#include <vector>

#include "CTermino.h"

using namespace std;

class CPolinomio
{
    public:
            ///ctor///
            CPolinomio();
            CPolinomio(const CPolinomio &cp);   //ctor de copia//
            ///destructor///
            ~CPolinomio();
            ///sets///


            ///gets///
            int ObtenerNroTerminos(){return NroTerminos;}


            ///metodos///
            void AsignarTermino(CTermino termino);


            ///sobrecarga de operadores///
            CPolinomio operator+(CPolinomio& polB);

            //***********/
            friend ostream& operator<<(ostream& os, CPolinomio& polX);

            double operator()(double x);
            operator double();

    protected:
    private:
            vector <CTermino> polinomio;
            int NroTerminos;
};

#endif // POLINOMIO_H_INCLUDED
