#include "validaciones.h"

bool validar_impacto(Tablero* flota, Coordenada coordenada) {
    return flota->casillas[coordenada.x + coordenada.y * flota->n] != VACIO;
}

bool verificar_hundido(Tablero* flota, Coordenada coordenada) {
    // Implementación de verificación de barco hundido pendiente
}
