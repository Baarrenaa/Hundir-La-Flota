#ifndef VALIDACIONES_H
#define VALIDACIONES_H

#include "tablero.h"

#define HORIZONTAL 0
#define VERTICAL 1
#define DIAGONAL_DER 2
#define DIAGONAL_IZQ 3

#define MIN_TAMANO_TABLERO 8
#define MAX_TAMANO_TABLERO 15

int es_posicion_valida(int fila, int columna, int tamano_tablero);
int es_colocacion_barco_valida(Tablero* tablero, int fila, int columna, 
                              int tamano, int orientacion);
int es_tipo_disparo_valido(char tipo);
int es_nombre_jugador_valido(const char* nombre);
int es_tamano_tablero_valido(int tamano);
int es_cantidad_barcos_valida(int cantidad, int tamano_barco, 
                            int tamano_tablero);

#endif
