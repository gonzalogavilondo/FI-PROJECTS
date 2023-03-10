#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

int main()
{
    int8_t abece[28] = {0}; //Son 27 letras las del abecedario contando la ñ.
    int8_t dim = (sizeof(abece)/sizeof(char));

    for (int i = 0; i < dim - 2; i++)
    {
        abece[i] = 0x41+i; /* A partir del 65 empiezan las letras en la tabla ASCII
                             dim -2  porque 90(la Z) y 65(la A) = 26 contando desde la A a la Z sin la ñ
                             como dim = 28 y necesito que sea igual a 26, ya que  arranca de 0 entonces pararia en 25
                            en el bucle y en total imprimiria 26 letras  que son las que necesito por no estar la ñ --> dim = dim-2 = 26
                           */
    }
    // Impresion del vector.
    for (int i = 0; i < dim - 2; i++)
    {
        printf("%c, ", abece[i]);
    }
    printf("\b\b ");
    return 0;
}
