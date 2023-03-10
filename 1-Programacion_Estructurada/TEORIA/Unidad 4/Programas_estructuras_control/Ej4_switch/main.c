#include  <stdio.h>
#include<locale.h>

#define    BISIESTO     1

int main()
{
    int mes,
        dias;

    setlocale(LC_ALL,"spanish");
    printf("\nIngrese el número del mes: ");
    scanf("%i", &mes);

    switch(mes)
    {
        case 4: case 6: case 8: case 11:
            dias = 30;
            break;
        case 2:
            if(BISIESTO)
                dias = 29;
            else
                dias = 28;
            break;
        default:
            dias = 31;
    }

    printf("\n\nEl mes %d tiene %d dias.\n\n", mes,  dias);

    return 0;
}
