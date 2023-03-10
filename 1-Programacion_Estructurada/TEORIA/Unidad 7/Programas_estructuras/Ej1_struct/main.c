#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#include "prototipos.h"

/***  struct estructura { ... };        // se debe utilizar la palabra clave struct

      typedef struct { ... } mySt;      // mySt es un nuevo tipo de dato (declaro toda la esturctura)

      typedef struct estructura newSt;  // newSt es otro tipo nuevo de dato (utilizo una declaracion anterior)

***/

int main()
{
    struct estructura st1;     // forma larga de declarar un nuevo dato de tipo estructura
    mySt st2,                  // otra forma escribiendo menos de declarar un nuevo dato
         st3 = {3, 33.33, "prueba 3 correcta"};  // inicializa al declarar
    newSt st4;                 // tipo de dato definido en el *.h

    /**** inicializa datos de estructura st1 ****/
    st1.iNumero = 1;
    st1.fNumero = 11.11;
//    st1.cCar = "prueba 1 correcta";            // no se puede asignar un string directamente
    strcpy(st1.cCar,"prueba 1 correcta");

    /**** se pueden igualar estructuras del mismo tipo ****/
    st2 = st3;              // ver las posiciones de memoria
    st4 = st1;              // se copian todos los campos de st1 en st4

    /**** no se puede igualar tipos distintos, mySt != struct estructura  ****/
//    st2=st1;         // hay que copiar campo por campo
    st2.iNumero = st1.iNumero;
    st2.fNumero = st1.fNumero;
    strcpy(st2.cCar, st1.cCar);

   /**** modifica los datos de estructura st2 ****/
    printf("Ingrese un numero entero: ");
    scanf("%d", &st2.iNumero);
    printf("Ingrese un numero flotante: ");
    scanf("%f", &st2.fNumero);
    printf("Ingrese un mensaje: ");
    fflush(stdin);           // para eliminar el \n del scanf anterior
    scanf("%[^\n]", st2.cCar);

    /**** impresión de los campos de cada estructura ****/
    printf("\n\nEntero = %d, flotante = %f, string = %s\n", st1.iNumero, st1.fNumero, st1.cCar);
    printf("Entero = %d, flotante = %f, string = %s\n", st2.iNumero, st2.fNumero, st2.cCar);
    printf("Entero = %d, flotante = %f, string = %s\n", st3.iNumero, st3.fNumero, st3.cCar);
    printf("Entero = %d, flotante = %f, string = %s\n", st4.iNumero, st4.fNumero, st4.cCar);

    return 0;
}
