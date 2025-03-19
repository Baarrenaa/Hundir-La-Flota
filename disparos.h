#ifndef DISPAROS_H
#define DISPAROS_H

#include "tableros.h"

void realizarDisparo(Tablero *tablero, int x, int y);
int verificarImpacto(const Tablero *tablero, int x, int y);

#endif
