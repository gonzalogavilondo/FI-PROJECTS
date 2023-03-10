#include <stdio.h>
#include <locale.h>
#include <stdint.h>
#include <stdlib.h>
#include "declaraciones_funciones.h"

void entero_a_bytes(uint32_t num, uint8_t bytes[]) //Descompone un entero en sus bytes y lo guarda en un arreglo.
{
    uint8_t mask = 0xFF;
    for(int i = (BYTES-1); i > -1; i--)  //Como BYTES = 4, y el arreglo empieza desde el elemento 0 al 3... si yo arranco desde 4 que seria BYTES entonces estaria parado en una posicion que no existe o que si lo hace, pero podria ser otro arreglo por ejemplo, ya que las variables se guardan en posiciones sucesivas de memoria.
    {
        bytes[BYTES-1-i] = ((num >> i*8) & mask);
    }
}

void mostrar_bytes(const uint8_t bytes[], uint32_t elementos)
{
    for(int i = 0; i < elementos; i++)
    {
        printf("%X  ", bytes[i]);
    }
    puts("\n");
}
int cargar_tipo_de_dato(uint32_t tipo_de_dato)
{
    int salir = 0;
    do
    {
        system("cls");
        printf("Ingrese la cantidad de bytes que tiene su tipo de dato: ");
        scanf("%d", &tipo_de_dato);
        if (tipo_de_dato > ELEMENTOSMAX)
        {
            printf("Ha exedido el limite de memoria.\n");
            system("pause");
            salir = 0;
        }
        else
        {
            salir = 1;
        }

    }while(salir == 0);
    return tipo_de_dato;
}

int bytes_a_entero(uint32_t num, const uint8_t bytes[], uint32_t elementos)
{
    uint32_t entero = 0x00000000;
    for (int i = 0; i < elementos; i++)
    {
        entero += bytes[i] << ((elementos-1-i)*8);//Son "elementos"(los bytes que eligio el usuario que tenga).Pero como el conteo de la posicion de cada elemento del arreglo comienza desde 0, le resto 1 y lo multiplico por 8 (bits), para ir corriendo byte a byte.
    }

    return entero;
}
