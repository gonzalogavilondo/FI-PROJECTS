#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include "declaraciones_funciones.h"

int main()
{
    double tipo_de_dato = 0x0000000000000000; //Elegi double porque tiene 8 bytes, se verifica asi: printf("%d", sizeof(elementos));.
    double elementos = 0x0000000000000000;
    uint32_t num = 0x00000000;
    uint8_t bytes[ELEMENTOSMAX] = {0};

    printf("Ingrese un numero entero: ");
    scanf("%i", &num);
    system("pause");
    system("cls || clear");
    elementos = cargar_tipo_de_dato(tipo_de_dato);
    entero_a_bytes(num, bytes, elementos);
    printf("-En memoria- \n\n");
    mostrar_bytes(bytes, elementos);

    return 0;
}
