#ifndef PROTOTIPO_H_INCLUDED
#define PROTOTIPO_H_INCLUDED

struct punto
{
    int coorx;
    int coory;
};

typedef struct
{
    int color_linea;
    int color_fondo;
    struct punto verticeA;
    struct punto verticeB;
    struct punto verticeC;
    char  tipo[20];
} triangulo;

#endif // PROTOTIPO_H_INCLUDED
