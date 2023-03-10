#include "declaraciones.h"
/*
Los empleados de ventas de una empresa pesquera cargan los códigos de cada
transacción en diferentes archivos. Luego esos archivos son combinados y los códigos son
ordenados de forma ascendente por el sistema de acuerdo a la zona a la que pertenece cada
empleado. Se requiere tener el listado de códigos de la zona 1, la cual está compuesta por 3
empleados. Realizar un algoritmo que lea el archivo de cada empleado, combine la
información, ordene los códigos y guarde el listado final de códigos en un nuevo archivo cuyo
nombre referencie la zona.
Nota: Para el ordenamiento utilizar los métodos quick-sort y merge-sort.
*/

int main()
{
    char archivo_entrada1[] = "empleado1.txt"; //Nombre del archivo de entrada del primer empleado.
    char archivo_entrada2[] = "empleado2.txt"; //Nombre del archivo de entrada del segundo empleado.
    char archivo_entrada3[] = "empleado3.txt"; //Nombre del archivo de entrada del tercer empleado.
    char archivo_salida[] = "ventas_zona1.txt"; //Nombre del archivo de salida.
    int *entrada_1 = NULL;  //Donde voy a almacenar los datos del primer empleado.
    int *entrada_2 = NULL;  //Donde voy a almacenar los datos del segundo empleado.
    int *entrada_3 = NULL;  //Donde voy a almacenar los datos del tercer empleado.
    int *salida = NULL;     //Donde voy a almacenar los datos de toda la zona 1.
    int cnt_codigos1 = 0;   //Donde voy a almacenar la cantidad de codigos del primer empleado.
    int cnt_codigos2 = 0;   //Donde voy a almacenar la cantidad de codigos del segundo empleado.
    int cnt_codigos3 = 0;   //Donde voy a almacenar la cantidad de codigos del tercer empleado.
    int cnt_codigost = 0;   //Donde voy a almacenar la cantidad de codigos totales de la zona 1.

    //Declaracion del archivo de escritura, donde voy a escribir los datos que voy a levantar.
    FILE *fw;

    //Abro el archivo donde voy a escribir la informacion que voy a levantar.
    fw = fopen(archivo_salida, "w");
    verificar_apertura(fw);

    //Levanto lo que hay en cada archivo de entrada y voy reservando memoria mientras levanto.
    entrada_1 = recuperar_datos(archivo_entrada1, &cnt_codigos1);
    entrada_2 = recuperar_datos(archivo_entrada2, &cnt_codigos2);
    entrada_3 = recuperar_datos(archivo_entrada3, &cnt_codigos3);

    //Almaceno todos los vectores en un unico vector
    salida = combinar(entrada_1, entrada_2, entrada_3, &cnt_codigos1, &cnt_codigos2, &cnt_codigos3);

    //Sumamos la cantidad de codigos de los 3 empleados
    cnt_codigost = cnt_codigos1 + cnt_codigos2 + cnt_codigos3; //Sumamos la cantidad de codigos

    //Preguntar que metodo de ordenamiento desea usar con un mini menu
    menu(salida, cnt_codigost);

    //Imprimimos resultados
    grabar_datos(salida, cnt_codigost, fw);
    imprimir_datos(salida, cnt_codigost);

    //Cierro el archivo de escritura
    fclose(fw);

    //Libero memoria
    free(entrada_1);
    free(entrada_2);
    free(entrada_3);
    free(salida);


    return 0;
}
