#include "header_ejs_structs.h"

int main()
{
    entero_t var = {1};
    printf("UNION ANTES DE LLAMAR A LA FUNCION ALTERAR VALOR.\n\n");
    imprimir_campo(&var);
    alterar_valor(&var);
    printf("UNION DESPUES DE LLAMAR A LA FUNCION ALTERAR VALOR.\n\n");
    imprimir_campo(&var);
    return 0;
}
