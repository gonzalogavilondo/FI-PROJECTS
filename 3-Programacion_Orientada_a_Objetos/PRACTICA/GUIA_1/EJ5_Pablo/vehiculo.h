#ifndef VEHICULO_H_INCLUDED
#define VEHICULO_H_INCLUDED

typedef struct Vehiculo* Vehiculo;

struct Vehiculo
{
    /* Atributos (todos publicos, no hay encapsulación!!)
       Un TDA debe ocultar TODA su implementación.
    */
    char* m_marca;
    int m_puertas;
    int m_kilometraje;
    float m_cilindrada;

    char* (*get_marca)(Vehiculo this);
    int (*get_puertas)(Vehiculo this);
    int (*get_kilometraje)(Vehiculo this);
    float (*get_cilindrada)(Vehiculo this);

    void (*set_marca)(Vehiculo, const char*);
    void (*set_puertas)(Vehiculo, int);
    void (*set_kilometraje)(Vehiculo, int);
    void (*set_cilindrada)(Vehiculo, float);

    void (*encender)(Vehiculo this);
    void (*apagar)(Vehiculo this);
    void (*acelerar)(Vehiculo this);
    void (*frenar)(Vehiculo this);
};

/* Definición de métodos */
char* getMarca(Vehiculo this);
int getPuertas(Vehiculo this);
int getKilometraje(Vehiculo this);
float getCilindrada(Vehiculo this);

void setMarca(Vehiculo, const char*);
void setPuertas(Vehiculo, int);
void setKilometraje(Vehiculo, int);
void setCilindrada(Vehiculo, float);

void encenderVehiculo(Vehiculo this);
void apagarVehiculo(Vehiculo this);
void acelerarVehiculo(Vehiculo this);
void frenarVehiculo(Vehiculo this);

/* Constructor & Destructor*/
Vehiculo crearVehiculo(const char*, int, int, float);
void destruirVehiculo(Vehiculo this);
#endif // VEHICULO_H_INCLUDED
