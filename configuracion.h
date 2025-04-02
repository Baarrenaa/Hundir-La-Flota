#ifndef CONFIGURACION_H
#define CONFIGURACION_H

#include "tablero.h"
#include "barcos.h"

typedef enum {
    AUTOMATICO,
    MANUAL
} TipoDisparo;

typedef struct {
    int id;
    char nombre[21];
    TipoDisparo tipo_disparo;
    int num_disp;
    bool ganador;
    Tablero* flota;
    Tablero* oponente;
} Jugador;

typedef struct {
    int n;
    Jugador jugadores[2];
    Flota* tipos_barcos;
} Configuracion;

Configuracion* cargar_configuracion(const char* filename);
void liberar_configuracion(Configuracion* config);

#endif
