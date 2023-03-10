#ifndef CTERMINO_H_INCLUDED
#define CTERMINO_H_INCLUDED

#include <iostream>
#include <iomanip>

class CTermino
{
    public:
        CTermino(float coef = 0, int exp = 0);

        void AsignarCoeficiente(float);
        float ObtenerCoeficiente();

        void AsignarExponente(int);
        int ObtenerExponente();

        void VisualizarTermino();

        bool operator== (const CTermino&);
        bool operator< (const CTermino&);

    private:
        float coeficiente;
        int exponente;
};

#endif // CTERMINO_H_INCLUDED
