#ifndef VEHICULO_H
#define VEHICULO_H
#include <string>
#include <iostream>
using namespace std;

class Vehiculo
{
    public:
        //Constructores y Destructores
        Vehiculo();
        Vehiculo(string, string, string, int, float, int);
        virtual ~Vehiculo();

        //Setters y Getters
        void setDueno(string);
        void setMarca(string);
        void setPatente(string);
        void setCantPuertas(int);
        void setKilometraje(float);
        void setCilindrada(int);

        string getDueno();
        string getMarca();
        string getPatente();
        int getCantPuertas();
        float getKilometraje();
        int getCilindrada();

        //Sobrecarga de los operandores de extracción e inserción
        friend istream& operator >> (istream&, Vehiculo&);
        friend ostream& operator << (ostream&, const Vehiculo&);

        //Métodos de "Vehículo"
        virtual void caracteristicas() = 0;
        virtual void printVehiculo(ostream&) const = 0;
        virtual void setVehiculo(istream&) = 0;
    protected:
        string dueno;
        string marca;
        string patente;
        int cantPuertas;
        float kilometraje;
        int cilindrada;
    private:
};

#endif // VEHICULO_H
