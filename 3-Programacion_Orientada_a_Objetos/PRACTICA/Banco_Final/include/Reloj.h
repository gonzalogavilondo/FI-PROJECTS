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

        ///Constructores
        Reloj();
        Reloj(int _hour, int _min, int _sec);

        ///Destructor
        ~Reloj();

        ///Getters y Setters
        int getHour();
        bool setHour(int);
        int getMin();
        bool setMin(int);
        int getSec();
        bool setSec(int);

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
