#ifndef MYINCLUDE_H_INCLUDED
#define MYINCLUDE_H_INCLUDED

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct
{
    int day;
    int month;
    int year;
}stDate;

typedef struct
{
   char Nombre[20];
   int iDato;
   float fDato;
   stDate stFecha;
}stFile;

void graba(char *);
void printRecord(stFile);
void backup(char *);

#endif // MYINCLUDE_H_INCLUDED
