#ifndef BANCO_H
#define BANCO_H
#include <fstream>
#include <stdexcept>
#include <vector>
#include "CuentaBancaria.h"
#include "CajaDeAhorro.h"
#include "CuentaCorriente.h"
#include "CuentaUniversitaria.h"
#include "Cliente.h"
#include "bLinkCliente.h"
#include "bLinkCuenta.h"

class Banco
{
    public:
        Banco();
        Banco(string, int, string);
        ~Banco();

        void setNombre(string);
        void setTelefono(unsigned int);
        void setDireccion(string);
        string getNombre();
        unsigned int getTelefono();
        string getDireccion();
        Cliente& getCliente(int);
        CuentaBancaria* getCuentaBancaria(int);

        vector <CuentaBancaria*> getCuentasCliente(int);
        vector <Cliente*> getClientesCuenta(string);
        int getSizeCuentasCliente(int) const;
        int getSizeClientesCuenta(int) const;



        void levantarClientes(vector <int>);
        int crearCliente(string, string, int, int, string,
                             string, string, Fecha, Fecha);
        int crearCliente(Cliente&);
        string asignarCuenta(int, tipoDeCuenta);
        int buscarCuenta(string);
        CuentaBancaria *buscarCuenta(string, int);
        int buscarCliente(int);
        Cliente *buscarCliente(int, int);

        int buscarClienteDNI(int);

        bool depositar(string);
        bool depositar(string, float);
        bool extraer(string);
        bool extraer(string, float);
        float consultarSaldo(string);


        float activoDisponible();
        void printClientes(ostream&);
        void printCuentas(ostream&);
        void cargarCliente();
        void mostrarClienteYCuentas(int);
        void mostrarCuentaYTitulares(string);

        int getSizeClientes() const;
        int getSizeCuentas() const;

    private:
        string nombre;
        unsigned int telefono;
        string direccion;
        vector <bLinkCliente> clientes;
        vector <bLinkCuenta> cuentasBancarias;
};

#endif // BANCO_H
