#ifndef CRADIORELOJ_H_INCLUDED
#define CRADIORELOJ_H_INCLUDED

#include "cRadio.h"
#include "cReloj.h"

enum TipoAlarma {Musica, Timbre};

class cRadioReloj: public cRadio, public cReloj
{
    private:
        cTime alarma;
        TipoAlarma tipo;
        bool prendido;

    public:
        cRadioReloj(cTime reloj = cTime(23, 59, 59),
                    cTime alarma = cTime(0, 0, 0),
                    TipoAlarma tipoAlarma = Timbre,
                    bool prendidoAlarma = false,
                    float frecuencia = 100.1,
                    TipoDeBanda banda = FM,
                    bool prendidoRadio = false);
        //Destructor de oficio

        void setPrendido(bool);
        void setAlarma(unsigned int, unsigned int, unsigned int);
        //cTime getTiempo();  //Sobrecarga para devolver cTime alarma

        //void incrementarTiempo();
        bool verificarAlarma();
};

#endif // CRADIORELOJ_H_INCLUDED
