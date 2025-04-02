#ifndef TABLERO_H
#define TABLERO_H

typedef enum {
    VACIO,
    AGUA,
    TOCADO,
    HUNDIDO
} EstadoCasilla;

typedef struct {
    int n;
    EstadoCasilla* casillas;
    Barco* barcos;
} Tablero;

Tablero* crear_tablero(int n);
void liberar_tablero(Tablero* tablero);

#endif
