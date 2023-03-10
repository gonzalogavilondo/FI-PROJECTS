#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include "declaraciones_funciones.h"

int main()
{
    uint32_t tipo_de_dato = 0x00000000; //Tiene 4 bytes, un entero de maximo de 4 bytes se puede usar, se verifica asi: printf("%d", sizeof(elementos));.
    uint32_t elementos = 0x00000000;
    uint32_t num = 0x00000000;
    uint32_t entero = 0x00000000;
    uint8_t bytes[ELEMENTOSMAX] = {0};

    printf("Ingrese un numero entero: ");
    scanf("%i", &num);
    system("pause");
    system("cls || clear");
    elementos = cargar_tipo_de_dato(tipo_de_dato);
    entero_a_bytes(num, bytes);
    printf("-Numero entero expresado en bytes- \n\n"); //Los imprimo al reves de como esta en memoria.
    mostrar_bytes(bytes, elementos);
    entero = bytes_a_entero(num, bytes, elementos);
    printf("-Numero entero expresado en forma decimal-\n\n %i \n", entero);

    return 0;
}
