#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <string.h>
#include "declaraciones_funciones.h"

void ingreso_datos(datos_vehiculo vehiculos[LONGMAX], int indice)
{
    int nombre;
    int color;
    char barra;
    for(int cnt = 0; cnt < indice; cnt ++)
    {
        printf("Ingrese el nombre del %i%c propietario: ", cnt+1, 248);
        fgets(vehiculos[cnt].nombre, LONGMAX, stdin);
        fflush(stdin);
        nombre = strlen(vehiculos[cnt].nombre);
        vehiculos[cnt].nombre = (char*)malloc(nombre*sizeof(char));

        //Estructura tipo
        printf("\nIngrese el peso del vehiculo: ");
        scanf("%f", &vehiculos[cnt].t_vehiculo.peso);
        printf("\nIngrese la cantidad de ruedas: ");
        scanf("%i", &vehiculos[cnt].t_vehiculo.ruedas);
        printf("\nIngrese la potencia <HP>: ");
        scanf("%f", &vehiculos[cnt].t_vehiculo.potencia);
        printf("\nIngrese la cantidad de pasajeros: ");
        scanf("%i", &vehiculos[cnt].t_vehiculo.capacidad_pasajeros);

        //Estructura modelo
        printf("\nIngrese el color del vehiculo: ");
        fgets(vehiculos[cnt].m_vehiculo.color, LONGMAX, stdin);
        fflush(stdin);
        color = strlen(vehiculos[cnt].m_vehiculo.color);
        vehiculos[cnt].m_vehiculo.color = (char*)malloc(color*sizeof(char));
        printf("Ingrese la fecha de fabricacion de la forma <dd/mm/yyyy>: ");
        scanf("%i%c%i%c%i", &vehiculos[cnt].m_vehiculo.fabricacion.dia, &barra, &vehiculos[cnt].m_vehiculo.fabricacion.mes, &barra, &vehiculos[cnt].m_vehiculo.fabricacion.anio);

        //Estructura patente

        printf("\nIngrese las 2 letras de la patente: ");
        scanf("%s", vehiculos[cnt].p_vehiculo.letras);
        printf("\nIngrese los 3 numeros de la patente: ");
        scanf("%i", &vehiculos[cnt].p_vehiculo.numero);

        printf("\nIngrese la fecha de ultima transferencia de la forma <dd/mm/yyyy>: ");
        scanf("%i%c%i%c%i", &vehiculos[cnt].p_vehiculo.ult_transferencia.dia, &barra, &vehiculos[cnt].p_vehiculo.ult_transferencia.mes, &barra, &vehiculos[cnt].p_vehiculo.ult_transferencia.anio);

    }
    //Pausa y borrado de pantalla
    system("pause");
    system("cls || clear");

}

void impresion_datos(datos_vehiculo vehiculos[LONGMAX], int dimension)
{
    for(int cnt = 0; cnt < dimension; cnt++)
    {
        printf("Nombre del propietario: %s", vehiculos[cnt].nombre);

        //Estructura tipo
        printf("\nPeso: %.2f", vehiculos[cnt].t_vehiculo.peso);
        printf("\nCantidad de ruedas: %i", vehiculos[cnt].t_vehiculo.ruedas);
        printf("\nPotencia: %.2f", vehiculos[cnt].t_vehiculo.potencia);
        printf("\nCapacidad de pasajeros: %i", vehiculos[cnt].t_vehiculo.capacidad_pasajeros);

        //Estructura modelo
        printf("\nColor: %s", vehiculos[cnt].m_vehiculo.color);
        printf("\nFecha de fabricacion <dd/mm/yyyy>: %i/%i/%i", vehiculos[cnt].m_vehiculo.fabricacion.dia, vehiculos[cnt].m_vehiculo.fabricacion.mes, vehiculos[cnt].m_vehiculo.fabricacion.anio);

        //Estructura patente


        printf("\nPatente: %s%i", vehiculos[cnt].p_vehiculo.letras, vehiculos[cnt].p_vehiculo.numero);

        printf("\nFecha de ultima transferencia <dd/mm/yyyy>: %i/%i/%i\n\n", vehiculos[cnt].p_vehiculo.ult_transferencia.dia, vehiculos[cnt].p_vehiculo.ult_transferencia.mes, vehiculos[cnt].p_vehiculo.ult_transferencia.anio);

    }

}


