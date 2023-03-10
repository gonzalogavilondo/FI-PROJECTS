#ifndef CTERMINO_H
#define CTERMINO_H

#include <iostream>

using namespace std;

class CTermino
{
    public:
        CTermino();
        CTermino(float coef, int exp);
        ~CTermino();

        ///sets///
        void AsignarCoeficiente(float val) { coeficiente = val; }
        void Setexponente(int val) { exponente = val; }

        ///gets///
        float ObtenerCoeficiente() { return coeficiente; }
        int ObtenerExponente() { return exponente; }

        ///metodos///
        void VisualizarTermino();


        ///sobrecarga///
        bool operator== (const CTermino &ct);
        bool operator< (const CTermino &ct);

    protected:

    private:
        float coeficiente;
        int exponente;
};

#endif // CTERMINO_H
