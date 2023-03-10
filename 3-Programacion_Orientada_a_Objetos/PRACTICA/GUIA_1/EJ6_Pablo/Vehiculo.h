#ifndef VEHICULO_H
#define VEHICULO_H

class Vehiculo
{
    public:
        static float valor_patente;

        Vehiculo(const char* , int , int, float);
        virtual ~Vehiculo();

        const char* Getmarca() { return m_marca; }
        void Setmarca(const char* val) { m_marca = val; }
        int Getpuertas() { return m_puertas; }
        void Setpuertas(int val) { m_puertas = val; }
        int Getkilometraje() { return m_kilometraje; }
        void Setkilometraje(int val) { m_kilometraje = val; }
        float Getcilindrada() { return m_cilindrada; }
        void Setcilindrada(float val) { m_cilindrada = val; }

        //void encender();
        //void apagar();
        void acelerar();
        void frenar();

    protected:

    private:
        const char* m_marca;
        int m_puertas;
        int m_kilometraje;
        float m_cilindrada;
};
#endif // VEHICULO_H
