#include <stdio.h>

float calculo(float n1, float n2, float *mult)
{
    float suma = 0.0;
    suma = (n1 + n2);
    *mult = (n1 * n2);

    return suma;
}
