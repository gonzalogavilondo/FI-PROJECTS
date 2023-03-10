#include <stdio.h>
#include<locale.h>

int main()
{
    int  i;
    float num, suma=0;

    setlocale(LC_ALL,"spanish");
    for (i=1; i<=10; i++)
    {
        printf("\nEntre número %d: ", i);
        scanf("%f", &num);
        if(num < 0.0)
        {
                break;        /* sale del for() si num < 0 */
        }                                                                                 /* end if()  */
        suma+= num;
    }
                                                                                          /* end for() */
    printf("\nPromedio = %f\n\n", suma/(i-1) );

    return 0;
}
