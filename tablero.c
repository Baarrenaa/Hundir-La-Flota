#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int **casillas;
    int tamano;
} Tablero;

Tablero* crear_tablero(int tamano) {
    Tablero *tab = malloc(sizeof(Tablero));
    if (!tab) return NULL;

    tab->tamano = tamano;
    tab->casillas = malloc(tamano * sizeof(int *));

    if (!tab->casillas) {
        free(tab);
        return NULL;
    }

    for(int i = 0; i < tamano; i++) {
        tab->casillas[i] = malloc(tamano * sizeof(int));
        if (!tab->casillas[i]) {
            for(int j = 0; j < i; j++) {
                free(tab->casillas[j]);
            }
            free(tab->casillas);
            free(tab);
            return NULL;
        }

        for(int j = 0; j < tamano; j++) {
            tab->casillas[i][j] = 0;
        }
    }

    return tab;
}

void mostrar_tablero(Tablero* tab) {
    printf("   ");

    for(int i = 0; i < tab->tamano; i++) {
        printf("%d ", i);
    }
    printf("\n");

    for(int i = 0; i < tab->tamano; i++) {
        printf("%d  ", i);
        for(int j = 0; j < tab->tamano; j++) {
            printf("%d ", tab->casillas[i][j]);
        }
        printf("\n");
    }
}
    int tamano = 5;
