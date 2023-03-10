#ifndef CPOLINOMIO_H_INCLUDED
#define CPOLINOMIO_H_INCLUDED

#include "CTermino.h"
#include <vector>

using namespace std;

class CPolinomio
{
    public:
        CPolinomio();
        void AsignarTermino(CTermino termino);
        CPolinomio operator+(CPolinomio& polB);
        friend ostream& operator<<(ostream& os, CPolinomio& polX);
        double operator()(double x);
        operator double();

        int ObtenerNroTerminos();

    private:
        vector<CTermino> polinomio;

};

#endif // CPOLINOMIO_H_INCLUDED
