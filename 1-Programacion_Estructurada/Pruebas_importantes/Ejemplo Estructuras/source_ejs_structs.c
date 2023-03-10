#include "header_ejs_structs.h"

void alterar_valor (entero_t *var)
{
    var->valor = 0x3EC00000;
}

void imprimir_campo (entero_t *var)
{
    uint8_t *byte;
    byte = (uint8_t *)&var->valor;
    for (int i = 0; i < 4; i++)
    {
        printf("%02X\n", byte[3-i]);
    }
    printf("\n");
}
