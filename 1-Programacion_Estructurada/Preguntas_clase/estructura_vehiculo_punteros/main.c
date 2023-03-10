#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include "declaraciones_funciones.h"

int main()
{
    //Declaracion del puntero a estructura
    datos_vehiculo *vehiculos;

    printf("El tamaño de la estructura es: %d\n", sizeof(*vehiculos));
    //Reservo memoria para el nuevo tipo de dato (4 bytes ya que es un puntero a estructura)
    vehiculos = (datos_vehiculo*)malloc(sizeof(datos_vehiculo));
    printf("El tamaño de lo que hay dentro de la estructura es: %d\n", sizeof(vehiculos));

    //Llamada a las funciones requeridas
    ingreso_datos(vehiculos);
    impresion_datos(vehiculos);

    //Libero memoria
    free(vehiculos->nombre);
    free(vehiculos->m_vehiculo.color);
    free(vehiculos);
}

    /***********
    Verifico lo que reserve en memoria asi:

    printf("\nEl tamaño de la estructura es: %d\n", sizeof(vehiculos));

    Estoy reservando 4 bytes, por ese motivo no es necesario reservar primero memoria para las cadenas
    de caracteres como el nombre del propietario o el color, que se encuentran dentro de la estructura
   (donde apunta el puntero).

   Si quisiera ver el tamaño en bytes de lo que ocupa la estructura, tengo que ir dentro de la direccion
   de memoria guardada por el puntero a estructura, es decir

   printf("\nEl tamaño de la estructura es: %d\n", sizeof(*vehiculos)); // 54bytes.
   Agregando el operador indireccion.
    ************/
