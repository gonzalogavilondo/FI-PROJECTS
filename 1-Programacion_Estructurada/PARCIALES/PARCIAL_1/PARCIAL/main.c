#include "header_imagen.h"

int main()
{
    uint32_t color_img[16] = {15549202, 4866494, 15210456, 2480723, 7585345, 1305803, 15923462, 12937018, 5483659, 659701, 10379638, 15908365, 5222557, 14731295, 5556534, 3598359};
    uint32_t components_color_img[16][4] = {{0}};
    uint32_t colors_count = 16;
    uint32_t componentes_color = 4;
    uint32_t color_gris_mat[16] = {0};
    obtener_matriz_componentes_color (color_img, colors_count, componentes_color, components_color_img);
    mostrar_matrices_color (components_color_img, colors_count, componentes_color);
    transformar_niveles_gris (components_color_img, color_gris_mat, colors_count);
    printf("\n\t\t\t MATRIZ NIVELES GRIS \n\n");
    mostrar_vector_como_matriz(color_gris_mat, colors_count, componentes_color);
    return 0;
}
