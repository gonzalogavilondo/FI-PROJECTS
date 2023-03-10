#ifndef PERSONA_H
#define PERSONA_H
#include "Fecha.h"
#include <iostream>

using namespace std;

class Persona
{
    public:

        ///Constructor
        Persona(string _name = "Pedro", string _lastName = "Picapiedras", unsigned _document = 12345678, Fecha _birthDate = Fecha());

        ///Destructor
        virtual ~Persona();

        ///Getters y Setters
        string getName();
        void setName(string val);
        string getLastName();
        void setLastName(string val);
        unsigned getDocument();
        void setDocument(unsigned val);
        Fecha getBirthDate();
        void setBirthDate(Fecha val);

        ///Sobrecarga de operadores
        friend ostream& operator<< (ostream&, Persona&);
        friend istream& operator>> (istream&, Persona&);

    protected:
        string name;
        string lastName;
        unsigned document;
        Fecha birthDate;

    private:
};

#endif // PERSONA_H
