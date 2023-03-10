#include <stdio.h>
#include <stdlib.h>
int main()
{
    int array[4],    // vector de datos
        i;           // usada para armar lazos

    // mostrar las posiciones de memoria a medida que se llenan
    for (i=0; i<4; i++)
    {
        printf("Ingrese el elemento %d/3: ", i);
        scanf("%d", &array[i]);
        printf("\nQue se encuentra en la posicion de memoria: %#X \n", &array[i]);
    }

    // ingreso de un elemento en particular
    printf("\nIngrese el elemento 2: ");
    scanf("%d", &array[2]);

    // imprimo todos los valores para verificar
    puts("\n\n");
    for (i=0; i<4; i++)
    {
        printf("El elemento %d vale = %d\n", i, array[i]);
    }

    // razonar que valor imprime a continuación
    puts("\n\n");
    printf("El elemento %d vale = %d\n\n", i, array[i]);

    /*Como i (contador) esta inicializado antes, fuera del lazo for, una vez que sale del lazo
    sale con el valor de i = 4, y como el array 4 no existe, le da un valor cualquiera(basura)*/

    return 0;
}
