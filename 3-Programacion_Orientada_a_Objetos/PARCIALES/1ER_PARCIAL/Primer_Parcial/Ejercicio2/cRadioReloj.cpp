#include "cRadioReloj.h"

cRadioReloj::cRadioReloj(cTime reloj, cTime alarmaTime, TipoAlarma tipoAlarma,
            bool prendidoAlarma, float frecuencia, TipoDeBanda banda,
            bool prendidoRadio)
    : cRadio(frecuencia, banda, prendidoRadio), cReloj(reloj)
{
    alarma = alarmaTime;
    tipo = tipoAlarma;
    prendido = prendidoAlarma;
}

void cRadioReloj::setPrendido(bool prendido)
{
    this->prendido = prendido;
}

void cRadioReloj::setAlarma(unsigned int hh, unsigned int mm, unsigned int ss)
{
    alarma = cTime(hh, mm, ss);
}

//cTime cRadioReloj::getTiempo();  //Sobrecarga para devolver cTime alarma


bool cRadioReloj::verificarAlarma()
{
    return prendido;
}
