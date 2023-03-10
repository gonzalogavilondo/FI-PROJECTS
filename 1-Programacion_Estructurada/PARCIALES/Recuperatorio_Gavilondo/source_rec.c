#include "header_rec.h"

void aplicar_mascara(uint32_t v1[], uint32_t v2[], const uint8_t mascara[FILAS][COLUMNAS]) //intercambian los bytes i-esimos de dos enteros de dos vectores, en la posicion i-ésima
{
    uint8_t elemento_v1[FILAS] = {0};
    uint8_t elemento_v2[FILAS] = {0};

    for (uint8_t i = 0; i < FILAS; i++)
    {
        entero_a_bytes(v1[i], elemento_v1);
        entero_a_bytes(v2[i], elemento_v2);
        for (uint8_t j = 0; j < COLUMNAS; j++)
        {
            if (mascara[i][j] == 1) //Recorro la mascara con la condicion de que si hay un "1", luego de pasar de entero a bytes, se ejecute la funcion "intercambiar_bytes" con esta misma condicion
            {
                intercambiar_bytes(&elemento_v1[j], &elemento_v2[j]);
            }
            bytes_a_entero(elemento_v1, &v1[i]);
            bytes_a_entero(elemento_v2, &v2[i]);

        }

    }
}

void entero_a_bytes(uint32_t vector, uint8_t elemento[]) //Descompone un entero en sus bytes (4) y lo guarda en un arreglo, en este caso el arreglo es elemento[], vector es el elemento de turno de los vectores 1 y 2 que se pasa a bytes.
{
    uint8_t mascara = 0xFF;
    for (int i = 3; i > -1; i--)  //Lo vamos a hacer de manera que queden ordenados al reves de como quedan en memoria.
    {
        elemento[3-i] = ((vector >> i*8) & mascara);
    }
}

void intercambiar_bytes(uint8_t *elemento_vectorA, uint8_t *elemento_vectorB) //Intercambian los bytes j-esimos de dos arreglos, en una posicion i-esima
{
    //Metodo de "la burbuja" para intercambiar valores, con la condicion dada anteriormente en la funcion "aplicar mascara" (que si hay un 1, se ejecuta el cambio, es decir esta funcion, si no la cumple, esta funcion, que es el intercambio no se ejecuta).

    uint8_t aux = 0;

    aux = *elemento_vectorB;
    *elemento_vectorB = *elemento_vectorA;
    *elemento_vectorA = aux;

}

void bytes_a_entero(uint8_t elemento[], uint32_t *entero) //Pasa los 4 bytes (los de cada arreglo, que son 5) en un entero.
{
    *entero = 0;
    for (int i = 0; i < BYTES; i++)
    {
        *entero += elemento[i] << ((BYTES-1-i)*8);//Son 4 bytes ya que hay 4 elementos de 8bits en el arreglo de un entero en este problema, pero como el conteo de la posicion de cada elemento del arreglo comienza desde 0, le resto 1 y lo multiplico por 8 (bits), para ir corriendo byte a byte.
    }
}

void mostrar_vector(uint32_t vector[], uint8_t numero_vector)
{
    printf("-VECTOR NUMERO %i- \n\n", numero_vector);
    printf("|   ");
    for (int i = 0; i < FILAS; i++)
    {
        printf("0x%08X   ", vector[i]);
    }
    printf("|\n\n");
}
