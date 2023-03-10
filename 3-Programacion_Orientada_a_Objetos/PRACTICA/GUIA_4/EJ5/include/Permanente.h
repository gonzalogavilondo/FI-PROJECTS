#ifndef PERMANENTE_H
#define PERMANENTE_H
#include "Empleado.h"

class Permanente : public Empleado
{
    public:
        ///Constructor
        Permanente();
        Permanente(Empleado&);

        ///Destructor
        ~Permanente();

        ///Getters y setters
        float GetValorHora();
        void SetValorHora(float);
        int GetCntHoras();
        void SetCntHoras(int);
        float GetAntiguedad();
        void SetAntiguedad(float);

        ///Funciones
        float CalcularSueldo();

    protected:
        float valorHora;
        int cntHoras;
        float antiguedad;

    private:
};

#endif // PERMANENTE_H
