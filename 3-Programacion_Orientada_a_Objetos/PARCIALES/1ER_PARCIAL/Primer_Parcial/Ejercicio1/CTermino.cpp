#include "CTermino.h"

using namespace std;

CTermino::CTermino(float coef, int exp)
{
    AsignarCoeficiente(coef);
    AsignarExponente(exp);
}

void CTermino::AsignarCoeficiente(float coef)
{
    coeficiente = coef;
}

float CTermino::ObtenerCoeficiente()
{
    return coeficiente;
}

void CTermino::AsignarExponente(int exp)
{
    exponente = exp;
}

int CTermino::ObtenerExponente()
{
    return exponente;
}

void CTermino::VisualizarTermino()
{
    cout << showpos << coeficiente;
    if(exponente > 0)
        cout << "x^" << noshowpos << exponente;
}

bool CTermino::operator== (const CTermino& termino)
{
    if (this->coeficiente == termino.coeficiente && this->exponente == termino.exponente)
        return true;
    else
        return false;
}

bool CTermino::operator< (const CTermino& termino)
{
    //El orden de los términos es según el exponente
    if(this->exponente < termino.exponente)
        return true;
    else
        return false;
}
