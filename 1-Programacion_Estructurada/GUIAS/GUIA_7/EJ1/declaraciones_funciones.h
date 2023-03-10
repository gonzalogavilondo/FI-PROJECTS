#ifndef DECLARACIONES_FUNCIONES_H_INCLUDED
#define DECLARACIONES_FUNCIONES_H_INCLUDED

#define SIZE 100
/* Información sobre la celda */
struct informacion_celda
{
    char nombre[SIZE]; /* Nombre de la celda */
    unsigned int identificador; /* Número identificador */
    int calidad_senal; /* Calidad de la señal (entre 0 y 100) */
    struct informacion_operador *ptr_operador; /* Puntero a una segunda estructura */
};
/* Información sobre el operador */
struct informacion_operador
{
    char nombre[SIZE]; /* Cadena de texto con el nombre */
    unsigned int prioridad; /* Prioridad de conexión */
    unsigned int ultima_comprob; /* Fecha de la última comprobación */
};


#endif // DECLARACIONES_FUNCIONES_H_INCLUDED
