#ifndef CRADIO_H_INCLUDED
#define CRADIO_H_INCLUDED

enum TipoDeBanda {AM, FM};
class cRadio
{
    protected:
        float frecuencia;
        TipoDeBanda banda;
        bool prendido;

    public:
        cRadio(float frec = 95.5, TipoDeBanda banda = FM, bool prendido = false);
        //No hay atributos de memoria dinámica; se usó
        //el constructor de copia y el destructor ambos de oficio

        void setPrendido(bool);
        void setBanda(TipoDeBanda);

        bool verificarRadio();
};

#endif // CRADIO_H_INCLUDED
