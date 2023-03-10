#include <stdio.h>
#include <stdlib.h>

int main()
{
    int num = 0;
    printf("Digite un numero: ");
    scanf("%i", &num);

    if((num ^ 0x01))
    {
        printf("El numero es par.");
    }
    else
    {
        printf("El numero es impar.");
    }


    return 0;
}
