#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "header.h"
/***  datos_alumno:                   catedras:                   fecha:
          char nombre[20];                char nombre[20];            int dia;
          int matricula;                  fecha aprobado;             int mes;
          catedras materia[30];           float promedio;             int anio;   ***/

int main()
{
    datos_alumno alumnos[3] = { {"Jose Perez", 1000, { {"Algebra A", {30, 11, 2014}, 6.25},
                                                       {"Matematica B", {15, 07, 2014}, 8.02},
                                                       {"Fisica A", {1, 03, 2015}, 4.50} } },    // alumno 0
                                {"Anibal Fernandez", 100, { {"Algebra A", {30, 07, 2005}, 4.25},
                                                     {"Dibujo", {15, 07, 2010}, 6.02},
                                                     /*{"Fisica A", {1, 03, 2014}, 4.50}*/ } }   // alumno 1
                                 };    // fin de ingreso de datos


    strcpy(alumnos[2].nombre,"Pepe Grillo");
    alumnos[2].matricula = 10528;                     // acceso a un campo en particular

    strcpy(alumnos[2].materia[0].nombre, "Algebra B");       // materia[0]
    alumnos[2].materia[0].aprobado.dia = 15;
    alumnos[2].materia[0].aprobado.mes = 7;
    alumnos[2].materia[0].aprobado.anio = 2014;
    alumnos[2].materia[0].promedio = 9.2;

    strcpy(alumnos[2].materia[1].nombre, "Fisica B");        // materia[1]
    alumnos[2].materia[1].aprobado.dia = 10;
    alumnos[2].materia[1].aprobado.mes = 8;
    alumnos[2].materia[1].aprobado.anio = 2014;
    alumnos[2].materia[1].promedio = 8.5;

    printf("Nombre materia = ");
    scanf("%[^\n]",alumnos[2].materia[2].nombre);
    printf("Anio de aprobacion = ");
    scanf("%d",&alumnos[2].materia[2].aprobado.anio);
    printf("Promedio = ");
    scanf("%f",&alumnos[2].materia[2].promedio);
    printf("\n\n");

    /****  imprimo el listado ****/
    int lazo;
    for(int cnt=0; cnt<3; cnt++)
    {
        printf("Alumno (%d): %s; ", cnt+1, alumnos[cnt].nombre);
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
    return 0;
}



