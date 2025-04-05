#include <stdio.h>
#include <stdlib.h>
#include "validaciones.h"
#include "tablero.h"

int es_posicion_valida(int fila, int columna, int tamano_tablero) {
    return (fila >= 0 && fila < tamano_tablero && 
            columna >= 0 && columna < tamano_tablero);
}

int es_colocacion_barco_valida(Tablero* tablero, int fila, int columna, 
                              int tamano, int orientacion) {
    int i;
    
    if (!es_posicion_valida(fila, columna, tablero->tamano)) {
        return 0;
    }
    
    if (orientacion == HORIZONTAL && 
        !es_posicion_valida(fila, columna + tamano - 1, tablero->tamano)) {
        return 0;
    }
    if (orientacion == VERTICAL && 
        !es_posicion_valida(fila + tamano - 1, columna, tablero->tamano)) {
        return 0;
    }
    if (orientacion == DIAGONAL_DER && 
        !es_posicion_valida(fila + tamano - 1, columna + tamano - 1, tablero->tamano)) {
        return 0;
    }
    if (orientacion == DIAGONAL_IZQ && 
        !es_posicion_valida(fila + tamano - 1, columna - tamano + 1, tablero->tamano)) {
        return 0;
    }
    
    switch(orientacion) {
        case HORIZONTAL:
            for(i = 0; i < tamano; i++) {
                if (!casillas_validas(tablero, fila, columna + i)) {
                    return 0;
                }
            }
            break;
            
        case VERTICAL:
            for(i = 0; i < tamano; i++) {
                if (!casillas_validas(tablero, fila + i, columna)) {
                    return 0;
                }
            }
            break;
            
        case DIAGONAL_DER:
            for(i = 0; i < tamano; i++) {
                if (!casillas_validas(tablero, fila + i, columna + i)) {
                    return 0;
                }
            }
            break;
            
        case DIAGONAL_IZQ:
            for(i = 0; i < tamano; i++) {
                if (!casillas_validas(tablero, fila + i, columna - i)) {
                    return 0;
                }
            }
            break;
    }
    
    return 1;
}

int casillas_validas(Tablero* tablero, int fila, int columna) {
    const int direcciones[][2] = {{-1,-1}, {-1,0}, {-1,1},
                                 {0,-1},          {0,1},
                                 {1,-1},  {1,0},  {1,1}};
    int i;
    
    if (tablero->casillas[fila][columna] != ' ') {
        return 0;
    }
    
    for(i = 0; i < 8; i++) {
        int nueva_fila = fila + direcciones[i][0];
        int nueva_col = columna + direcciones[i][1];
        
        if (es_posicion_valida(nueva_fila, nueva_col, tablero->tamano)) {
            if (tablero->casillas[nueva_fila][nueva_col] != ' ') {
                return 0;
            }
        }
    }
    
    return 1;
}

int es_tipo_disparo_valido(char tipo) {
    return (tipo == 'A' || tipo == 'M');
}

int es_nombre_jugador_valido(const char* nombre) {
    return (nombre != NULL && strlen(nombre) <= 20 && strlen(nombre) >= 1);
}

int es_tamano_tablero_valido(int tamano) {
    return (tamano >= MIN_TAMANO_TABLERO && tamano <= MAX_TAMANO_TABLERO);
}

int es_cantidad_barcos_valida(int cantidad, int tamano_barco, 
                            int tamano_tablero) {
    int espacio_necesario = cantidad * tamano_barco;
    int espacio_total = tamano_tablero * tamano_tablero;
    
    return (cantidad > 0 && espacio_necesario <= espacio_total);
}
