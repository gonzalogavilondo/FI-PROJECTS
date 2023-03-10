#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include "header_opsMatrices.h"

#include "../menu_generico/menu.h"

#define MENU_OPERACION_SUMA 1
#define MENU_OPERACION_RESTA 2
#define MENU_OPERACION_MULTIPLICACION 3
#define MENU_OPERACION_DIVISION 4
#define MENU_OPERACION_TRASPUESTA 5

unsigned int menu_cant_elems = 6;

const char menu_textos[][MENU_LARGO_TEXTO] = {
"Suma",
"Resta",
"Multiplicación",
"División por escalar",
"Transpuesta",
"Salir"
};

const char menu_opciones[] = {
's',
'r',
'm',
'd',
't',
'q'
};

const int menu_operaciones[] = {
MENU_OPERACION_SUMA,
MENU_OPERACION_RESTA,
MENU_OPERACION_MULTIPLICACION,
MENU_OPERACION_DIVISION,
MENU_OPERACION_TRASPUESTA,
MENU_OPERACION_FIN
};

int main()
{
    setlocale(LC_ALL, "spanish");
    int op;
    int fil = 3, col = 3;
    while((op = menu_operacion()) != MENU_OPERACION_FIN)
    {
        float A[3][3] = {{0.0}};
        float B[3][3] = {{0.0}};
        float C[3][3] = {{0.0}};
        system("cls || clean");
        if (op < 4)
        {
            completar_matriz(fil, col, A, 'A');
            completar_matriz(fil, col, B, 'B');
        }
        else
        {
            completar_matriz(fil, col, A, 'A');
        }
        switch (op)
        {
        case 1:
            suma_matriz (fil, col, (const float(*)[col])A, (const float(*)[col])B, C);
            break;
        case 2:
            resta_matriz (fil, col, (const float(*)[col])A, (const float(*)[col])B, C);
            break;
        case 3:
            mult_matriz (fil, col, (const float(*)[col])A, (const float(*)[col])B, C);
            break;
        case 4:
            div_escalar(fil, col, (const float(*)[col])A, C);
            break;
        case 5:
            transpuesta_matriz(fil, col, (const float(*)[col])A, C);
            break;
        }
        if (op < 4)
        {
            printf("La matriz A es:\n");
            mostrar_matriz(fil, col, (const float(*)[col])A);
            printf("La matriz B es:\n");
            mostrar_matriz(fil, col, (const float(*)[col])B);
        }
        else
        {
            printf("La matriz A es:\n");
            mostrar_matriz(fil, col, (const float(*)[col])A);
        }
        printf("La matriz resultante es:\n");
        mostrar_matriz(fil, col, (const float(*)[col])C);
        fflush(stdin);
        printf("Presione cualquier tecla para continuar: ");
        getchar();
    }
    return 0;
}
