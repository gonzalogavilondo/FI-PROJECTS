#include <stdio.h>

void a_local(void);  /* declaración de la función a_local */
void b_static(void); /* declaración de la función b_static */
void c_global(void); /* declaración de la función c_global */

int x_global_local = 1; /* declara la variable x_global_local y le asigna el valor 1 */

int main(void)
{
    int x_global_local = 5; /* cambia el valor de x_global_local a 5 */
    printf("La variable x_global_local dentro de main es: %d.\n", x_global_local); /* imprime el valor de x_global_local*/

    {
        int x_global_local = 7;
        printf("La variable x_global_local en el subbloque de main es: %d.\n", x_global_local); /* cambia el valor de x_global_local a 7 y lo imprime */
    }

    printf("La variable x_global_local en main es: %d.\n", x_global_local); /* imprime x_global_local pero vuelve a tener el valor 5 */
    a_local();
    b_static(); /* Llamada a las funciones a_local, b_static y c_global por primera vez */
    c_global();
    printf("\n\n*****Resultados luego de invocar por segunda vez a las funciones a, b y c*****\n");
    a_local();  /* x_global_local al entrar vale 25 y al salir 26*/
    b_static(); /* x_global_local al entrar vale 51 y al salir 52 por ser static adentro de esta funcion*/
    c_global(); /* x_global_local al entrar vale 10 y al salir 100 porque la funcion es global*/
    printf("\nLa variable x_global_local en main es: %d.\n", x_global_local);/* imprime x_global_local = 5 */
    return 0;
}

/* definición de la función a_local */
void a_local(void)
{
    int x_global_local = 25; /* Asigna el valor 25 a x_global_local */
    printf("\nLa variable x_global_local luego de entrar en a_local es: %d.\n", x_global_local); /* imprime x_global_local = 25 */
    x_global_local++; /* Le suma 1 a x_global_local y termina valiendo 26 */
    printf("La variable x_global_local antes de salir de a_local es: %d.\n", x_global_local); /* imprime x_global_local = 26 */
}

/* definición de la función b_static */
void b_static(void)
{
    static int x_global_local = 50; /* Asigna el valor 25 a x_global_local */
    printf("\nLa variable x_global_local al entrar en b_static es: %d.\n", x_global_local); /* imprime x_global_local = 50 */
    x_global_local++; /* Le suma 1 a x_global_local y termina valiendo 51 */
    printf("La variable x_global_local antes de salir de b_static es: %d.\n", x_global_local); /* imprime x_global_local = 51 */
}

/* definición de la función c_global */
void c_global(void)
{
    printf("\nLa variable x_global_local en c_global es: %d.\n", x_global_local); /* imprime x_global_local = 1 */
    x_global_local *= 10; /* Multiplica x_global_local por 10 */
    printf("La variable x_global_local antes de salir de c_global es: %d.\n", x_global_local); /* imprime x_global_local = 10 */
}
