#ifndef CLIENTE_H
#define CLIENTE_H
#include <vector>
#include "Fecha.h"
#include "Persona.h"

class Cliente : public Persona
{
    public:
        //Constructores y Destructores
        Cliente();
        Cliente(string, string, int, int, string, string, string,
                int, int, int, int, int, int);
        Cliente(string, string, int, int, string, string, string,
                Fecha, Fecha);
        ~Cliente();

        //Setters y Getters
        void setIdCliente(string);
        void setFechaIng(int, int, int);
        void setFechaIng(Fecha);
        void addCbu(string);

        string getIdCliente();
        Fecha getFechaIng();
        string getCbu(int);
        vector<string> getCbus();
        unsigned getSizeCbus();

        //Métodos para mostrar o ingresar un cliente
        //para el usuario
        void ingresarCliente();
        ostream& mostrarCliente(ostream& co = cout);

        //Métodos virtuales para usar los operadores de
        //inserción y extracción a través de la clase
        //Persona
        virtual void setPersona(istream&);
        virtual void printPersona(ostream&);
    private:
        string idCliente;
        Fecha fechaIng;
        vector<string> cbus;
};

#endif // CLIENTE_H
