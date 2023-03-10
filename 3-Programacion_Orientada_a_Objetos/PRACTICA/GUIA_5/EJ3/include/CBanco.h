#ifndef CBANCO_H
#define CBANCO_H

#include <string>
#include <fstream>
#include <stdexcept>
#include "CCuenta.h"
#include "CCliente.h"
#include <vector>

class CBanco
{
    public:
        ///Constructor
        CBanco(string _nombre = "", string _telefono = "", string _direccion = "", double _activoDisponible = 0.0);

        ///Destructor
        virtual ~CBanco();

        ///Setters
        void SetActivoDisponible(double);
        bool SetNombre(string);
        bool SetTelefono(string);
        bool SetDireccion(string);

        ///Getters
        double GetActivoDisponible();
        string GetNombre();
        string GetTelefono();
        string GetDireccion();

        ///Sobrecarga de operadores
        CCuenta* operator[] (size_t i) const; //Devuelve un puntero al objeto que está en la posición i de la matriz cuentas.
        friend ostream& operator<< (ostream&, const CBanco&);

        ///Metodos de la propia clase CBanco
        //Cliente
        int CrearCliente(string, string, string);  //Crea un cliente y devuelve el indice

        //Cuenta
        int CrearCuenta(int _tipoDeCuenta = 0); //Crea la cuenta con el nombre del titular y devuelve el numero de cuenta
        void AnyadirCuenta(CCuenta*); //Añade un puntero a un objeto de la clase CCuenta o de alguna de sus derivadas al final de la matriz cuentas
        void AsignarCuenta(int, int);
        bool EliminarCuenta(int);  //Elimina el objeto que coincida con el número de cuenta pasado como argumento y después elimina el elemento de la
                                      //matriz cuentas.
        int BuscarCuenta(int num = -1, int pos = 0) const; //Devuelve la posición en la matriz cuentas del objeto cuyo
                                                   //titular (nombre total o parcial) o cuenta coincida con el
                                                   //valor pasado como argumento
        size_t LongitudCuenta() const; //Devuelve el número de elementos de la matriz

        bool Ingreso(int, int, double);
        bool Reingreso(int, int, double);
        double ConsultarSaldo(int, int);

        //Banco
        void LevantarClientes(vector<int>);
        void Operaciones(int, int);
        void ActivoDisponible();
        void ActualizarCntClientes();
        double CobrarComisiones(int, int);
        double PagarIntereses(int, int);

        ///Metodos para menu
        static void VisualizarCuentas(CBanco& banco, string tipoCue = "");
        static string TipoCuenta(CCuenta*);
        /***
        En ocasiones se hace necesario disponer de una variable global públicamente accesible que no sea parte de
        un objeto, pero sí de la clase, o bien de un método que no necesite ser invocado para un objeto en particular.
        Esta funcionalidad es proporcionada en C++ por los miembros estáticos (static) de una clase.

        En este caso, "VisualizarCuentas" y  "TipoCuenta" tienen que ser static, ya que este metodo no necesariamente
        va a ser invocado para un objeto en particular, puede ser invocado para CCuentaAhorro o CCuentaCorriente.
        ***/

    protected:

    private:
        string nombre;
        string telefono;
        string direccion;
        vector <CCuenta*> cuentas; //Matriz de objetos
        vector <CCliente> clientes;
        double activoDisponible;
        static int cntClientes;
        static int cntCuentas;
};


#endif // CBANCO_H
