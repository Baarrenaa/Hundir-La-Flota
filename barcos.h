#ifndef BARCOS_H
#define BARCOS_H

typedef struct {
    char nombre[21];
    char id;
    int tamano;
    int cantidad;
} Barco;

Barco* cargar_barcos(const char* archivo);
void liberar_barcos(Barco* barcos, int num_barcos);

#endif
