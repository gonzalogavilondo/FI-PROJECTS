#ifndef MENU_H
#define MENU_H
#include <vector>
#include <map>
#include <string>
#include <iostream>
#include <fstream>
#include "Banco.h"
#include <conio.h>
#include <stdio.h>

using namespace std;

class Menu
{
    public:
        //Constructores y Destructores
        Menu();
        Menu(string, vector<string>);
        ~Menu();

        //Métodos de la clase Menu
        void imprimirMenu(ostream& co = cout);

//        void ejecutarMenu(void (*[])(ostream&), unsigned, unsigned, ostream& co = cout);
        unsigned ingresarOpcion(unsigned, unsigned);
        void setCartel(string);
        void addOpcionStr(string);

        //Al final paso una instancia objeto para poder usar las funciones miembro.
        template <class T> void ejecutarMenu(void (T::*funciones[])(ostream&), unsigned limInf, unsigned limSup, ostream& co, T obj){
            unsigned op = 0;
            while(op != limSup){
                system("cls || clean");
                imprimirMenu();

                op = ingresarOpcion(limInf, limSup);

                system("cls || clean");

                (obj.*funciones[op - 1])(co);

                cout <<  endl;
                system("pause");

            }
        }

    private:
        bool validarOpcion(unsigned, unsigned, unsigned);

        string cartel;
        map<unsigned, string> opciones;
};

#endif // MENU_H
