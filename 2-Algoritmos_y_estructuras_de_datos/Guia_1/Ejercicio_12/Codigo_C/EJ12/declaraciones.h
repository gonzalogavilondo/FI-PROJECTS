#define CANTIDAD 5
#define LONGMAX 20

typedef struct
{
    int numero;
    int planta;

}vivienda;

typedef struct
{
    char nombre_calle[LONGMAX];
    vivienda casa;

}datos_calle;


void ingreso_datos(datos_calle calles[CANTIDAD]);
void impresion_datos(const datos_calle calles[CANTIDAD]);
