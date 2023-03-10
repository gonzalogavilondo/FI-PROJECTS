#include <stdio.h>
#include<locale.h>

int main()
{
    int  i;
    float num,
          producto;

    setlocale(LC_ALL,"spanish");

    for (i=1, producto=1; i<=5; i++)
    {
        printf("\nEntre número %d: ",i);
        scanf("%f", &num);
        if(num==0)
        {
            continue;                                      /* evita multiplicar por 0 */
        }                                                  /* end if()  */
        //if(num!=0)                                         /* permite eliminar el continue */
        producto*= num;
    }                                                      /* end for() */

    printf("\nProducto = %f", producto);

    return 0;
}
