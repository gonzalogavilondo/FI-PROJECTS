#include "cRadioReloj.h"

/***
    Constructor de cTime
***/
cTime::cTime(unsigned int h, unsigned int m, unsigned int s)
{
    hora = h;
    minuto = m;
    segundo = s;
}

/***
    Getters de cTime
***/
int cTime::getHora()
{
    return hora;
}

int cTime::getMinuto()
{
    return minuto;
}

int cTime::getSegundo()
{
    return segundo;
}

/***
    Setters de cTime
***/
void cTime::setHora(int val)
{
    hora = val;

}

void cTime::setMinuto(int val)
{
    minuto = val;
}

void cTime::setSegundo(int val)
{
    segundo = val;
}

/***
    Sobrecarga del operador de insercion para cTime
***/
ostream& operator<< (ostream& co, const cTime& cT)
{
    co << cT.hora  << ":" << cT.minuto << ":" << cT.segundo;

    return co;
}

////////////////////////////////////////////////////

/***
    Constructor de cReloj
***/
cReloj::cReloj(unsigned int hora, unsigned int minuto, unsigned int segundo)
{
    time.setHora(hora);
    time.setMinuto(minuto);
    time.setSegundo(segundo);
}

cReloj::cReloj(cTime tiempo, const char* val)
{
    //Inicializamos atributo time
    tiempo.setHora(0);
    tiempo.setMinuto(0);
    tiempo.setSegundo(0);
    //Inicializamos atributo marca
    marca = new char[strlen(val) + 1];
    strcpy(marca, val);

}
/***
    Constructor de copia de cReloj
***/
cReloj::cReloj(const cReloj& cRel)
{
    //Inicializamos atributo time
    time.setHora(0);
    time.setMinuto(0);
    time.setSegundo(0);
    //Inicializamos atributo marca
    marca = new char[strlen(cRel.marca) + 1];
    strcpy(marca, cRel.marca);

}

/***
    Destructor de cReloj
***/
cReloj::~cReloj()
{
    delete [] marca; //Elimino una cadena de caracteres, si es un solo caracter, se adapta
}

/***
    Getters de cReloj
***/
cTime cReloj::getTiempo()
{
    return time;
}

char cReloj::getMarca()
{
    return *marca;
}

/***
    Setters de cReloj
***/
void cReloj::setTiempo(cTime val)
{
    time = val;
}

void cReloj::setTiempo(int h, int m, int s)
{
    time.setHora(h);
    time.setMinuto(m);
    time.setSegundo(s);
}

void cReloj::setMarca(const char *val)
{
    marca = new char[strlen(val) + 1];
    strcpy(marca, val);
}

////////////////////////////////////////////////////

/***
    Constructor de cRadio
***/
cRadio::cRadio(float f, TipoDeBanda b, bool p)
{
    frecuencia = f;
    banda = b;
    prendido = p;
}

/***
    Constructor de copia de cRadio
***/

cRadio::cRadio(const cRadio& cRad)
{
    frecuencia = cRad.frecuencia;
    banda = cRad.banda;
    prendido = cRad.prendido;
}

/***
    Getters de cRadio
***/
float cRadio::getFrecuencia()
{
    return frecuencia;
}

TipoDeBanda cRadio::getBanda()
{
    return banda;
}

bool cRadio::getPrendido()
{
    return prendido;
}

/***
    Setters de cRadio
***/
void cRadio::setFrecuencia(float val)
{
    frecuencia = val;
}

void cRadio::setBanda(TipoDeBanda val)
{
    banda = val;
}

void cRadio::setPrendido(bool val)
{
    prendido = val;
}

/***
    Funcion propia de cRadio
***/
void cReloj::incrementarTiempo()
{
    if(time.getSegundo() > 59)
    {
        while(time.getSegundo() > 59)
        {
            time.setSegundo(time.getSegundo() - 59);
            time.setMinuto(time.getMinuto() + 0.0166667 * time.getSegundo()); //1seg = 0.0166667 minutos. Le agregamos cuantos minutos se paso.
        }
    }
    else if(time.getMinuto() > 59)
    {
        while(time.getMinuto() > 59)
        {
            time.setMinuto(time.getMinuto() - 59);
            time.setHora(time.getHora() + 0.0166667 * time.getMinuto()); //1seg = 0.0166667 minutos. Le agregamos cuantos minutos se paso.
        }
    }
    else if(time.getHora() > 23)
    {
        cout << "Error. Ha introducido una hora incorrecta." << endl;
        exit(1); //Codigo de error: 1
    }
}

////////////////////////////////////////////////////

/***
    Constructor de cRadioReloj
***/
cRadioReloj::cRadioReloj(cTime tiempoCRel, cTime tiempoAlar,
                         float frec, TipoDeBanda band, bool prenCRadio,
                         const char* marc,
                         TipoAlarma tip, bool prenCRadioRel):

//Inicializo en el orden que heredo
cRadio(frec, band, prenCRadio),
cReloj(tiempoCRel, marc)
{
    alarma = tiempoAlar;
    tipo = tip;
    prendido = prenCRadioRel;
}

/***
    Getters de cRadioReloj
***/
cTime cRadioReloj::getAlarma()
{
    return alarma;
}

TipoAlarma cRadioReloj::getTipo()
{
    return tipo;
}

bool cRadioReloj::getPrendido()
{
    return prendido;
}

/***
    Setters de cRadioReloj
***/
void cRadioReloj::setAlarma(unsigned int hora, unsigned int minuto, unsigned int segundo)
{
    alarma.setHora(hora);
    alarma.setMinuto(minuto);
    alarma.setSegundo(segundo);
}

void cRadioReloj::setTipo(TipoAlarma val)
{
    tipo = val;
}

void cRadioReloj::setPrendido(bool val)
{
    prendido = val;
}

/***
    Funciones propias de cRadioReloj
***/
bool cRadioReloj::verificarAlarma()
{
    if(prendido)
    {
        return true;
    }
    else
    {
        return false;
    }
}
