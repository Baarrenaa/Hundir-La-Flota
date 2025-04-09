#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "disparos.h"
#include "tablero.h"

int realizar_disparo(Tablero* tablero_flota, Tablero* tablero_oponente, 
                     int fila, int columna, char tipo_disparo) {
    int resultado = 0;  // 0: Agua, 1: Tocado, 2: Hundido
    
    if (!es_posicion_valida(fila, columna, tablero_flota->tamano)) {
        return -1;
    }
  
    switch(tipo_disparo) {
        case 'A':  // Disparo Automático
            resultado = disparo_automático(tablero_flota, fila, columna);
            break;
            
        case 'M':  // Disparo Manual
            resultado = disparo_manual(tablero_flota, fila, columna);
            break;
            
        default:
            return -1;
    }
    
    actualizar_tablero_oponente(tablero_oponente, fila, columna, resultado);
    
    return resultado;
}

int disparo_automático(Tablero* tablero, int fila, int columna) {
    char estado_casilla = tablero->casillas[fila][columna];
    
    if (estado_casilla == ' ') {  // Casilla vacía
        return 0;  // Agua
    } else if (estado_casilla != '*' && estado_casilla != 'T' && 
               estado_casilla != 'H') {
        return 1;  // Tocado
    }
    
    return 0;  // Casilla ya disparada
}

int disparo_manual(Tablero* tablero, int fila, int columna) {
    char estado_casilla = tablero->casillas[fila][columna];
    
    if (estado_casilla == ' ') {  // Casilla vacía
        return 0;  // Agua
    } else if (estado_casilla != '*' && estado_casilla != 'T' && 
               estado_casilla != 'H') {
        return 1;  // Tocado
    }
    
    return 0;  // Casilla ya disparada
}

void actualizar_tablero_oponente(Tablero* tablero, int fila, int columna, 
                               int resultado) {
    switch(resultado) {
        case 0:  // Agua
            tablero->casillas[fila][columna] = '*';
            break;
            
        case 1:  // Tocado
            tablero->casillas[fila][columna] = 'T';
            break;
            
        case 2:  // Hundido
            tablero->casillas[fila][columna] = 'H';
            marcar_barco_hundido(tablero, fila, columna);
            break;
    }
}

void marcar_barco_hundido(Tablero* tablero, int fila, int columna) {
    const int direcciones[][2] = {{-1,-1}, {-1,0}, {-1,1},
                                 {0,-1},          {0,1},
                                 {1,-1},  {1,0},  {1,1}};
    int i;
    
    for (i = 0; i < 8; i++) {
        int nueva_fila = fila + direcciones[i][0];
        int nueva_col = columna + direcciones[i][1];
        
        if (es_posicion_valida(nueva_fila, nueva_col, tablero->tamano)) {
            if (tablero->casillas[nueva_fila][nueva_col] == ' ') {
                tablero->casillas[nueva_fila][nueva_col] = '*';
            }
        }
    }
}
