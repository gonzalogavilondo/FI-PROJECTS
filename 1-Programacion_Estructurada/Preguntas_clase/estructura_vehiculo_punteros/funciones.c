#ifndef FUNCIONES_C_INCLUDED
#define FUNCIONES_C_INCLUDED

#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <string.h>
#include "declaraciones_funciones.h"

void ingreso_datos(datos_vehiculo *vehiculos)
{
    char barra;
    int nombre;
    int color;
    char aux[LONGMAX];

    printf("Ingrese el nombre del  propietario: ");
    fflush(stdin);
    fgets(aux, LONGMAX, stdin);
    nombre = strlen(aux);
    //Reservamos memoria para nombre:
    vehiculos->nombre = (char*)malloc(nombre*sizeof(char));
    //Copiamos el string
    strcpy(vehiculos->nombre, aux);
    //Estructura tipo
    printf("\nIngrese el peso del vehiculo: ");
    scanf("%f", &vehiculos->t_vehiculo.peso);
    printf("\nIngrese la cantidad de ruedas: ");
    scanf("%i", &vehiculos->t_vehiculo.ruedas);
    printf("\nIngrese la potencia <HP>: ");
    scanf("%f", &vehiculos->t_vehiculo.potencia);
    printf("\nIngrese la cantidad de pasajeros: ");
    scanf("%i", &vehiculos->t_vehiculo.capacidad_pasajeros);

    //Estructura modelo
    printf("\nIngrese el color del vehiculo: ");
    fflush(stdin);
    fgets(aux, LONGMAX, stdin);
    color = strlen(aux); //Cantidad de caracteres de aux.
    //Reservamos memoria para color:
    vehiculos->m_vehiculo.color = (char*)malloc(color*sizeof(char));
    //Copiamos el string
    strcpy(vehiculos->m_vehiculo.color, aux);
    printf("Ingrese la fecha de fabricacion de la forma <dd/mm/yyyy>: ");
    scanf("%i%c%i%c%i", &vehiculos->m_vehiculo.fabricacion.dia, &barra, &vehiculos->m_vehiculo.fabricacion.mes, &barra, &vehiculos->m_vehiculo.fabricacion.anio);

    //Estructura patente

    printf("\nIngrese las 2 letras de la patente: ");
    scanf("%s", vehiculos->p_vehiculo.letras);
    printf("\nIngrese los 3 numeros de la patente: ");
    scanf("%i", &vehiculos->p_vehiculo.numero);
    printf("\nIngrese la fecha de ultima transferencia de la forma <dd/mm/yyyy>: ");
    scanf("%i%c%i%c%i", &vehiculos->p_vehiculo.ult_transferencia.dia, &barra, &vehiculos->p_vehiculo.ult_transferencia.mes, &barra, &vehiculos->p_vehiculo.ult_transferencia.anio);

    //Pausa y borrado de pantalla
    system("pause");
    system("cls || clear");

}

void impresion_datos(const datos_vehiculo *vehiculos)
{

    printf("Nombre del propietario: %s", vehiculos->nombre);

    //Estructura tipo
    printf("\nPeso: %.2f", vehiculos->t_vehiculo.peso);
    printf("\nCantidad de ruedas: %i", vehiculos->t_vehiculo.ruedas);
    printf("\nPotencia: %.2f", vehiculos->t_vehiculo.potencia);
    printf("\nCapacidad de pasajeros: %i", vehiculos->t_vehiculo.capacidad_pasajeros);

    //Estructura modelo
    printf("\nColor: %s", vehiculos->m_vehiculo.color);
    printf("\nFecha de fabricacion <dd/mm/yyyy>: %i/%i/%i", vehiculos->m_vehiculo.fabricacion.dia, vehiculos->m_vehiculo.fabricacion.mes, vehiculos->m_vehiculo.fabricacion.anio);

    //Estructura patente
    printf("\nPatente: %s%i", vehiculos->p_vehiculo.letras, vehiculos->p_vehiculo.numero);
    printf("\nFecha de ultima transferencia <dd/mm/yyyy>: %i/%i/%i\n\n", vehiculos->p_vehiculo.ult_transferencia.dia, vehiculos->p_vehiculo.ult_transferencia.mes, vehiculos->p_vehiculo.ult_transferencia.anio);


}

#endif // FUNCIONES_C_INCLUDED
