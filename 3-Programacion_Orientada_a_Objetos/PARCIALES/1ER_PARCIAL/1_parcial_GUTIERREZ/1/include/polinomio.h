#ifndef POLINOMIO_H
#define POLINOMIO_H
#include <iostream>
#include "polinomio.h"
#include <vector>
using namespace std;

class CTermino
{
    public:
        //Constructores
        CTermino(float c = 0, int e = 0);

        //Setters y Getters
        void AsignarCoeficiente(float);
        float ObtenerCoeficiente();
        int ObtenerExponente();

        //Sobrecarga de operadores aritméticos y lógicos
        bool operator== (const CTermino&);
        bool operator< (const CTermino&);

        //Impresión
        void VisualizarTermino();

    private:
        float coeficiente;
        int exponente;

};

class CPolinomio
{
    public:
        //Constructores
        CPolinomio();

        //Setters y Getters
        void AsignarTermino(CTermino);
        size_t ObtenerNroTerminos();

        //Sobrecarga de operadores aritméticos y lógicos
        CPolinomio operator+(CPolinomio&);

        //Sobrecarga del operador de inserción y extracción
        friend ostream& operator<<(ostream&, CPolinomio&);

        double operator()(double);
        operator double();

    private:
        vector<CTermino> polinomio;
};

#endif // POLINOMIO_H
