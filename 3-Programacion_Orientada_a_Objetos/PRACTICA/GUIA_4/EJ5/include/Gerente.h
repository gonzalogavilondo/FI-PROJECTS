#ifndef GERENTE_H
#define GERENTE_H

#include "Permanente.h"

class Gerente : public Permanente
{
    public:
        ///Constructor
        Gerente();

        ///Destructor
        ~Gerente();

        ///Getters y setters
        float GetValorHora();
        void SetValorHora(float);
        float GetSueldo();
        void SetSueldo(float);

        ///Funciones
        float CalcularSueldo();

    protected:

    private:
        float valorHora;
        float sueldo;
};

#endif // GERENTE_H
