#include "declaraciones.h"

float *reservar_memoria(int cnt_elementos)
{
    float *vector = NULL;

    vector = (float *)calloc(cnt_elementos, sizeof(float));

    if(vector == NULL)
    {
        printf("No se ha podido reservar espacio en memoria.\n");
        exit(1);
    }

    return vector;
}

void completar_vector(float *vector, int cnt_elementos)
{
    for(int j = 0; j < cnt_elementos; j++)
    {
        printf("\t-COMPLETE EL VECTOR ORDENADO DE MENOR A MAYOR-\n\n");
        imprimir_vector(vector, cnt_elementos);
        printf("Digite un valor para el elemento[%i]: ", j+1);
        scanf("%f", &vector[j]);
        system("cls || clear"); //Para que funcione tambien en linux el "clear"

    }
}

void imprimir_vector(float *vector, int cnt_elementos)
{
    printf("|\t");
    for(int j = 0; j < cnt_elementos; j++)
    {
        printf("%.2f\t", vector[j]);
    }
    printf("|\n\n");

}

int busqueda_binaria(float *vector, float condicion, int cnt_elementos)
{
    int low, mid, high;
    low = 0; high = (cnt_elementos - 1); //low seria la posicion inicial y high la posicion final.

    while(low <= high)  //Mientras que la posicion inicial sea menor a la posicion final
    {
        mid = (low + high)/2; //Encuentro el valor medio.
        if(vector[mid] < condicion)        //Verifico si el valor que esta en esa posicion es menor al valor que quiero encontrar
        {
            low = (mid + 1);   //Si es menor, entonces achico el intervalo de busqueda y mid pasa a ser el nuevo low del intervalo.
        }
        else
        {
            if (vector[mid] > condicion) //Como no era menor, verifico si es mayor el valor que esta en esa posicion con respecto al que quiero hayar.
            {
                high = (mid - 1);//Si es mayor, entonces achico el intervalo de busqueda y mid pasa a ser el nuevo high del intervalo.
            }
            else //Si no es ni mayor, ni menor, quiere decir que entonces el valor que esta en la posicion [mid], es el que queriamos buscar.
            {
                return(mid);
            }
        }
    }

    return(-1);
}

void imprimir(int posicion, float condicion)
{
    printf("\n\nLa condicion es hayar en el vector la posicion del numero: %.2f", condicion);

    if(posicion == -1)
    {
        printf("\n\nNo se ha podido encontrar la posicion del valor pedido.\n");
    }
    else
    {
        printf("\n\nLa posicion del numero pedido es: %d\n\n", posicion+1);
    }
}


