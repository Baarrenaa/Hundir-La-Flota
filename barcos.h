#ifndef BARCOS_H
#define BARCOS_H

typedef struct {
    char nombre[21];
    char id;
    int tamano;
} Barco;

Barco* cargar_barcos(const char* filename);
void liberar_barcos(Barco* barcos);

#endif
