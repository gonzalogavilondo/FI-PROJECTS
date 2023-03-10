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

        //M�todos para mostrar o ingresar un cliente
        //para el usuario
        void ingresarCliente();
        ostream& mostrarCliente(ostream& co = cout);

        //M�todos virtuales para usar los operadores de
        //inserci�n y extracci�n a trav�s de la clase
        //Persona
        virtual void setPersona(istream&);
        virtual void printPersona(ostream&);
    private:
        string idCliente;
        Fecha fechaIng;
        vector<string> cbus;
};

#endif // CLIENTE_H
