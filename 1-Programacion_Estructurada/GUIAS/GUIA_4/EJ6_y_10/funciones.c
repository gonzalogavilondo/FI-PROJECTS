#include <math.h>
#include "declaraciones_funciones_reales.h"

float area_cuadrado (float lado)
{
    float area = lado*lado;
    return area;
}
float area_circulo (float radio)
{
    const float PI = 3.141592654;
    float area = PI*radio*radio;
    return area;
}
float area_triangulo (float lado)
{
    float area = (lado*lado)*sqrt(3)*(1.0/4);
    return area;
}
