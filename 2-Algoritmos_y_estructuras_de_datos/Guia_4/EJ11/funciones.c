#include "listas.h"

NODO *cargar_alumno(int pos)
{

    //Le asignamos a nuevo todos los datos
    if(pos == 1)
    {
        //Declaracion de variables
        NODO *alumno1 = LISTA;
        char aux[LONGMAX] = "Juan";

        //Reservo memoria
        alumno1 = (NODO*)malloc(sizeof(NODO));

        //Completo la informacion
        strcpy(alumno1->alumno.nombre, aux);
        alumno1->alumno.matricula = 120341;
        alumno1->alumno.porcentaje_materias_ap = 85;

        return alumno1;
    }
    else if(pos == 2)
    {
        //Declaramos las variables
        NODO *alumno2 = LISTA;
        char aux[LONGMAX] = "Gonzalo";

        //Reservo memoria
        alumno2 = (NODO*)malloc(sizeof(NODO));

        //Completo la informacion
        strcpy(alumno2->alumno.nombre, aux);
        alumno2->alumno.matricula = 120339;
        alumno2->alumno.porcentaje_materias_ap = 25;

        return alumno2;
    }
    else if(pos == 3)
    {
        //Declaramos las variables
        NODO *alumno3 = LISTA;
        char aux[LONGMAX] = "Martin";

        //Reservo memoria
        alumno3 = (NODO*)malloc(sizeof(NODO));

        //Completo la informacion
        strcpy(alumno3->alumno.nombre, aux);
        alumno3->alumno.matricula = 120420;
        alumno3->alumno.porcentaje_materias_ap = 95;

      return alumno3;
    }
    else
    {
        //Declaramos las variables
        NODO *alumno4 = LISTA;
        char aux[LONGMAX] = "Carlos";

        //Reservo memoria
        alumno4 = (NODO*)malloc(sizeof(NODO));

        //Completo la informacion
        strcpy(alumno4->alumno.nombre, aux);
        alumno4->alumno.matricula = 120400;
        alumno4->alumno.porcentaje_materias_ap = 80;

       return alumno4;
    }
}

void ultimas_materias()
{
    int pos = 1;
    NODO *pS = LISTA;
    while(pS != NULL)
    {
        if(pS->alumno.porcentaje_materias_ap < 80)
        {
            deletee(pos);
        }
        pS = pS->next; //Avanzamos
        pos++;
    }

}

