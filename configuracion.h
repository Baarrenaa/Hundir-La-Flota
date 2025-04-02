#ifndef CONFIGURACION_H
#define CONFIGURACION_H

typedef struct {
    int tamano_tablero;
    Barco* barcos;
    int num_barcos;
} Configuracion;

Configuracion* crear_configuracion();
void guardar_configuracion(Configuracion* config, const char* archivo);
Configuracion* cargar_configuracion(const char* archivo);

#endif
