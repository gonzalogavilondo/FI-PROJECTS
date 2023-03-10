#include "declaraciones.h"

void OrdInsercion(int vector[LONGMAX], int cnt_elementos)
{
    int i, j, aux;

    for(i = 1; i < cnt_elementos; i++)
    {
        j = i;
        aux = vector[i];                  //Guarda el valor que quiere insertar en una variable auxiliar.
        while(j > 0 && aux < vector[j-1]) //Recorre de derecha a izquierda
        {
            vector[j] = vector[j-1];      //Se detiene cuando el anterior ya NO es mayor.
            j--;                          //En cada caso, corre el numero a la derecha.
        }
        vector[j] = aux;                  //Al terminar, coloca el valor en su posicion final.
    }

}

void busqueda_binaria(int vector[LONGMAX], int condicion[7], int posicion[7])
{
    int low, mid, high;

    for(int i = 0; i < 7; i++)
    {
        low = 0;
        high = (LONGMAX - 1); //low seria la posicion inicial y high la posicion final.
        while(low <= high)  //Mientras que la posicion inicial sea menor a la posicion final
        {
            mid = (low + high)/2; //Encuentro el valor medio.
            if(vector[mid] < condicion[i])        //Verifico si el valor que esta en esa posicion es menor al valor que quiero encontrar
            {
                low = (mid + 1);   //Si es menor, entonces achico el intervalo de busqueda y mid pasa a ser el nuevo low del intervalo.
            }
            else
            {
                if (vector[mid] > condicion[i]) //Como no era menor, verifico si es mayor el valor que esta en esa posicion con respecto al que quiero hayar.
                {
                    high = (mid - 1);//Si es mayor, entonces achico el intervalo de busqueda y mid pasa a ser el nuevo high del intervalo.
                }
                else //Si no es ni mayor, ni menor, quiere decir que entonces el valor que esta en la posicion [mid], es el que queriamos buscar.
                {
                    posicion[i] = mid;
                    i++;
                    low = 0; //Tengo que hacer low = 0, ya que una vez que encuentre el valor, para allar el siguiente va a quedar guardado el ultimo low y va a salir el programa.
                }
            }
        }

    }

}

void imprimir_vector(int vector[LONGMAX], int cnt_elementos)
{
    printf("|\t");
    for(int j = 0; j < cnt_elementos; j++)
    {
        printf("%d\t", vector[j]);
    }
    printf("|\n\n");

}


void imprimir(int posicion[7], int condicion[7])
{
    int i;

    for(i = 0; i < 7; i++)
    {
        printf("\n\nLa condicion es hayar en el vector la posicion del numero: %d", condicion[i]);

        if(posicion[i] == -1)
        {
            printf("\n\nNo se ha podido encontrar la posicion del valor pedido.\n");
        }
        else
        {
            printf("\n\nLa posicion del numero pedido es: %d\n\n", posicion[i]+1);
        }

    }

}

