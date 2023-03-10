#ifndef AUTO_H
#define AUTO_H
#include "Vehiculo.h"

class Auto : public Vehiculo
{
    public:
        //Constructores y Destructores
        Auto();
        Auto(string, string, string, int, float, int, bool);
        ~Auto();

        //Getters y Setters
        void setEsDescapotable(bool);
        bool getEsDescapotable();

        //Sobrecarga de los operadores de extracción e inserción
        friend istream& operator >> (istream&, Auto&);
        friend ostream& operator << (ostream&, const Auto&);

        //Métodos de "Auto"
        virtual void caracteristicas();
        void subir();
        void bajar();
        virtual void printVehiculo(ostream&) const;
        virtual void setVehiculo(istream&);
    protected:
        bool esDescapotable;
    private:
};

#endif // AUTO_H
