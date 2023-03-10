#ifndef POLINOMIO_H_INCLUDED
#define POLINOMIO_H_INCLUDED

#include <iostream>
#include <vector>
using namespace std;

class CTermino
{
    public:
        ///Constructores
        CTermino(float coef = 0.0, int exp = 0); //Constructor por default

        ///Getters
        float ObtenerCoeficiente();
        int ObtenerExponente();

        ///Setters
        void AsignarCoeficiente(float);
        void AsignarExponente(int);

        ///Sobrecarga de operadores de comparacion
        bool operator== (const CTermino&);;
        bool operator< (const CTermino&);

        ///Funciones propias de CTermino
        void VisualizarTermino();

    private:
        float coeficiente;
        int exponente;


};

class CPolinomio
{
    public:
        ///Constructores
        CPolinomio();

        ///Getters


        ///Setters


        ///Sobrecarga del operador de insercion
        friend ostream& operator<< (ostream&, CPolinomio&);

        ///Sobrecarga de operadores aritméticos
        CPolinomio operator+ (CPolinomio&);

        ///Operador llamada a función
        double operator()(double);

        ///Operador de conversión de CPolinomio a double
        operator double();

        ///Funciones propias de polinomio
        void AsignarTermino(CTermino);
        size_t ObtenerNroTerminos();

    protected:
        vector <CTermino> polinomio;

};

#endif // POLINOMIO_H_INCLUDED
