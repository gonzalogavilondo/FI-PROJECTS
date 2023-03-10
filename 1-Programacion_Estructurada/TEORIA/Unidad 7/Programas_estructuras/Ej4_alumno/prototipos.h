#ifndef PROTOTIPOS_H_INCLUDED
#define PROTOTIPOS_H_INCLUDED

struct fecha
{
    int dia;
    int mes;
    int anio;
};

struct telefono
{
    int pais;
    int ciudad;
    long numero;
};

struct contacto
{
    struct telefono tel;
    char correo[50];
};

struct colegio
{
    char nombre[20];
    struct fecha recibido;
    float promedio;
};

struct alumno
{
    char nombre[20];
    struct fecha fecha_nac;
    int  matricula;
    struct contacto info;
    struct colegio colegio;
};

#endif // PROTOTIPOS_H_INCLUDED
