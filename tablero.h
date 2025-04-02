#ifndef TABLERO_H
#define TABLERO_H

typedef struct {
    int tamano;
    char** casillas;
} Tablero;

Tablero* crear_tablero(int tamano);
void inicializar_tablero(Tablero* tablero);
void liberar_tablero(Tablero* tablero);

#endif
