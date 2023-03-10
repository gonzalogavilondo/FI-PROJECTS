#include "cabeceras.h"

int leer_temperatura(FILE* f, void* d, int cant_regs)
{
    registro_t* datos = d;
    int i = 0;
    while (i < cant_regs)
    {
        fscanf(f,"%d:%d;%f%*c", &(datos[i].hora.hh), &(datos[i].hora.mm), &(datos[i].valor));
        i++;
    }
    // Retorna la cantidad de registros leidos.
    return i++;
}

registro_t obtener_temp_minimax(registro_t* datos, int cant_regs, ptr_comp func_comp)
{
    registro_t reg_aux = datos[0];
    for (int i = 1; i < cant_regs; i++)
    {
        if (func_comp(datos[i],reg_aux))
        {
            reg_aux = datos[i];
        }
    }
    return reg_aux;
}

float obtener_temp_prom(registro_t* datos, int cant_regs)
{
    float reg_prom = datos[0].valor;
    for (int i = 1; i < cant_regs; i++)
    {
        reg_prom += datos[i].valor;
    }
    return reg_prom / cant_regs;
}

int leer_datos(FILE* file, registro_t** datos)
{
    int cant_regs = 0;
    /*
    int file_size = 0;
    fseek(file, 0L, SEEK_END);
    file_size = ftell(file);
    fseek(file, 0L, SEEK_SET);
    */
    fscanf(file, "%d%*c", &cant_regs);
    *datos = (registro_t*)malloc(cant_regs * sizeof(registro_t));
    if (!*datos)
    {
        perror("No se puede asignar memoria");
        return 2;
    }

    leer_temperatura(file, *datos, cant_regs);

    return cant_regs;
}

void mostrar_datos(resumen_t res, const registro_t* datos, int cant_regs)
{
    printf("\nResumen diario:\n\n");
    printf("Tmax  = %.2f \t hora = %0.2d:%0.2d\n", res.max.valor, res.max.hora.hh, res.max.hora.mm);
    printf("Tmin  = %.2f \t hora = %0.2d:%0.2d\n", res.min.valor, res.min.hora.hh, res.min.hora.mm);
    printf("Tprom = %.2f \n\n", res.prom);
    printf("\nTabla de valores registrados:\n\n");
    printf("Valor Temp. \t hora \n");
    printf("===================== \n");
    for (int i = 0; i < cant_regs; i++)
    {
        printf("%11.2f \t%0.2d:%0.2d \n", datos[i].valor, datos[i].hora.hh, datos[i].hora.mm);
    }
}

void guardar(FILE* file, resumen_t res, const registro_t* datos, int cant_regs)
{
    fwrite(&cant_regs, sizeof(int), 1, file);
    fwrite(&res, sizeof(resumen_t), 1, file);
    fwrite(datos, sizeof(registro_t), cant_regs, file);
}

void verificar_salida(FILE* file)
{
    int cant_regs = 0;
    registro_t* datos = NULL;
    resumen_t res;

    fread(&cant_regs, sizeof(int), 1, file);
    datos = (registro_t*)malloc(cant_regs * sizeof(registro_t));
    if (!datos)
    {
        perror("No pudo asignar memoria");
        exit(4);
    }
    fread(&res, sizeof(resumen_t), 1, file);
    fread(datos, sizeof(registro_t), cant_regs, file);

    printf("\n\n VERIFICACION \n\n");
    mostrar_datos(res, datos, cant_regs);

    free(datos);
}
