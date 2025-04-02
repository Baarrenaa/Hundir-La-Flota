#include "tablero.h"

Tablero* crear_tablero(int n) {
    Tablero* tablero = malloc(sizeof(Tablero));
    tablero->n = n;
    tablero->casillas = calloc(n * n, sizeof(EstadoCasilla));
    return tablero;
}

void liberar_tablero(Tablero* tablero) {
    free(tablero->casillas);
    free(tablero);
}
