#include <stdio.h>
#include <stdlib.h>

int main()
{
    int num;
    printf("Ingrese un codigo ASCII para convertirlo en el caracter que representa: \n");
    scanf("%i", &num);
    printf("El caracter que representa el codigo ASCII ingresado es: %c\n", num);
    return 0;
}
