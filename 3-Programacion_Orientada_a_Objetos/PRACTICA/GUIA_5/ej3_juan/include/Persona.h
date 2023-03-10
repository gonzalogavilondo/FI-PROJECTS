#ifndef PERSONA_H
#define PERSONA_H
#include "Fecha.h"
using namespace std;

class Persona
{
    public:
        Persona();
        Persona(string, string, int, int, string, string, string, int, int, int);
        Persona(string, string, int, int, string, string, string, Fecha);
        virtual ~Persona();

        void setNombre(string);
        void setMail(string);
        void setDNI(int);
        void setTelefono(int);
        void setDireccion(string);
        void setProvincia(string);
        void setLocalidad(string);
        void setFechaNac(int, int, int);
        void setFechaNac(Fecha);

        string getNombre();
        string getMail();
        int getDNI();
        int getTelefono();
        string getDireccion();
        string getProvincia();
        string getLocalidad();
        Fecha getFechaNac();

        friend istream& operator >> (istream&, Persona&);
        friend ostream& operator << (ostream&, Persona&);

        void ingresarPersona();
        void mostrarPersona(ostream&);

        virtual void setPersona(istream&) = 0;
        virtual void printPersona(ostream&) = 0;

    protected:
        string nombre;
        string mail;
        unsigned int DNI;
        unsigned telefono;
        string provincia;
        string localidad;
        string direccion;
        Fecha fechaNac;
};

#endif // PERSONA_H
