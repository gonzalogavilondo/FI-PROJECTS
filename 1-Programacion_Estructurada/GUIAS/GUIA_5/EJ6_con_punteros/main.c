#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <stdbool.h>

bool num_repetido (const uint32_t *, uint32_t, uint32_t);
int main()
{
    uint32_t num = 1;
    uint32_t *numeros = NULL;
    numeros = &num+1;
    uint32_t i = 0;
    printf("Ingrese numeros. Cuando desee terminar ingrese presione 0.\n");
    while (num != 0)
    {
        //scanf("%i", &num);
        if (!num_repetido(numeros, num, i))
        {
            *(numeros+i) = num;
            i++;
        }
        num++;
    }
    return 0;
}

bool num_repetido (const uint32_t *numeros, uint32_t num, uint32_t cont)
{
    bool repe = false;
    uint32_t i = 0;
    while ( (!repe) && (i != cont) )
    {
        if ( (numeros+i) == (uint32_t *)num )
        {
            repe = true;
        }
        i++;
    }
    return false;
}


/* OTRA OPCION SERIA PREGUNTARLE CUANTOS VA A INGRESAR Y HACER UN FOR */
