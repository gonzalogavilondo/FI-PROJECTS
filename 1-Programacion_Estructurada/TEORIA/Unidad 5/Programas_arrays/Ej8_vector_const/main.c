#include <stdio.h>

float avg_vector(float [], int);   // retorna el promedio de los valores
//float avg_vector(const float [], int);   // retorna el promedio de los valores

int main()
{
    float fValores[5] = {20.2, 30.3, 40.4, 50.5, 10.1};
    float promedio;

    promedio = avg_vector(fValores, 5);
    printf("\nEl promedio de los valores es = %.2f\n\n", promedio);
    printf("El valor modificado de fValores[1] = %.2f\n\n", fValores[1]);

    return 0;
}

float avg_vector(float vector[], int dim)
//float avg_vector(const float vector[], int dim)
{
    float avg=0;

    for(int cnt=0; cnt<dim; cnt++)
    {
        avg+= vector[cnt];
    }
    avg/=dim;

    /**** se produce un error si quiero modificar el valor y uso const ****/
    vector[1] = 27.5;       // se modifica el valor del parámetro

    return avg;
}
