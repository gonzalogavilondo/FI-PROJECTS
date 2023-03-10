#include "cabeceras.h"

int leer_datos(FILE* file, registro_t** datos)
{
    int cant_regs = 0;
    char c;
    fscanf(file, "%i", &cant_regs);
    *datos = (registro_t *)malloc(sizeof(registro_t) * cant_regs);
    fgetc(file);
    for (int i = 0; i < cant_regs; i++)
    {
        registro_t reg = (*(*datos + i));
        fscanf(file, "%d", &reg.hora.hh);
        c = fgetc(file);
        fscanf(file, "%d", &reg.hora.mm);
        c = fgetc(file);
        fscanf(file, "%f", &reg.valor);
        c = fgetc(file);
        (*(*datos + i)) = reg;
    }
    return cant_regs;
}

registro_t obtener_temp_minimax(registro_t* datos, int cant_regs, ptr_comp compare)
{
//    registro_t minimax;
//    qsort(datos, cant_regs, sizeof(registro_t), (void *)compare);
//    minimax = datos[0];
//    return minimax;
    registro_t reg_aux = datos[0];
    for (int i = 1; i < cant_regs; i++)
    {
        if (compare(datos[i],reg_aux))
        {
            reg_aux = datos[i];
        }
    }
    return reg_aux;
}
/*
int leer_temperatura(FILE* file, void* algo, int algo1)
{
    return 0;
}*/////QUE HACE ESTA FUNCION?

float obtener_temp_prom(registro_t* datos, int cant_regs)
{
    float sum_temps = 0.0;
    for (int i = 0; i < cant_regs; i++)
    {
        sum_temps += datos[i].valor;
    }
    return sum_temps/cant_regs;
}

void guardar(FILE* file, resumen_t resumen, const registro_t* registro, int cant_regs)
{
    fwrite(&cant_regs, sizeof(int), 1, file);
    fwrite(&resumen, sizeof(resumen_t), 1, file);
    for (int i = 0; i < cant_regs; i++)
    {
        fwrite((registro+i), sizeof(registro_t), 1, file);
    }
}

void mostrar_datos(resumen_t resumen, const registro_t* registro, int cant_regs)
{
    printf("Resumen diario: \n\n");
    printf("Tmax = %.2f \t hora = %02i:%02i\n", resumen.max.valor, resumen.max.hora.hh, resumen.max.hora.mm);
    printf("Tmin = %.2f \t hora = %02i:%02i\n", resumen.min.valor, resumen.min.hora.hh, resumen.min.hora.mm);
    printf("Tprom = %.2f\n\n", resumen.prom);
    printf("Tabla de valores registrados: \n\n");
    printf("Valor Temp. \t hora\n");
    printf("=====================\n");
    for (int i = 0; i < cant_regs; i++)
    {
        printf("%11.2f \t %02i:%02i\n", registro[i].valor, registro[i].hora.hh, registro[i].hora.mm);
    }
}

void verificar_salida(FILE* file, resumen_t* resumen, registro_t* datos, int cant_regs)
{
    fread(&cant_regs, sizeof(int), 1, file);
    datos = malloc(sizeof(registro_t) * cant_regs);
    fread(resumen, sizeof(resumen_t), 1, file);
    for (int i = 0; i < cant_regs; i++)
    {
        fread(&datos[i], sizeof(registro_t), 1, file);
    }
    printf("\n\n VERIFICACION \n\n");
    mostrar_datos(*resumen, datos, cant_regs);
    free(datos);
}
