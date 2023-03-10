#include "listas.h"
/*
En la facultad de ingenier�a se quiere obtener un listado ordenado, seg�n matr�cula, del
n�mero de alumnos que est�n cursando los �ltimos a�os de las carreras. Para ello, se
registra uno a uno la matr�cula y el porcentaje de materias aprobadas de cada alumno. Se
considera que aquel alumno que tiene aprobado m�s del 80% de la carrera est� cursando
las �ltimas materias. Escribir un programa que permita obtener el listado mencionado.
*/
int main()
{
    int cnt_alumnos;
    CARRERA informacion;

    //Insertamos 4  alumnos
    for(int i = 1; i < 5; i++)
    {
        insert(i);
    }

    //Ordenamos los alumnos por matricula
    sort();

    //Funcion que determine quien cursa los ultimos a�os
    ultimas_materias();

    //Obtenemos la cantidad de alumnos que estan por terminar la carrera
    cnt_alumnos = length();

    //Extraemos la informacion e imprimimos los datos.
    printf("-DATOS DE LOS ALUMNOS POR FINALIZAR LA CARRERA-\n");
    for(int i = 1; i <= cnt_alumnos; i++)
    {
        informacion = get(i); //Tomamos los datos de la posicion "i" sin eliminarlos.
        traverse(informacion); //Imprimimos los datos.
    }

    //Liberamos memoria
    liberar_memoria();

    return 0;
}
