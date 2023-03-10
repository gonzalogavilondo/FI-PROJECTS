#include "header_imagen.h"

void obtener_matriz_componentes_color (const uint32_t color_img[], uint32_t colors_count, uint32_t componentes_color, uint32_t components_color_img[][4])
{
    for (uint32_t k = 0; k < colors_count; k++)
    {
        uint32_t comp_color[4] = {0};
        uint32_t components_color_count = 4;
        uint32_t color = 0;
        color = color_img[k];
        get_bytes_by_colores(color, comp_color);
        for (uint32_t c = 0; c < components_color_count; c++)
        {
            components_color_img[k][c] = comp_color[c];
        }
    }
}

void get_bytes_by_colores (uint32_t color, uint32_t comp_color[])
{
    uint8_t mask = 0xFF;
    for (int i = 3; i > -1; i--)
    {
        comp_color[3-i] = (color >> i*8) & mask;
    }
}

void mostrar_vector_como_matriz(const uint32_t arr[], uint32_t colors_count, uint32_t componentes_color)
{
    uint8_t filas = colors_count/componentes_color;
    for(int i = 0; i < filas; i++)
    {
        printf("|");
        for(int j = 0; j < componentes_color; j++)
        {
            int k = componentes_color*i+j;
            printf("%02X\t", arr[k]);

        }
        printf("\b\b\b\b\b\b|\n");
   }
}

void completar_vector_color (const uint32_t components_color_img[][4], uint32_t colors_count, uint32_t componentes_color, uint32_t arr[])
{
    for (int i = 0; i < colors_count; i++)
    {
        arr[i] = components_color_img[i][componentes_color];
    }
}

void mostrar_matrices_color (const uint32_t components_color_img[][4], uint32_t colors_count, uint32_t componentes_color)
{
    uint32_t arr[16] = {0};
    printf("\n\t\t\t MATRIZ DE COLOR ROJO \n\n");
    completar_vector_color(components_color_img, colors_count, 1, arr);
    mostrar_vector_como_matriz(arr, colors_count, componentes_color);
    printf("\n\t\t\t MATRIZ DE COLOR VERDE \n\n");
    completar_vector_color(components_color_img, colors_count, 2, arr);
    mostrar_vector_como_matriz(arr, colors_count, componentes_color);
    printf("\n\t\t\t MATRIZ DE COLOR AZUL \n\n");
    completar_vector_color(components_color_img, colors_count, 3, arr);
    mostrar_vector_como_matriz(arr, colors_count, componentes_color);
}

void transformar_niveles_gris (uint32_t components_color_img[][4], uint32_t color_gris_mat[], uint32_t colors_count)
{
    for (int i = 0; i < colors_count; i++)
    {
        color_gris_mat[i] = (uint8_t)round(0.3*components_color_img[i][1]+0.59*components_color_img[i][2]+0.11*components_color_img[i][3]);
    }
}


