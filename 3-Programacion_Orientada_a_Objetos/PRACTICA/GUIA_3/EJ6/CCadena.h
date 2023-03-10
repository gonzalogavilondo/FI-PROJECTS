#ifndef CCADENA_H_INCLUDED
#define CCADENA_H_INCLUDED

#include <iostream>
#include <string.h>
using namespace std;

///Clase para operar con cadenas de caracteres
class CCadena
{
    private:
        char *pmCad; //Puntero a la cadena de caracteres
        size_t nLong; //Longitud de la cadena

    public:
        ///Constructores
        CCadena(const char * = "");     //Constructor por default
        CCadena(const CCadena&);        //Constructor copia
        CCadena(char*, int);            //Constructor sobrecargado

        ///Destructor
        ~CCadena();

        ///Getters y Setters
        char GetPmCad();
        void SetPmCad(char*);
        size_t GetN_long();
        void SetN_long(size_t);

        ///Operaciones de entrada/salida
        friend istream& operator>> (istream&, CCadena&);
        friend ostream& operator<< (ostream&, const CCadena&);

        ///Concatenar cadenas de caracteres
        friend CCadena operator+ (const CCadena&, const CCadena&);

        ///Comparacion de cadenas
        friend bool operator== (const CCadena&, const CCadena&);
        friend bool operator!= (const CCadena&, const CCadena&);
        friend bool operator< (const CCadena&, const CCadena&);
        friend bool operator> (const CCadena&, const CCadena&);

        ///Asignacion, concatenacion e indexación
        CCadena& operator= (const CCadena&);       //Asignacion objeto
        CCadena& operator= (const char *);         // Asignacion cadena
        CCadena& operator+= (const CCadena&);      // Suma mas asignacion
        char& operator[] (unsigned int);           // Indexacion


};

#endif // CCADENA_H_INCLUDED
