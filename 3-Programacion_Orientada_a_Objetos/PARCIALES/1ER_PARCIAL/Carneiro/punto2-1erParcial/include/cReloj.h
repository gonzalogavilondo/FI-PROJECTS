#ifndef CRELOJ_H
#define CRELOJ_H

#include <iostream>
#include <cstring>
#include <string.h>

#define MAX_MARCA 50

using namespace std;

class cTime
{
    public:
            cTime(unsigned int horaIn=0, unsigned int minutoIn=0, unsigned int segundoIn=0);
            void SetHora(unsigned int val) { hora = val; }
            void SetMinuto(unsigned int val) { minuto = val; }
            void SetSegundo(unsigned int val) { segundo = val; }

            ///sobrecarga///
            friend ostream& operator<< (ostream &co, const cTime &ct);

    protected:
    private:
            unsigned int hora;
            unsigned int minuto;
            unsigned int segundo;
};

class cReloj
{
    public:
        cReloj(cTime timeIn);
        cReloj(unsigned int hr=0, unsigned int min=0, unsigned int seg=0);  //parametros por defecto
        cReloj(const cReloj &c);   //ctor de copia
        ~cReloj();

        ///sets///
        void Settime(cTime val) { time = val; }
        void setMarca(char *val) { strcpy(marca, val); }

        void setTiempo(int hr, int min, int seg);
        ///gets///
        cTime getTiempo() { return time; }
        char* Getmarca() { return marca; }

    private:
    protected:      //como protected ya que es heredada//
        cTime time;
        char* marca;
};

enum TipoDeBanda {AM, FM};
class cRadio
{
    public:
            cRadio(float frec=95.5, TipoDeBanda ban=FM, bool pren=false);
            cRadio(const cRadio &cr);   //ctor de copia//

            void setBanda(TipoDeBanda tipoBandaIn);
            void setPrendido(bool pren){prendido = pren;}
    private:
    protected:  //como protected ya que es heredada//
            float frecuencia;
            TipoDeBanda banda;
            bool prendido;
};

enum TipoAlarma {Musica, Timbre};
class cRadioReloj: public cRadio, public cReloj
{
    public:
            cRadioReloj(cTime timeIn=cTime(), cTime alarmaIn=cTime(), TipoAlarma tipoAlarmaIn=Timbre,
                        bool prendidoAlarmaIn = false, float frecuenciaIn=100.1, TipoDeBanda tipoBandaIn=FM, bool prendidoRelojIn=false);

            void setPrendido(bool prendidoIn){prendido = prendidoIn;}
            void setAlarma(int hr, int min, int seg){alarma.SetHora(hr);
                                                     alarma.SetMinuto(min);
                                                     alarma.SetSegundo(seg);}
            bool verificarAlarma();
            //void incrementarTiempo();
    protected:
    private:    //como private ya que es la ultima clase derivada//
            cTime alarma;
            TipoAlarma tipo;
            bool prendido;
};

#endif // CRELOJ_H
