#include "validaciones.h"

bool validar_impacto(Tablero* flota, Coordenada coordenada) {
    return flota->casillas[coordenada.x + coordenada.y * flota->n] != VACIO;
}

bool verificar_hundido(Tablero* flota, Coordenada coordenada) {
    bool verificar_hundido(Tablero* flota, Coordenada coordenada) {
    int x = coordenada.x;
    int y = coordenada.y;
    
    char id_barco = obtener_id_barco(flota, x, y);
    if (!id_barco) return false;

    bool hundido = true;
    for(int i = 0; i < flota->n && hundido; i++) {
        for(int j = 0; j < flota->n && hundido; j++) {
            EstadoCasilla estado = flota->casillas[i + j * flota->n];
            if (estado == TOCADO && !es_parte_de_barco_hundido(flota, i, j, id_barco)) {
                hundido = false;
            }
        }
    }

    if (hundido) {
        marcar_barcos_hundidos(flota, id_barco);
        marcar_casillas_contiguas_agua(flota, id_barco);
    }

    return hundido;
    }    
}
