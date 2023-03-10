#include "cabeceras.h"

bool_t reg_menor(registro_t a, registro_t b)
{
    return (a.valor < b.valor)? VERDADERO: FALSO;
}

bool_t reg_mayor(registro_t a, registro_t b)
{
    return (a.valor > b.valor)? VERDADERO: FALSO;
}

int main(int argc, char* argv[])
{
    system("color 9e");
    registro_t* datos = NULL;
    int cant_regs = 0;
    resumen_t resumen;

    FILE* file;
    file = fopen(argv[1], "r");
    if (!file)
    {
        perror("No se puede abrir el registro de temperaturas");
        return 1;
    }
    // Encapsular en una función de lectura
    cant_regs = leer_datos(file, &datos);
    fclose(file);

    // Procesar datos para calcular valores máximo, mínimo, promedio.
    resumen.min = obtener_temp_minimax(datos, cant_regs, reg_menor);
    resumen.max = obtener_temp_minimax(datos, cant_regs, reg_mayor);
    resumen.prom = obtener_temp_prom(datos, cant_regs);

    // Guardar los datos estructurados en un archivo binario, de forma que otro programa
    // pueda leerlos conociendo dicha estructura.
    file = fopen(argv[2], "wb");
    if (!file)
    {
        perror("No se puede abrir el archivo de salida");
        return 2;
    }

    guardar(file, resumen, datos, cant_regs);

    fclose(file);

    // Mostrar en pantalla la siguiente información:
    // Resumen diario:
    // temp max   h
    // temp min   h
    // temp prom
    // A continuación la tabla de datos
    mostrar_datos(resumen, datos, cant_regs);
    free(datos);
    datos = NULL;

    // Verificación: Leer el binario grabado en ejercicio 1, cargar datos en memoria
    //               (resumen, datos, cant_regs)y volver a invocar a mostrar_datos

    file = fopen(argv[2], "rb");
    if (!file)
    {
        perror("No se puede abrir el archivo de salida");
        return 3;
    }

    verificar_salida(file, &resumen, datos, cant_regs);

    fclose(file);

    return 0;
}
