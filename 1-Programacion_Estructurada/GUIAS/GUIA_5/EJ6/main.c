#include "cosas_raras.h"

int main()
{
    int num = 1, mn = 0, mx = 0, sum_num_neg = 0, i = 0;
    float prod_num_pos = 0.0;
    int numeros[1000] = {0};
    printf("Ingrese numeros. Para salir presione 0.\n");
    do
    {
        fflush(stdin); /*Limpia el buffer de entrada, para asegurarse que no se va a asignar otra cosa mas que lo que ingresa el usuario.*/
        scanf("%i", &num);
        int repite = 0;
        int j = 0;
        while (repite == 0 && j <= i) /*Recorre el arreglo y sale si el número está repetido o ya se lo recorrió todo.*/
        {
            if (num == numeros[j]) /*NOTA: En el caso de ingresar 0, va a recorrer el arreglo y en algún punto se va a chocar con 0, por lo cual se salta el valor como si fuera un repetido.*/
            {

                repite = 1;
            }
            j++;
        }
        if (repite == 0)    /*Si el número no se repite, se lo asigna al arreglo. Además aumenta en 1 la variable i, que es la cantidad neta de elementos ingresados en el arreglo.*/
        {
            numeros[i] = num;
            i++;
        }
    }while (num != 0); /*Repite el código hasta que el usuario ingrese 0.*/

    mn = minimo(numeros, i);
    mx = maximo(numeros, i);
    sum_num_neg = suma_negativos (numeros, i, mn);
    prod_num_pos = prod_positivos (numeros, i, mx);


    /*OPCIONAL: Imprimir todo para verificar los resultados obtenidos.*/
    printf("VECTOR\n(");
    for (int j = 0; j < i; j++)
    {
        printf("%i, ", numeros[j]);
    }
    printf("\b\b)\n"); /*Borra la última coma y la reemplaza por un ')'.*/
    printf("MINIMO: %i\n", mn);
    printf("MAXIMO: %i\n", mx);
    printf("SUMA VALORES NEGATIVOS (menos el minimo): %i\n", sum_num_neg);
    printf("MULTIPLICACION VALORES POSITIVOS (menos el maximo): %.0f\n", prod_num_pos);


    return 0;
}

