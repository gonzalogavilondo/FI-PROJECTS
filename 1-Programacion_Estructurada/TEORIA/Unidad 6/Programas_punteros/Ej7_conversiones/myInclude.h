#ifndef MYINCLUDE_H_INCLUDED
#define MYINCLUDE_H_INCLUDED

#include <stdio.h>
#include <stdlib.h>

char *itoa(int val, char *str, int b);             // para evitar los warnings, son
char *ltoa(long val, char *str, int b);            // funciones que se mantienes por
char *gcvt (double val, int prec, char *str);      // compatibilidad con anteriores
char *ecvt(double val, int prec, int *dec, int *sgn);
char *fcvt(double val, int prec, int *dec, int *sgn);


void enteros(void);
void flotantes(void);

#endif // MYINCLUDE_H_INCLUDED
