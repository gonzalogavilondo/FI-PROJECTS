#include "header_menu.h"

void ingreso_impresion (uint32_t[], uint8_t, uint8_t);

int main()
{
    uint8_t op = 0;
    uint32_t vec[10] = {0};
    uint8_t dim_vec = sizeof(vec)/sizeof(uint32_t);
    op = opcion_elegida();
    ingreso_impresion(vec, dim_vec, op);
    return 0;
}

void ingreso_impresion (uint32_t vector[], uint8_t longitud, uint8_t opcion)
{
    uint8_t i = 0, c = 0;
    printf("CARGUE EL VECTOR.\n");
    if (opcion == 1)
    {
        printf("| ");
        while (i != longitud)
        {
            c = getch();
            if (c == '\b')
            {
                i--;
                printf("\b \b");
            }
            else
            {
                vector[i] = c;
                printf("%c ", vector[i]);
                i++;
            }
        }
        printf("|");
    }
    else
    {
        printf("|");
        for (int i = 0; i < longitud; i++)
        {
            printf(" %u ", vector[i]);
        }
        printf("|");
    }
}

