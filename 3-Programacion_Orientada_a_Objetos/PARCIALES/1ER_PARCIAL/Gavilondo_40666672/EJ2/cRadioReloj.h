#ifndef CRADIORELOJ_H_INCLUDED
#define CRADIORELOJ_H_INCLUDED

#include <iostream>
#include <string.h>
using namespace std;

class cTime
{
    public:
        ///Constructor
        cTime(unsigned int hora = 0, unsigned int minuto = 0, unsigned int segundo = 0);

        ///Getters
        int getHora();
        int getMinuto();
        int getSegundo();

        ///Setters
        void setHora(int);
        void setMinuto(int);
        void setSegundo(int);

        ///Sobrecargamos el operador de insercion
        friend ostream& operator<< (ostream&, const cTime&);


    private:
        unsigned int hora;
        unsigned int minuto;
        unsigned int segundo;
};

class cReloj
{
    public:
        ///Constructor
        cReloj(unsigned int hora = 0, unsigned int minutos = 0, unsigned int segundos = 0); // Constructor con valores por default
        cReloj(cTime, const char*);
        cReloj(const cReloj&); //Constructor de copia

        ///Destructor
        ~cReloj();

        ///Getters
        cTime getTiempo();
        char getMarca();

        ///Setters
        void setTiempo(cTime); //Si se quiere ingresar con un cTime directamente
        void setTiempo(int, int, int); //Si se quiere ingresar de la manera SetTime(hora, minuto, segundo)
        void setMarca(const char *);

        ///Funcion propia de CReloj
        void incrementarTiempo();

    private:
        cTime time;
        char *marca;
};

enum TipoDeBanda {AM, FM};
class cRadio
{
    public:

        ///Constructor
        cRadio(float f = 95.5, TipoDeBanda b = FM, bool p = false);//Constructor por default

        ///Constructor de copia
        cRadio(const cRadio&);

        ///Getters
        float getFrecuencia();
        TipoDeBanda getBanda();
        bool getPrendido();

        ///Setters
        void setFrecuencia(float);
        void setBanda(TipoDeBanda);
        void setPrendido(bool);



    private:
        float frecuencia;
        TipoDeBanda banda;
        bool prendido;
};

enum TipoAlarma {Musica, Timbre};
class cRadioReloj: public cRadio, public cReloj
{
    public:
        ///Constructor
        cRadioReloj(cTime tiempoCRel = cTime(), cTime tiempoAlar = cTime(),
                    float frec = 95.5, TipoDeBanda band = FM, bool prenCRadio = false,
                    const char* marc = "",
                    TipoAlarma tip = Timbre, bool prenCRadioRel = false);

        ///Getters
        cTime getAlarma();
        TipoAlarma getTipo();
        bool getPrendido();

        ///Setters
        void setAlarma(unsigned int, unsigned int, unsigned int);
        void setTipo(TipoAlarma val);
        void setPrendido(bool);

        ///Funcion propia de cRadioReloj
        bool verificarAlarma();


    private:
        cTime alarma;
        TipoAlarma tipo;
        bool prendido;
};



#endif // CRADIORELOJ_H_INCLUDED
