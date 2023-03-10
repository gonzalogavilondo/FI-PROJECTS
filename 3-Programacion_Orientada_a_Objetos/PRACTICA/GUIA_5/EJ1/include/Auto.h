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

        //Sobrecarga de los operadores de extracci�n e inserci�n
        friend istream& operator >> (istream&, Auto&);
        friend ostream& operator << (ostream&, const Auto&);

        //M�todos de "Auto"
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
