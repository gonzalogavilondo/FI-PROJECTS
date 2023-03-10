#include "declaraciones_funciones_reales.h"

float calcular_promedio(float *datos, int cantidad_datos)
{
    int indice = 0;
    float suma = 0;
    float media = 0;

    for(indice = 0; indice < cantidad_datos; indice++)
    {
        suma += datos[indice];
    }

    media = (suma/cantidad_datos);

    return media;
}
