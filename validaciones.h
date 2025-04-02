#ifndef VALIDACIONES_H
#define VALIDACIONES_H

int es_posicion_valida(int fila, int columna, int tamano_tablero);
int es_colocacion_barco_valida(Tablero* tablero, int fila, int columna, 
                              int tamano, int orientacion);

#endif
