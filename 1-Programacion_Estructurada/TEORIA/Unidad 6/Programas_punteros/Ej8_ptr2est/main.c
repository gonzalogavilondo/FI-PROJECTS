#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct
{
    int iNumero;
    float fNumero;
    char cCar[20];
} myStruc;

struct estructura
{
    int iNumero;
    float fNumero;
    char cCar[20];
};

void presenta_datos_valor(struct estructura);
struct estructura presenta_datos_retorno(struct estructura);
void presenta_datos_ref(myStruc *);

int main()
{
    struct estructura st;     // variable de struct estructura
    myStruc *pst;             // puntero al tipo de dato mySt

    printf("Tamaño de st = %d\tTamaño de *pst = %d",   // Tamaño de la estructura
           sizeof(struct estructura), sizeof(myStruc));

    st.iNumero = 17;                       // acceso a los campos
    st.fNumero = 23.45;                    // mediante el operador '.'
    strcpy(st.cCar,"Prueba de variable");
    presenta_datos_valor(st);              // invoco la función y trato de cambiar un valor
    printf("\nValor de st.iNumero modificado? = %d", st.iNumero);

    st = presenta_datos_retorno(st);       // invoco la función y trato de cambiar un valor
    printf("\nValor de st.iNumero modificado? = %d", st.iNumero);

    pst = (myStruc *)&st;                  // inicializo puntero con la dirección de la estructura
    pst->iNumero = 33;                     // modifico los datos originales de la
    pst->fNumero = 19.59;                  // variable a través del puntero
    pst->cCar[4] = 0x0;                    // acorto el mensaje
    presenta_datos_ref(pst);
    presenta_datos_ref((myStruc *)&st);

    pst = (myStruc *)malloc(sizeof(myStruc));     // apunto a otro bloque de memoria

    pst->iNumero = 0xFF;                   // operador flecha usado con puntero
    (*pst).fNumero = 2.4e5;                // operador punto usado con puntero
    strcpy((*pst).cCar,"Prueba de puntero");
    presenta_datos_ref(pst);

    puts("\n\n");
    free(pst);

    return 0;
}

void presenta_datos_valor(struct estructura valores)
{
    printf("\n\nEntero = %d, flotante = %7.3f, string = %s",
           valores.iNumero, valores.fNumero, valores.cCar);
    (&valores)->iNumero = 45;                 // <-- porque no se modifica el valor si uso un puntero?
}

struct estructura presenta_datos_retorno(struct estructura valores)
{
    printf("\n\nEntero = %d, flotante = %7.3f, string = %s",
           valores.iNumero, valores.fNumero, valores.cCar);
    valores.iNumero = 45;

    return valores;
}

void presenta_datos_ref(myStruc *valores)
{
    printf("\n\nEntero = %d, flotante = %7.3f, string = %s",
           valores->iNumero, valores->fNumero, (*valores).cCar);
}
