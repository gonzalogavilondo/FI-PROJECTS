#ifndef CAMIONETA_H
#define CAMIONETA_H
#include "Vehiculo.h"

class Camioneta : public Vehiculo
{
    public:
        //Constructores y Destructores
        Camioneta();
        Camioneta(string, string, string, int, float, int, float, float);
        ~Camioneta();

        //Setters y Getters
        void setTara(float);
        void setCarga(float);
        float getTara();
        float getCarga();

        //Sobrecarga de los operadores de extracción e inserción
        friend istream& operator >> (istream&, Camioneta&);
        friend ostream& operator << (ostream&, const Camioneta&);

        //Métodos de la clase "Camioneta"
        virtual void caracteristicas();
        void cargar(float);
        virtual void printVehiculo(ostream&) const;
        virtual void setVehiculo(istream&);
    protected:
        float tara;
        float carga;
    private:
};

#endif // CAMIONETA_H
