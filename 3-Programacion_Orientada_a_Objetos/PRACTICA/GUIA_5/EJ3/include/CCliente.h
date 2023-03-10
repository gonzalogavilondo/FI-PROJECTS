#ifndef CCLIENTE_H
#define CCLIENTE_H

#include <vector>
#include "CCuenta.h"

class CCuenta;
class CCliente
{
    public:
        ///Constructor
        CCliente(string _nombre = "", string _dni = "", string _telefono = "");

        ///Destructor
        virtual ~CCliente();

        ///Setters
        bool SetNombre(string); //Almacena el nombre del propietario de la cuenta. Retorna false si la cuenta es una cadena vacía, y true en otro caso.
        bool SetDni(string); //Almacena el dni del propietario de la cuenta. Retorna false si la cuenta es una cadena vacía, y true en otro caso.
        bool SetTelefono(string); //Almacena el telefono del propietario de la cuenta. Retorna false si la cuenta es una cadena vacía, y true en otro caso.
        void SetCuentas(vector <CCuenta*>);

        ///Getters
        string GetNombre();
        string GetDni();
        string GetTelefono();
        vector <CCuenta*> GetCuentas();

        ///Sobrecarga del operador de insercion
        friend ostream& operator<< (ostream&, const CCliente&);
        friend istream& operator>> (istream&, CCliente&);

        ///Metodos propios de la clase CCliente para manejar cuentas
        void AnyadirCuenta(CCuenta*); //Añade un puntero a un objeto de la clase CCuenta o de alguna de sus derivadas al final de la matriz cuentas
        bool EliminarCuenta(int);  //Elimina el objeto que coincida con el número de cuenta pasado como argumento y después elimina el elemento de la
                                      //matriz cuentas.

        int BuscarCuenta(int num = -1, int pos = 0) const; //Devuelve la posición en la matriz cuentas del objeto cuyo
                                                   //titular (nombre total o parcial) o cuenta coincida con el
                                                   //valor pasado como argumento
        size_t LongitudCuenta() const; //Devuelve el número de elementos de la matriz

    protected:

    private:
        string nombre;
        string dni;
        string telefono;
        vector <CCuenta*> cuentas; //Matriz de objetos
};

#endif // CCLIENTE_H
