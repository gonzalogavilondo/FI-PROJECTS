#ifndef MESAREDONDA_H
#define MESAREDONDA_H

#include "Circulo.h"
#include "Mesa.h"

class MesaRedonda: public Circulo, public Mesa
{
    public:

        ///Constructores
        //MesaRedonda();
        MesaRedonda(float initRadio = 0.5,
                    float initAltura = 1.2, int initCntPatas = 4,
                    int initColor = 1);

        ///Destructor
        ~MesaRedonda();

        ///Getters y Setters
        int GetColor();
        void SetColor(int);

        ///Sobrecargamos el operador de insercion
        friend ostream& operator<< (ostream&, const MesaRedonda&);

        ///Metodos propios de MesaRedonda
        int Color() const;

    protected:
        int color; //1 marron

    private:
};

#endif // MESAREDONDA_H
