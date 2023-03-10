#ifndef MESA_H
#define MESA_H
#include <iostream>
using namespace std;

class Mesa
{
    public:

        ///Constructor
        Mesa(float initAltura = 0.8, int initCntPatas = 4); //Constructor por default

        ///Getters y Setters
        float GetAltura();
        void SetAltura(float);
        int GetCntPatas();
        void SetCntPatas(int);

        ///Sobrecargamos el operador de insercion
        friend ostream& operator<< (ostream&, const Mesa&);

        ///Funciones de mesa
        float alto() const;

    protected:
        int cntPatas;
        float altura;

    private:
};

#endif // MESA_H
