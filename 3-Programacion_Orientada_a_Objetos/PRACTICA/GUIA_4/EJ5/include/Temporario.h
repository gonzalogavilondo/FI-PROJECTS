#ifndef TEMPORARIO_H
#define TEMPORARIO_H
#include "Empleado.h"

class Temporario : public Empleado
{
    public:
        ///Constructor
        Temporario();
        Temporario(Empleado&);

        ///Destructor
        ~Temporario();

        ///Getters y setters
        float GetValorHora();
        void SetValorHora(float);
        int GetCntHoras();
        void SetCntHoras(int);

        ///Funciones
        float CalcularSueldo();

    protected:
        float valorHora;
        int cntHoras;

    private:
};

#endif // TEMPORARIO_H
