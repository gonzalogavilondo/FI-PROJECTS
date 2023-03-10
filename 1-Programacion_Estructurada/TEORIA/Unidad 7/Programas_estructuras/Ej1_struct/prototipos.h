#ifndef PROTOTIPOS_H_INCLUDED
#define PROTOTIPOS_H_INCLUDED

// Una forma de definir una estructura
struct estructura
{
   int iNumero;
   float fNumero;
   char cCar[20];
};

// Otra forma es usar tydef para no escribir tanto
typedef struct
{
   int iNumero;
   float fNumero;
   char cCar[20];
} mySt;                                   // mySt es un nuevo tipo de dato

// Otra forma de utilizar el typedef en función de una estructura conocida
typedef struct estructura newSt;       // newSt es otro tipo nuevo de dato

#endif // PROTOTIPOS_H_INCLUDED
