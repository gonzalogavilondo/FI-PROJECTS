#include <stdio.h>
#include <stdlib.h>

int main()
{
    const float A = 3.5;
    const float B = 6.5;
    float num = 0, acum = 0, prom = 0;
    printf("Escriba tantos numeros como desee. Cuando finalice presione 0.\n");
    int i = 0;
    do
    {
        scanf("%f", &num);
        if (num>A && num<B)
        {
            acum += num;
            i++;
        }
    }while (num != 0);
    prom = acum/i;
    printf("El promedio es: %.2f", prom);
    return 0;
}
