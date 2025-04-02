#include <stdio.h>
#include <stdlib.h>
#include "tablero.h"

// Función para crear un nuevo tablero
Tablero* crear_tablero(int tamano) {
    Tablero* tablero = NULL;
    int i, j;
    
    // Reservar memoria para la estructura del tablero
    tablero = (Tablero*)malloc(sizeof(Tablero));
    if (!tablero) {
        fprintf(stderr, "Error al reservar memoria para el tablero\n");
        return NULL;
    }
    
    // Inicializar tamaño y reservar matriz de casillas
    tablero->tamano = tamano;
    tablero->casillas = (char**)malloc(tamano * sizeof(char*));
    if (!tablero->casillas) {
        free(tablero);
        fprintf(stderr, "Error al reservar memoria para las casillas\n");
        return NULL;
    }
    
    // Reservar cada fila de la matriz
    for (i = 0; i < tamano; i++) {
        tablero->casillas[i] = (char*)malloc(tamano * sizeof(char));
        if (!tablero->casillas[i]) {
            // Liberar memoria previamente asignada en caso de error
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

// Función para inicializar todas las casillas del tablero como vacías
void inicializar_tablero(Tablero* tablero) {
    int i, j;
    for (i = 0; i < tablero->tamano; i++) {
        for (j = 0; j < tablero->tamano; j++) {
            tablero->casillas[i][j] = ' ';  // Casilla vacía
        }
    }
}

// Función para liberar toda la memoria utilizada por el tablero
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
