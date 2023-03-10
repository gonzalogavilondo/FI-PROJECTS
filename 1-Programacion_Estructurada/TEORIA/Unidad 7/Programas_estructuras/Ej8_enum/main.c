#include <stdio.h>
#include <stdlib.h>

enum espectro {rojo, naranja, amarillo, verde, azul, violeta};
enum precios {nulo, cien=100, cien1, cien2, dosc=200, dosc1};

int main()
{
    enum espectro color;

    color = azul;

    printf("El tamaño de color es = %d\n\n", sizeof(color));
    printf("El valor de amarillo es = %d, color = %d\n\n", amarillo, color);

    for(color=rojo; color<violeta; color++)
        printf("El valor de color es = %d\n", color);

    printf("\nEl primer valor de precios es  = %d\n", nulo);
    printf("El segundo valor de precios es = %d\n", cien);
    printf("El tercer valor de precios es  = %d\n", cien1);
    printf("El cuarto valor de precios es  = %d\n", cien2);
    printf("El quinto valor de precios es  = %d\n", dosc);
    printf("El sexto valor de precios es   = %d\n\n", dosc1);

    if(color == violeta)
        printf("El color es violeta\n\n");
    else
        printf("El color es distinto de violeta\n\n");

    return 0;
}
