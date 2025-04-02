#ifndef BARCOS_H
#define BARCOS_H

#include <archivos.h>

typedef struct {
    Barco* tipos;
    int cantidad;
} Flota;

Flota* crear_flota(Barco* tipos_barcos, int num_tipos);
void liberar_flota(Flota* flota);

#endif
