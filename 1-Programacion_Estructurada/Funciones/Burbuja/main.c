#include <stdio.h>
#include <stdlib.h>

int main()
{
    int array[6] = {1, 3, 4, 2, 5, 6};
    int aux;

    for(int i = 0; i < 6; i++)
    {
        for(int j = 0; j < 6; j++)
        {
            if(array[j] > array[j+1])
            {
                aux = array[j];
                array[j] = array[j+1];
                array[j+1] = aux;
            }
        }

        printf("%i ", array[i]);
    }

    return 0;
}
