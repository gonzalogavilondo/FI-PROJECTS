#ifndef CLIENTE_H
#define CLIENTE_H
#include <vector>
#include "Fecha.h"
#include "Persona.h"

class Cliente : public Persona
{
    public:
        Cliente();
        Cliente(string, string, int, int, string, string, string,
                int, int, int, int, int, int);
        Cliente(string, string, int, int, string, string, string,
                Fecha, Fecha);
        virtual ~Cliente();

        void setIdCliente(int);
        void setFechaIng(int, int, int);
        void setFechaIng(Fecha);

        int getIdCliente();
        Fecha getFechaIng();

        void ingresarCliente();
        void mostrarCliente(ostream&);

        virtual void setPersona(istream&);
        virtual void printPersona(ostream&);

        void generadorID();

    private:
        int idCliente;
        Fecha fechaIng;
};

#endif // CLIENTE_H
