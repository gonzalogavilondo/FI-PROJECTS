#include "declaraciones.h"
/*
Un palíndromo es una cadena de caracteres que se lee igual hacia delante que hacia atrás
(pudiéndose modificar los espacios en blanco). Por ejemplo: Dábale arroz a la zorra el abad.
Escribir un programa para detectar si una cadena de caracteres es un palíndromo o no.
(Nota: un mecanismo efectivo de solución consiste en el uso simultáneo de una pila y una
cola).

SOLUCION:
Para poder ver si una cadena de caracteres es un palindromo, lo que podemos hacer
es lo siguiente: Rellenamos una pila y una fila con la cadena de caracteres sin espacios, luego
sabemos que cuando desapilamos una pila y cuando sacamos los elementos de una fila, como en una pila salen
primero los ULTIMOS que entraron y en una fila los PRIMEROS que entraron, vamos a poder comparar si
el PRIMER caracter y el ULTIMO son iguales (condicion para que una cadena de caracteres sea un palindromo).

NOTA: ME FALTARIA PONER QUE EL USUARIO INGRESE LA CADENA Y QUE SE RESERVE MEMORIA DE FORMA DINAMICA.
*/

int main()
{
    //Declaraciones de variables a utilizar
    char frase[] =  "DABALE ARROZ A LA ZORRA EL ABAD";
    int largo = strlen(frase);
    int *pXpila;
    int *pXfila;
    PILA *pS = NULL;
    FILA *pF = NULL;

    //Reservamos memoria
    pS = (PILA*)malloc(sizeof(PILA));
    pF = (FILA*)malloc(sizeof(FILA));
    pXpila = (int*)malloc(sizeof(int));
    pXfila = (int*)malloc(sizeof(int));

    //Inicializamos la fila
    inicializar_fila(pF);

    //Imprimimos la frase original con espacios
    printf("Frase original: %s\n\n", frase);

    //Borramos los espacios de la cadena
    borrar_espacios(frase);  // Me devuelve la cadena de caracteres sin espacios
    largo = strlen(frase);   //Cantidad de caracteres de la cadena sin los espacios

    //Imprimimos la frase sin espacios
    printf("Frase sin espacios: %s\n\n", frase);

    //Asigno a la pila y a la fila cada elemento
    cargar_fila_pila(pF, pS, largo, frase);

    //Comparamos la fila con la pila
    comparar(pF, pS, largo, pXfila, pXpila);

    //Libero memoria
    free(pS);
    free(pF);
    free(pXfila);
    free(pXpila);

    return 0;
}
