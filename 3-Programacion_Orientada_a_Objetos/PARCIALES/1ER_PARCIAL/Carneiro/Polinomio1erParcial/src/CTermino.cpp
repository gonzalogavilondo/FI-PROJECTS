#include "CTermino.h"

CTermino::CTermino()
{
    coeficiente = 0;
    exponente = 0;
}
CTermino::CTermino(float coef, int exp)
{
    coeficiente = coef;
    exponente = exp;
}
CTermino::~CTermino()
{
    //dtor
}
/***********************/
void CTermino::VisualizarTermino()
{
    cout << showpos << coeficiente << " x ( " << exponente << " ) ";     //showpos-> muestra el signo
}
bool CTermino::operator== (const CTermino &ct)
{
    if(coeficiente==ct.coeficiente && exponente==ct.exponente)
        return true;
    else
        return false;
}
bool CTermino::operator< (const CTermino &ct)
{
    if( (exponente<ct.exponente) || (exponente>=ct.exponente && coeficiente<ct.coeficiente) )
        return true;
    else
        return false;
}
