#ifndef RELOJ_H
#define RELOJ_H

#include <iostream>
#include <windows.h> // Para la funcion sleep
#include <ctime>
#include <sstream>
#include <string>

using namespace std;
class Reloj
{
    public:

        ///Constructor
        Reloj();

        ///Destructor
        ~Reloj();

        ///Getters y Setters
        int getHour();
        void setHour(int);
        int getMin();
        void setMin(int);
        int getSec();
        void setSec(int);

        ///Sobrecargamos los operadores de insercion
        friend istream& operator >> (istream&, Reloj&);
        friend ostream& operator << (ostream&, Reloj&);

        ///Metodos propios de la clase reloj
        void printReloj(ostream& co = cout);
        void printRelojActualizandose(ostream& co = cout);


    protected:

    private:
        int hour;
        int min;
        int sec;
};

#endif // RELOJ_H
