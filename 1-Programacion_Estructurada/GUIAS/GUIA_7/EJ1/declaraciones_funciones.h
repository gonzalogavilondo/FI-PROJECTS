#ifndef DECLARACIONES_FUNCIONES_H_INCLUDED
#define DECLARACIONES_FUNCIONES_H_INCLUDED

#define SIZE 100
/* Informaci�n sobre la celda */
struct informacion_celda
{
    char nombre[SIZE]; /* Nombre de la celda */
    unsigned int identificador; /* N�mero identificador */
    int calidad_senal; /* Calidad de la se�al (entre 0 y 100) */
    struct informacion_operador *ptr_operador; /* Puntero a una segunda estructura */
};
/* Informaci�n sobre el operador */
struct informacion_operador
{
    char nombre[SIZE]; /* Cadena de texto con el nombre */
    unsigned int prioridad; /* Prioridad de conexi�n */
    unsigned int ultima_comprob; /* Fecha de la �ltima comprobaci�n */
};


#endif // DECLARACIONES_FUNCIONES_H_INCLUDED
