#include <stdio.h>
#include <stdlib.h>

int main()
{
    char car1 = '0';
    char car2 = '0';
    char car3 = '0';
    printf("Escriba tres caracteres, separados por comas: ");
    scanf("%c,%c,%c", &car1, &car2, &car3);
    while(car2 < car1 || car2 > car3)
    {
        int aux = car1;
        car1 = car2;
        car2 = aux;
        if (car3 < car2)
        {
            int aux = car3;
            car3 = car2;
            car2 = aux;
        }
    }
    printf("%c,%c,%c", car1, car2, car3);
}
