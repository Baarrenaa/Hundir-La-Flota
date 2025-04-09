#ifndef MAIN_H
#define MAIN_H

#include "configuracion.h"
#include "tablero.h"
#include "disparos.h"
#include "interfaz.h"
#include "validaciones.h"

void configurar_juego(Configuracion** config, Jugador* jugador1, Jugador* jugador2);
void iniciar_partida(Configuracion** config, Jugador* jugador1, Jugador* jugador2, int* turno_actual);
void inicializar_jugadores(Jugador* jugador1, Jugador* jugador2, int tamano);
void liberar_jugadores(Jugador* jugador1, Jugador* jugador2);

#endif
