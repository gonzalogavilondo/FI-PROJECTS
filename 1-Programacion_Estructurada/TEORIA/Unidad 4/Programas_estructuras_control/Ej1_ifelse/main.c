#include <stdio.h>

#define UMBRAL  3.5

int main()
{
    float fvalor = 1.0;

    do                            /* mientras que el numero sea distinto de 0 */
    {
        printf("\nIngrese un flotante = ");
        scanf("%f", &fvalor);

        if(fvalor < (float)UMBRAL)
        {
            printf("\nEl valor ingresado es menor que %f\n", (float)UMBRAL);
        }
        else
        {
            printf("\nEl valor ingresado es mayor que %f\n", (float)UMBRAL);
        }

/*        fvalor < (float)UMBRAL ?
            printf("\nEl valor ingresado es menor que %f\n", (float)UMBRAL) :
            printf("\nEl valor ingresado es mayor que %f\n", (float)UMBRAL);
*/
    } while(fvalor != 0);

    return 0;
}
