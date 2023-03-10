#include <stdio.h>
#include <stdlib.h>

int main()
{
    int k = 0, i = 1, n = (i*(i+1))/2;
    printf("Hasta que termino de la sucesion desea imprimir? ");
    scanf("%i", &k);
    while (n<k)
    {
        printf("%i \n", n);
        i++;
        n = (i*(i+1))/2;
    }
    return 0;
}
