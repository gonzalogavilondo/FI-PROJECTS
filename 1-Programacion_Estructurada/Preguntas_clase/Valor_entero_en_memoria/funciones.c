#include <stdio.h>
#include <locale.h>
#include <stdint.h>
#include <stdlib.h>
#include "declaraciones_funciones.h"

void entero_a_bytes(uint32_t num, uint8_t bytes[], double elementos) //descompone un entero en sus bytes y lo guarda en un arreglo.
{
    uint8_t mask = 0xFF;
    for(int i = 0; i < elementos; i++)
    {
        bytes[i] = ((num >> i*8) & mask);
    }
}

void mostrar_bytes(const uint8_t bytes[], double elementos)
{
    for(int i = 0; i < elementos; i++)
    {
        printf("%X  ", bytes[i]);
    }
    puts("\n");
}
int cargar_tipo_de_dato(double tipo_de_dato)
{
    int salir = 0;
    do
    {
        system("cls");
        printf("Ingrese la cantidad de bytes que tiene su tipo de dato: ");
        scanf("%lf", &tipo_de_dato);
        if (tipo_de_dato > ELEMENTOSMAX)
        {
            printf("Ha exedido el limite de memoria.\n");
            salir = 0;
        }
        else
        {
            salir = 1;
        }

    }while(salir == 0);
    return tipo_de_dato;
}
