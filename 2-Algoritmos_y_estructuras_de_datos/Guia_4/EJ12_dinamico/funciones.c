#include "declaraciones.h"
///////////////////////////FUNCIONES////////////////////////////
void borrar_espacios(char *str) //Funcion para borrar los espacios de una cadena terminada en \0
{
    int i = 0, j = 0;

    while(str[i] != '\0')
    {
        if(str[i] != ' ')
        {
            str[j++] = str[i];
        }
        i++;
    }
    str[j] = '\0';
}

void cargar_fila_pila(FILA *pF, PILA *pS, int largo, char *frase)
{
    for(int i = 0; i < largo; i++)
    {
        push(pS, frase[i]);
        enqueue(pF, frase[i]);
    }
}

void comparar(FILA *pF, PILA *pS, int largo, int *pXfila, int *pXpila)
{
    int contador = 0;
    printf("COMPARAMOS CADA CARACTER:\n");
    for(int i = 0; i < largo; i++)
    {
        //Saco elementos
        dequeue(pF, pXfila);
        pop(pS, pXpila);
        printf("pXfila: %c\n", *pXfila);
        printf("pXpila: %c\n", *pXpila);

        //Comparo
        if(*pXfila == *pXpila)
        {
            contador++;
            printf("Contador: %d\n", contador);
        }
        else
        {
            printf("No es un palindromo.\n");
            contador = 0;
            i = largo - 1;
        }
    }
    if(contador == largo)
    {
        contador = 0;
        printf("Es un palindromo.\n");
    }
}
