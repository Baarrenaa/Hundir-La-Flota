#ifndef ARCHIVOS_H
#define ARCHIVOS_H

#include <stdio.h>
#include <stdlib.h>

typedef struct {
    char nombre[21];
    char id;
    int tamano;
} Barco;

Barco* cargar_barcos(const char* filename);
void liberar_barcos(Barco* barcos);

#endif
