#ifndef BANCO_H
#define BANCO_H
#include <vector>
#include <map>
#include <algorithm>
#include <numeric>
#include <time.h>
#include <fstream>
#include "Cliente.h"
#include "CuentaBancaria.h"
#include "CuentaCorriente.h"
#include "CajaDeAhorro.h"
#include "CuentaUniversitaria.h"

#define SEARCH_ERROR 100
#define LONG_ID 10
#define LONG_CBU 21

class Banco
{
    public:
        //Constructores y Destructores
        Banco();
        Banco(string, unsigned, string);
        ~Banco();

        //Setters y Getters de atributos
        void setNombre(string);
        void setTelefono(unsigned int);
        void setDireccion(string);

        string getNombre();
        unsigned int getTelefono();
        string getDireccion();

        vector<string> getIds();
        vector<string> getCbus();

        //Métodos para acceder a los mapas
        Cliente* getCliente(string);
        CuentaBancaria* getCuenta(string);

        map<string, Cliente*> getMapaClientes();
        map<string, CuentaBancaria*> getMapaCuentas();

        void addCliente(Cliente*);
        void addCuenta(CuentaBancaria*);

        unsigned getSizeClientes();
        unsigned getSizeCuentas();

        float getActivoDisponibleTotal();
        vector<float> getActivoDisponiblePorCuenta();

        //Metodos propios de la clase banco visibles para el usuario
        string crearCliente(string, string, unsigned, unsigned, string,
                                        string, string, Fecha, Fecha);
        string agregarCliente(Cliente*);
        string crearCuenta(string, tipoDeCuenta);
        string crearYAsignarCuenta(string, tipoDeCuenta);
        bool asignarCuenta(string, string); //Le asigna una cuenta a un cliente que ya es socio del banco

        bool depositar(string);
        bool depositar(string, float);
        bool extraer(string);
        bool extraer(string, float);
        float consultarSaldo(string);

        string buscarClienteDNI(unsigned);

        //Sobrecarga de los operadores de inserción y extracción
        friend istream& operator >> (istream&, Banco&);
        friend ostream& operator << (ostream&, Banco&);

        //Muestra de datos por algun flujo de salida
        string cargarCliente();
        void printClientes(ostream& co = cout);
        void printCuentas(ostream& co = cout);
        bool mostrarClienteYCuentas(string, ostream& co = cout);
        bool mostrarCuentaYTitulares(string, ostream& co = cout);

    private:
        //Metodos
        string gen_random(const int);
        string generadorID();
        string generadorCBU();

        //Atributos
        string nombre;
        unsigned int telefono;
        string direccion;
        map<string, Cliente*> clientes;         //IdCliente, Cliente
        map<string, CuentaBancaria*> cuentas;   //CBU, Cuenta
};

#endif // BANCO_H
