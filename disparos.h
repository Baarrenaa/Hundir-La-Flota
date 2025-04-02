#ifndef DISPAROS_H
#define DISPAROS_H

#include "configuracion.h"
#include "validaciones.h"

bool realizar_disparo(Configuracion* config, Jugador* jugador_actual, 
                     Jugador* oponente, Coordenada coordenada);

#endif
