#ifndef DECLARACIONES_H_INCLUDED
#define DECLARACIONES_H_INCLUDED
#define MAXCLIENTES 100
#define LONGMAX 20

typedef struct
{
    char nombre[LONGMAX];
    char apellidos[LONGMAX];
    char mail[LONGMAX];
    int telefono;

}datos_personales;

int ingreso_datos(datos_personales clientes[MAXCLIENTES]);
void impresion_datos(const datos_personales clientes[MAXCLIENTES], int contador);


#endif // DECLARACIONES_H_INCLUDED
