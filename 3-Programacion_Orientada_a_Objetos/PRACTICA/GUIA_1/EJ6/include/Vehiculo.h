#ifndef VEHICULO_H
#define VEHICULO_H
#include <string>

class Vehiculo
{
    public:
        Vehiculo();

        std::string GetMarca();
        void SetMarca(std::string);
        float GetKilometraje();
        void SetKilometraje(float);
        int GetPuertas();
        void SetPuertas(int);
        int GetCilindrada();
        void SetCilindrada(int);

    protected:

    private:
        //Atributos de la clase
        std::string Marca;
        float Kilometraje;
        int Puertas;
        int Cilindrada;
};

#endif // VEHICULO_H
