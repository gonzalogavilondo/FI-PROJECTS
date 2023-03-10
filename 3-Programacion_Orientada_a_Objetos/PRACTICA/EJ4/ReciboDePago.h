//
// Created by Gonza on 22/11/2021.
//

#ifndef EJ4_IML_RECIBODEPAGO_H
#define EJ4_IML_RECIBODEPAGO_H

#include "Limitado.h"
#include "Extendido.h"
#include "Completo.h"
#include <map>
#include <fstream>
#include <utility>

class ReciboDePago {

private:
    ///Atributos
    map <string, Contribuyente*> recibo; // <ID, CONTRIBUYENTE>

    ///Metodos privados
    string gen_random(int);
    string generadorID();

public:
    ///Constructor
    ReciboDePago();

    ///Setters
    void setRecibo(map<string, Contribuyente*>);

    ///Getters
    map<string, Contribuyente*> getRecibo();
    vector <string> getIds();
    Contribuyente* getContribuyente(string);

    ///Gestor de los metodos de ReciboDePago (ESTO VA EN LA INTERFAZ)
    //void operacionesRecibo(ReciboDePago&, ostream& co);

    ///Gestion de archivos
    void levantarContribuyentes(const char*);
    void levantarDatos();
    void guardarContribuyentes(const char*);
    void guardarDatos();

    ///Metodos propios de la clase ReciboDePago
    string nombreDelContribuyente();
    float montoTotal(); //Suma de Calculador + MontoFijo
    float montoFijo();
    float montoVariable();
    Factura primeraFacturaConsiderada();
    Factura ultimaFacturaConsiderada();

};


#endif //EJ4_IML_RECIBODEPAGO_H
