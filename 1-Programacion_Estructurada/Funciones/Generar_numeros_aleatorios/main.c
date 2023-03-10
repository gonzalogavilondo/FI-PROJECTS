#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define RANGO 20

int main()
{
    int num[RANGO];

    srand(time(NULL));
    for(int i = 0; i < RANGO; i++)
    {
        num[i] = 12 + rand()%(RANGO - 12 + 1);

        /*
        formula = limite_inferior + rand()% (limite_superior - limite_inferior + 1)

        Si hubiese puesto num[i] = rand()%10; El resultado serian numero entre 0 y 9, porque rand
        es un numero aleatorio dividido entre 10 y su resto esta comprendido entre 0 y 9...
        lo mismo pasaria si rand()%100 serian numeros del 0 al 99

        12 es el numero en que estara comprendido, entre 12 y RANGO (20)
        */

        printf("%d  ", num[i]);
    }

    return 0;
}
