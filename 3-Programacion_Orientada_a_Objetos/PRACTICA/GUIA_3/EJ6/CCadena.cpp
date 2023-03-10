#include "CCadena.h"

/**
    Constructores
**/
CCadena::CCadena(const char *cadena)      //Constructor
{
    pmCad = new char[strlen(cadena) + 1];
    strcpy(pmCad, cadena);
    nLong = strlen(cadena);

}

CCadena::CCadena(const CCadena& cadena)        //Constructor copia
{
    pmCad = new char[strlen(cadena.pmCad) + 1];

    strcpy(pmCad, cadena.pmCad);
    nLong = cadena.nLong;
}

CCadena::CCadena(char *cadena, int longitud)            //Constructor
{
    pmCad = new char[longitud + 1];

    strcpy(pmCad, cadena);
    nLong = longitud;
}

/**
    Destructor
**/
CCadena::~CCadena()
{
    delete [] pmCad;
}

/**
    Getters y Setters
**/
char CCadena::GetPmCad()
{
     return *pmCad;
}

void CCadena::SetPmCad(char *val)
{
     *pmCad = *val;
}

size_t CCadena::GetN_long()
{
     return nLong;
}

void CCadena::SetN_long(size_t val)
{
     nLong = val;
}

/**
    Operaciones de entrada/salida
**/
istream& operator>> (istream& ci , CCadena& cad)
{
    gets(cad.pmCad);
    cad.nLong = strlen(cad.pmCad);
    return ci;
}

ostream& operator<< (ostream& co, const CCadena& cad)
{
    co << cad.pmCad;
    //co << cad.pmCad << " Con: " << cad.nLong << " de longitud";

    return co;
}

/**
    Concatenar cadenas de caracteres
**/

CCadena operator+ (const CCadena& cad1, const CCadena& cad2)
{
    CCadena aux;

    aux.nLong = (cad1.nLong + cad2.nLong);
    strcat(aux.pmCad, cad1.pmCad);
    strcat(aux.pmCad, cad2.pmCad);

    return (aux);
}

/**
    Comparacion de cadenas
**/
bool operator== (const CCadena& cad1, const CCadena& cad2)
{
    if(strcmp(cad1.pmCad, cad2.pmCad) == 0) //Devuelve 0 si son iguales
    {
        return true;
    }
    else
    {
        return false;
    }
}

bool operator!= (const CCadena& cad1, const CCadena& cad2)
{
    if(strcmp(cad1.pmCad, cad2.pmCad) != 0) //Devuelve 0 si son iguales, distinto de 0 si no son iguales
    {
        return true;
    }
    else
    {
        return false;
    }
}

bool operator< (const CCadena& cad1, const CCadena& cad2)
{
    if(strcmp(cad1.pmCad, cad2.pmCad) == -1) //Devuelve -1 si cad1 < cad2
    {
        return true;
    }
    else
    {
        return false;
    }
}

bool operator> (const CCadena& cad1, const CCadena& cad2)
{
    if(strcmp(cad1.pmCad, cad2.pmCad) == 1) //Devuelve 1 si cad1 > cad2
    {
        return true;
    }
    else
    {
        return false;
    }
}

/**
    Asignacion, concatenacion e indexación
**/
CCadena& CCadena::operator= (const CCadena& cad)       //Asignacion objeto
{
    strcpy(pmCad, cad.pmCad);
    nLong = cad.nLong;

    return (*this);
}

CCadena& CCadena::operator= (const char *cad)        // Asignacion cadena
{
    strcpy(pmCad, cad);
    nLong = strlen(cad);

    return (*this);
}

CCadena& CCadena::operator+= (const CCadena& cad)
{
    strcat(pmCad, cad.pmCad);
    nLong += cad.nLong;

    return (*this);
}

char& CCadena::operator[] (unsigned int i)          // Indexacion
{
    if(i < nLong)
    {
        return pmCad[i];
    }
    else
    {
        return pmCad[nLong];
    }
}
