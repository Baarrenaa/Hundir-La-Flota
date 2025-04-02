#ifndef CONFIG_H
#define CONFIG_H

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
    Barco* tipos_barcos;
} Configuracion;

Configuracion* cargar_configuracion(const char* filename);
void liberar_configuracion(Configuracion* config);

#endif
