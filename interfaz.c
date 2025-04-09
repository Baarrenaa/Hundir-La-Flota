#include <stdio.h>
#include <stdlib.h>
#include "interfaz.h"
#include "tablero.h"

void mostrar_menu_principal() {
    printf("\n=== HUNDIR LA FLOTA ===\n");
    printf("1. Configuración\n");
    printf("2. Jugar Partida\n");
    printf("3. Salir\n");
    printf("==================\n");
}

void mostrar_menu_configuracion() {
    printf("\n=== CONFIGURACIÓN ===\n");
    printf("1. Introducir datos\n");
    printf("2. Mostrar\n");
    printf("3. Borrar\n");
    printf("4. Guardar\n");
    printf("5. Cargar\n");
    printf("6. Volver\n");
    printf("=================\n");
}

void mostrar_tableros(Tablero* flota, Tablero* oponente) {
    int i, j;
    
    printf("\n=== TABLERO DE FLOTA ===\n");
    printf("  ");
    for (j = 0; j < flota->tamano; j++) {
        printf("%d ", j);
    }
    printf("\n");
    
    for (i = 0; i < flota->tamano; i++) {
        printf("%d ", i);
        for (j = 0; j < flota->tamano; j++) {
            printf("%c ", flota->casillas[i][j]);
        }
        printf("\n");
    }
    
    printf("\n=== TABLERO OPONENTE ===\n");
    printf("  ");
    for (j = 0; j < oponente->tamano; j++) {
        printf("%d ", j);
    }
    printf("\n");
    
    for (i = 0; i < oponente->tamano; i++) {
        printf("%d ", i);
        for (j = 0; j < oponente->tamano; j++) {
            printf("%c ", oponente->casillas[i][j]);
        }
        printf("\n");
    }
}
