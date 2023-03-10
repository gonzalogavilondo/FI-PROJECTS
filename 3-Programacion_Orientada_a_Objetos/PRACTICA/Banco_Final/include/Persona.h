#ifndef PERSONA_H
#define PERSONA_H
#include "Fecha.h"
using namespace std;

class Persona
{
    public:
        //Constructores y Destructores
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
        unsigned getDNI();
        int getTelefono();
        string getDireccion();
        string getProvincia();
        string getLocalidad();
        Fecha getFechaNac();

        //Sobrecarga de los operadores de extracción e inserción
        friend istream& operator >> (istream&, Persona&);
        friend ostream& operator << (ostream&, Persona&);

        //Métodos para mostrar o ingresar una persona
        //para el usuario
        void ingresarPersona();
        ostream& mostrarPersona(ostream& co = cout);

        //Métodos virtuales llamados en la sobrecarga de los
        //operadores de extracción e inserción
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
