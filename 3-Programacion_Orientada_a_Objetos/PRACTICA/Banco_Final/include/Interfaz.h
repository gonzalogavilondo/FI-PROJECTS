#ifndef INTERFAZ_H
#define INTERFAZ_H
#include <iostream>
#include <sstream>
#include <string>
#include <conio.h>
#include "Banco.h"
#include "Backup.h"
#include "Menu.h"
#include "Fecha.h"
#include "Reloj.h"
enum backup_ID{
    BANCO, CUENTAS, CLIENTES, LOGS
};

/**
 *  Clase que se encarga de unir todas las clases que conformar
 *  un sistema bancario.
 */
class Interfaz
{
    public:
        //Constructores y Destructores
        Interfaz();
        ~Interfaz();

        void inicializarSistema();

    private:
        //Métodos de la clase
        void mostrarActivos(ostream& co = cout);
        void mostrarClientes(ostream& co = cout);
        void mostrarCuentas(ostream& co = cout);
        void cargarNuevoCliente(ostream& co = cout);

        void buscarYMostrarCliente(ostream& co = cout);
        void buscarYMostrarCuenta(ostream& co = cout);
        void operacionesConCuenta(ostream& co = cout);
        void guardarSistema(ostream& co = cout);

        void levantarBanco();
        void levantarClientes();
        void levantarCuentas();
        void levantarDatos();

        void guardarBanco();
        void guardarClientes();
        void guardarCuentas();

        ///AGREGAR INSTANCIA DE OBJETO
        //Función que guarda la impresión de un objeto en un string
        template <class T> string bufferToStr(T objeto, bool modo = false, ostream& (*print)(ostream& co) = NULL){
            stringstream buffer;
            if (!modo){ //Se usa el operador <<
                buffer << objeto << endl;
            } else {    //Se usa una función de impresión
                print(buffer);
                buffer << endl;
            }

            return buffer.str();
        }

        Banco banco;
        vector<Backup> backups;
        Menu menu;
        Fecha fecha;
        Reloj hora;
};

#endif // INTERFAZ_H
