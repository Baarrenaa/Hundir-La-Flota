#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "main.h"
#include "configuracion.h"
#include "tablero.h"
#include "disparos.h"
#include "interfaz.h"
#include "validaciones.h"

typedef struct {
    int id;
    char nombre[21];
    char tipo_disparo;
    Tablero* flota;
    Tablero* oponente;
    int num_disparos;
    int ganador;
} Jugador;

int main() {
    int opcion_menu;
    Configuracion* config = NULL;
    Jugador jugador1, jugador2;
    int turno_actual = 1;
    int juego_activo = 1;
    
    config = crear_configuracion();
    if (!config) {
        fprintf(stderr, "Error al crear la configuración inicial\n");
        return 1;
    }
    
    config->tamano_tablero = 10;
    
    int num_barcos;
    config->barcos = cargar_barcos("Barcos.txt", &num_barcos);
    if (!config->barcos || num_barcos == 0) {
        fprintf(stderr, "Error al cargar los barcos\n");
        liberar_configuracion(config);
        return 1;
    }
    
    jugador1.id = 1;
    jugador2.id = 2;
    
    printf("=== BIENVENIDO AL JUEGO HUNDIR LA FLOTA ===\n");
    
    while(juego_activo) {
        mostrar_menu_principal();
        
        printf("\nSeleccione una opción: ");
        scanf("%d", &opcion_menu);
        
        switch(opcion_menu) {
            case 1:
                configurar_juego(&config, &jugador1, &jugador2);
                break;
                
            case 2:
                iniciar_partida(&config, &jugador1, &jugador2, &turno_actual);
                break;
                
            case 3:
                juego_activo = 0;
                printf("¡Gracias por jugar!\n");
                break;
                
            default:
                printf("Opción no válida\n");
        }
    }
    
    liberar_configuracion(config);
    liberar_jugadores(&jugador1, &jugador2);
    
    return 0;
}

void configurar_juego(Configuracion** config, Jugador* jugador1, Jugador* jugador2) {
    int opcion;
    
    printf("\n=== CONFIGURACIÓN DEL JUEGO ===\n");

    printf("Nombre del Jugador 1: ");
    scanf("%s", jugador1->nombre);
    printf("Nombre del Jugador 2: ");
    scanf("%s", jugador2->nombre);
    
    printf("Tipo de disparo Jugador 1 (A/M): ");
    scanf(" %c", &jugador1->tipo_disparo);
    printf("Tipo de disparo Jugador 2 (A/M): ");
    scanf(" %c", &jugador2->tipo_disparo);
    
    srand(time(NULL));
    (*config)->jugador_inicio = (rand() % 2) + 1;
}

void iniciar_partida(Configuracion** config, Jugador* jugador1, Jugador* jugador2, 
                     int* turno_actual) {
    int terminado = 0;
    
    inicializar_jugadores(jugador1, jugador2, (*config)->tamano_tablero);
    
    colocar_barcos(jugador1->flota, (*config)->barcos, (*config)->num_barcos);
    colocar_barcos(jugador2->flota, (*config)->barcos, (*config)->num_barcos);
    
    while(!terminado) {
        mostrar_estado_partida(jugador1, jugador2, *turno_actual);
        
        if (*turno_actual == 1) {
            realizar_turno(jugador1, jugador2, (*config)->jugador_inicio);
        } else {
            realizar_turno(jugador2, jugador1, (*config)->jugador_inicio);
        }
        
        terminado = verificar_fin_partida(jugador1, jugador2);
        *turno_actual = (*turno_actual == 1) ? 2 : 1;
    }
}

void inicializar_jugadores(Jugador* jugador1, Jugador* jugador2, int tamano) {
    // Inicializar tableros de flota y oponente para cada jugador
    jugador1->flota = crear_tablero(tamano);
    jugador1->oponente = crear_tablero(tamano);
    jugador2->flota = crear_tablero(tamano);
    jugador2->oponente = crear_tablero(tamano);
    
    jugador1->num_disparos = 0;
    jugador2->num_disparos = 0;
    jugador1->ganador = 0;
    jugador2->ganador = 0;
}

void liberar_jugadores(Jugador* jugador1, Jugador* jugador2) {
    liberar_tablero(jugador1->flota);
    liberar_tablero(jugador1->oponente);
    liberar_tablero(jugador2->flota);
    liberar_tablero(jugador2->oponente);
}
