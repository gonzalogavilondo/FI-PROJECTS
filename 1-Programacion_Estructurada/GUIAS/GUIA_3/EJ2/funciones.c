#include "declaraciones_funciones_reales.h"

float area(float PI, int radio)
{
    float res;

    res = PI*radio*radio;

    return res;
}
float perimetro(float PI, int radio)
{
    float res;

    res = 2*PI*radio;

    return res;
}
float volumen(float PI, int radio)
{
    float res;

    res = PI*radio*radio*radio*(float)4/3;

    return res;
}
