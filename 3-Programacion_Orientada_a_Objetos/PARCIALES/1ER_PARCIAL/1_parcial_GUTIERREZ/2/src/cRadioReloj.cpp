#include "cRadioReloj.h"
#include "string.h"

/************************************************************************/
/*                             CLASE cTime                              */
/************************************************************************/

//Constructores
cTime::cTime(unsigned int hh, unsigned int mm, unsigned int ss){
    hora = hh;
    minuto = mm;
    segundo = ss;
}

//Getters y Setters
void cTime::setHora(unsigned int hh){
    hora = hh;
}

void cTime::setMinuto(unsigned int mm){
    minuto = mm;
}

void cTime::setSegundo(unsigned int ss){
    segundo = ss;
}

unsigned int cTime::getHora(){
    return hora;
}

unsigned int cTime::getMinuto(){
    return minuto;
}

unsigned int cTime::getSegundo(){
    return segundo;
}

//Sobrecarga del operador de inserción y extracción
ostream& operator << (ostream& co, cTime& tim){
    co << tim.hora << ':' << tim.minuto << ':' << tim.segundo;

    return co;
}

/************************************************************************/
/*                             CLASE cReloj                             */
/************************************************************************/

//Constructores y Destructores
cReloj::cReloj(unsigned int hh, unsigned int mm, unsigned int ss){
    time = cTime(hh, mm, ss);
}

cReloj::cReloj(const cTime& tim){
    time = cTime(tim);
}

cReloj::cReloj(const cReloj& rel){
    setTiempo(rel.time);
    setMarca(rel.marca);
}

cReloj::~cReloj(){
    delete marca;
}

//Setters y Getters
void cReloj::setTiempo(int hh, int mm, int ss){
    time = cTime(hh, mm, ss);
}

void cReloj::setTiempo(const cTime& tiempo){
    time = tiempo;
}

void cReloj::setMarca(const char *stMarca){
    marca = new char[strlen(stMarca) + 1];
    strcpy(marca, stMarca);
}

cTime cReloj::getTiempo(){
    return time;
}

char *cReloj::getMarca(){
    char *aux = new char[strlen(marca) + 1];
    strcpy(aux, marca);
    return aux;
}

//Se le pasan segundos y aumenta el tiempo
void cReloj::incrementarTiempo(){
    if (time.getSegundo() < 59){
        time.setSegundo(time.getSegundo() + 1);
    } else {

        int resto = time.getSegundo() % 60;
        int cociente = (time.getSegundo() / 60 - resto) * 60;

        if (resto < 59){
            time.setSegundo(time.getSegundo() + cociente);
            time.setMinuto(time.getMinuto() + resto);
        } else {
            time.setMinuto(time.getMinuto() + cociente);
            time.setHora(time.getHora() + resto);
        }
    }
}

/************************************************************************/
/*                             CLASE cRadio                             */
/************************************************************************/

//Constructores
cRadio::cRadio(float frec, TipoDeBanda band, bool prend){
    frecuencia = frec;
    banda = band;
    prendido = prend;
}

//Setters y Getters
void cRadio::setFrecuencia(float frec){
    frecuencia = frec;
}

void cRadio::setBanda(TipoDeBanda band){
    banda = band;
}

void cRadio::setPrendido(bool prend){
    prendido = prend;
}

float cRadio::getFrecuencia(){
    return frecuencia;
}

TipoDeBanda cRadio::getBanda(){
    return banda;
}

bool cRadio::getPrendido(){
    return prendido;
}

/************************************************************************/
/*                             CLASE cRadioReloj                        */
/************************************************************************/

//Constructores
cRadioReloj::cRadioReloj(const cTime& rel, const cTime& alar,
                        TipoAlarma tipA, bool prendA, float frec,
                        TipoDeBanda tipR, bool prendR) :
                        cRadio(frec, tipR, prendR), cReloj(rel){

    alarma = cTime(alar);
    tipo = tipA;
    prendido = prendA;
}

//Setters y Getters
void cRadioReloj::setAlarma(int hh, int mm, int ss){
    alarma = cTime(hh, mm, ss);
}

void cRadioReloj::setAlarma(const cTime& tim){
    alarma = tim;
}

void cRadioReloj::setTipo(TipoAlarma tip){
    tipo = tip;
}

void cRadioReloj::setPrendido(bool prend){
    prendido = prend;
}

cTime cRadioReloj::getAlarma(){
    return alarma;
}

TipoAlarma cRadioReloj::getTipo(){
    return tipo;
}

bool cRadioReloj::getPrendido(){
    return prendido;
}

//Funciones
bool cRadioReloj::verificarAlarma(){
    return (prendido ? 1 : 0);
}
