#ifndef MENU_H_INCLUDED
#define MENU_H_INCLUDED
#include "CBanco.h"
#include <limits>
#include <iomanip>

void Menu(CBanco*);
int CrearMenu(const char* opMenu[], int num_opciones);

#endif // MENU_H_INCLUDED
