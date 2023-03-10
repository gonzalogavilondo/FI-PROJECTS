#include <stdio.h>
#include <stdlib.h>
void my_recursive_function(int n);

int main()
{
    my_recursive_function(10);

    return 0;
}

void my_recursive_function(int n)
{
    if(n == 0)//Criterio de base.
    {
        return;
    }
    printf("%d ",n);
    my_recursive_function(n-1);//Aproximacion progresiva.
}
//Nota: El inciso "L" y "N" son iguales.
