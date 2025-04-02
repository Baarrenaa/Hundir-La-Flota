#include <stdio.h>
#include <stdlib.h>
#include "tablero.h"

Tablero* crear_tablero(int tamano) {
    Tablero* tablero = NULL;
    int i, j;
    
    tablero = (Tablero*)malloc(sizeof(Tablero));
    if (!tablero) {
        fprintf(stderr, "Error al reservar memoria para el tablero\n");
        return NULL;
    }
    
    tablero->tamano = tamano;
    tablero->casillas = (char**)malloc(tamano * sizeof(char*));
    if (!tablero->casillas) {
        free(tablero);
        fprintf(stderr, "Error al reservar memoria para las casillas\n");
        return NULL;
    }
    
 
    for (i = 0; i < tamano; i++) {
        tablero->casillas[i] = (char*)malloc(tamano * sizeof(char));
        if (!tablero->casillas[i]) {
            for (j = 0; j < i; j++) {
                free(tablero->casillas[j]);
            }
            free(tablero->casillas);
            free(tablero);
            fprintf(stderr, "Error al reservar memoria para las filas\n");
            return NULL;
        }
    }
    
    return tablero;
}

void inicializar_tablero(Tablero* tablero) {
    int i, j;
    for (i = 0; i < tablero->tamano; i++) {
        for (j = 0; j < tablero->tamano; j++) {
            tablero->casillas[i][j] = ' ';  // Casilla vacía
        }
    }
}

void liberar_tablero(Tablero* tablero) {
    int i;
    if (tablero != NULL) {
        if (tablero->casillas != NULL) {
            for (i = 0; i < tablero->tamano; i++) {
                if (tablero->casillas[i] != NULL) {
                    free(tablero->casillas[i]);
                }
            }
            free(tablero->casillas);
        }
        free(tablero);
    }
}
