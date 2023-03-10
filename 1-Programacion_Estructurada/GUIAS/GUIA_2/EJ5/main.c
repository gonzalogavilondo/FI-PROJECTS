#include <stdio.h>
#include <stdlib.h>
void pintas_a_moleculas(float x);
int main()
{
    float x = 0.0; // Variable en la cual voy a guardar la cantidad de pintas.

    /* Lo que tengo que hacer ahora, es pedir la cantidad de agua en pintas,
    y me muestre la cantidad de moleculas, siendo la equivalencia:  1 pinta = 1,1467E25 moleculas de agua. */

    printf("Ingrese la cantidad de agua en pintas: ");
    scanf("%f", &x);
    pintas_a_moleculas(x);

    return 0;
}

  void pintas_a_moleculas(float pintas_ingresadas)
    {
        const float MOLECULAS = 1.4167E25; //1 Pinta = 1.1467E25 moleculas de agua
        float resultado;

        resultado = (pintas_ingresadas * MOLECULAS);

        printf("La cantidad de moleculas de acuerdo a la cantidad de pintas ingresadas es: %.2f", resultado);
    }

