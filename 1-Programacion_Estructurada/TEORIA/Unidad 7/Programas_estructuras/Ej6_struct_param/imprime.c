#include "header.h"

void imprime_datos(datos_alumno alumnos[], int dimension)
{
    int lazo;
    for(int cnt=0; cnt<dimension; cnt++)
    {
        printf("Alumno (%d): %s; ", cnt, alumnos[cnt].nombre);
        printf("Matricula No = %d\n", alumnos[cnt].matricula);
        lazo = 0;
        do
        {
            printf("\n\tMateria: %s", alumnos[cnt].materia[lazo].nombre);
            printf("\n\tAprobada: %d/%d/%d", alumnos[cnt].materia[lazo].aprobado.dia,
                                               alumnos[cnt].materia[lazo].aprobado.mes,
                                               alumnos[cnt].materia[lazo].aprobado.anio);
            printf("\n\tPromedio: %4.2f", alumnos[cnt].materia[lazo].promedio);
            printf("\n");
            lazo++;
        }while((int)alumnos[cnt].materia[lazo].promedio);
        printf("\n\n");
    }
}

void ingresa_datos(datos_alumno alumnos[], int indice)
{
    strcpy(alumnos[indice].nombre,"Pepe Grillo");
    alumnos[indice].matricula = 10528;                     // acceso a un campo en particular

    strcpy(alumnos[indice].materia[0].nombre, "Algebra B");       // materia[0]
    alumnos[indice].materia[0].aprobado.dia = 15;
    alumnos[indice].materia[0].aprobado.mes = 7;
    alumnos[indice].materia[0].aprobado.anio = 2014;
    alumnos[indice].materia[0].promedio = 9.2;

    strcpy(alumnos[indice].materia[1].nombre, "Fisica B");        // materia[1]
    alumnos[indice].materia[1].aprobado.dia = 10;
    alumnos[indice].materia[1].aprobado.mes = 8;
    alumnos[indice].materia[1].aprobado.anio = 2014;
    alumnos[indice].materia[1].promedio = 8.5;
}
