#ifndef CRADIORELOJ_H
#define CRADIORELOJ_H
#include <iostream>
using namespace std;

class cTime
{
    private:
        unsigned int hora;
        unsigned int minuto;
        unsigned int segundo;
    public:
        //Constructores
        cTime(unsigned int hh = 0, unsigned int mm = 0, unsigned int ss = 0);

        //Getters y Setters
        void setHora(unsigned int);
        void setMinuto(unsigned int);
        void setSegundo(unsigned int);
        unsigned int getHora();
        unsigned int getMinuto();
        unsigned int getSegundo();

        //Sobrecarga del operador de inserción y extracción
        friend ostream& operator << (ostream&, cTime&);
};

class cReloj
{
    protected:
        cTime time;
        char *marca;
    public:
        //Constructores
        cReloj(unsigned int hh = 0, unsigned int mm = 0, unsigned int ss = 0);
        cReloj(const cTime&);
        cReloj(const cReloj&);
        ~cReloj();

        //Setters y Getters
        void setTiempo(int, int, int);
        void setTiempo(const cTime&);
        void setMarca(const char *);
        cTime getTiempo();
        char *getMarca();

        //Funciones
        void incrementarTiempo();
};

enum TipoDeBanda {AM, FM};
class cRadio
{
    protected:
        float frecuencia;
        TipoDeBanda banda;
        bool prendido;
    public:
        //Constructores
        cRadio(float frec = 95.5, TipoDeBanda band = FM, bool prend = false);

        //Setters y Getters
        void setFrecuencia(float);
        void setBanda(TipoDeBanda);
        void setPrendido(bool);
        float getFrecuencia();
        TipoDeBanda getBanda();
        bool getPrendido();
};

enum TipoAlarma {Musica, Timbre};
class cRadioReloj: public cRadio, public cReloj
{
    private:
        cTime alarma;
        TipoAlarma tipo;
        bool prendido;
    public:
        //Constructores
        cRadioReloj(const cTime& rel = cTime(), const cTime& alar = cTime(),
                    TipoAlarma tipA = Timbre, bool prendA = false, float frec = 100.1,
                    TipoDeBanda tipR = FM, bool prendR = false);
        //Setters y Getters
        void setAlarma(int hh, int mm, int ss);
        void setAlarma(const cTime&);
        void setTipo(TipoAlarma);
        void setPrendido(bool);
        cTime getAlarma();
        TipoAlarma getTipo();
        bool getPrendido();

        //Funciones
        bool verificarAlarma();

};

#endif // CRADIORELOJ_H
