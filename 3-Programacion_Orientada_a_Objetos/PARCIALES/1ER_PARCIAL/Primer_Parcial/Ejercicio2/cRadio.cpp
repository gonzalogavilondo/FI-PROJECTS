#include "cRadio.h"

cRadio::cRadio(float frecuencia, TipoDeBanda banda, bool prendido)
{
    this->frecuencia = frecuencia;
    this->banda = banda;
    this->prendido = prendido;
}

void cRadio::setPrendido(bool prendido)
{
    this->prendido = prendido;
}

void cRadio::setBanda(TipoDeBanda banda)
{
    this->banda = banda;
}

bool cRadio::verificarRadio()
{
    return prendido;
}
