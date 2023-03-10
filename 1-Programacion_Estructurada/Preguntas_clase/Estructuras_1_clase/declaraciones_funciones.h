#ifndef DECLARACIONES_FUNCIONES_H_INCLUDED
#define DECLARACIONES_FUNCIONES_H_INCLUDED

#define LONGMAX 25
typedef struct
{
    int nacimiento;
    char *nombre;
    float cantidad;
    char nacion;
}persona;

void imprimir_resultados(char *nombre, int nacimiento, float cantidad, char nacion, int identificador);


#endif // DECLARACIONES_FUNCIONES_H_INCLUDED
