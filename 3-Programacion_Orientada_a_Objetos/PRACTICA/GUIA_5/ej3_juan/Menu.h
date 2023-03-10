#ifndef MENU_H_INCLUDED
#define MENU_H_INCLUDED
#include <iostream>
#include <fstream>
#include "Banco.h"
using namespace std;

void _completarOpcion(char **str);
int validarOpcion(int, int);

void buscarYMostrarCliente(Banco&);
void buscarYMostrarCuenta(Banco&);
void operacionesConCuenta(Banco&);

void guardar(Banco&);

void imprimirMenu(Banco&);
void ejecutarMenu(Banco&);

#endif // MENU_H_INCLUDED
