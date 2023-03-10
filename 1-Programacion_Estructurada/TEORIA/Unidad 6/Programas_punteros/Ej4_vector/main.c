#include <stdio.h>
#include <stdlib.h>

void funcion1(void);
void funcion2(void);

int main()
{
    funcion1();

    funcion2();

    return 0;
}

void funcion1(void)
{
    int lista[6] = { 10, 7, 4, -2, 30, 6};
    int *ptr = lista;         // es equivalente a  ptr = &lista[0];
    int  x;

    /**** Supongo que lista está en la posición 0x1500 ****/
    x = lista[1];              // asigna x = 7
    x = *(lista+4);            // x = 30
    x = ptr[3];                // x = -2
    ptr = &lista[3];           // ptr = 105C
    x = *(ptr+2);              // x = 6

    printf("*(lista+4) = %d\n", *(lista+4));
    printf("lista[5] = %d\n", lista[5]);
    printf("Valor final de x = %d\n\n", x);
}


void funcion2(void)
{
    int arr[10];
    int *p_int ;
    char *pc;
    p_int = arr;
    pc = (char *)p_int;

    int x=0;
    do
    {
        printf("Valor de x = %d\n",x++);
    }while ( (int *)(pc + x) != (p_int + 3) );

    printf("\nValor de x = %d\n\n", x);
}
