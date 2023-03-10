#include <stdio.h>
#include <locale.h>

int main()
{
    float fvalor = 2.3;
    float *ptrf;
    short hvalor = 255;
    short *ptrh;
    int gvalor = 20;
    int *ptrg;

    ptrf = &fvalor;
    *ptrf = fvalor;

    printf("Direccion de memoria de fvalor: ");
    printf("\n%p", ptrf);
    printf("\nDato en la posicion de memoria apuntada: ");
    printf("\n%.2f", *ptrf);


    ptrh = &hvalor;

    printf("\nDireccion de memoria de hvalor: ");
    printf("\n%u", ptrh);

    printf("Direccion de memoria de gvalor:")
    ptrg = &gvalor;
    printf("\n%u", ptrg);





    return 0;
}
