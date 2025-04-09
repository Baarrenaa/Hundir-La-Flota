#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "configuracion.h"
#include "archivos.h"

Configuracion* crear_configuracion() {
    Configuracion* config = NULL;
    
    config = (Configuracion*)malloc(sizeof(Configuracion));
    if (!config) {
        fprintf(stderr, "Error al crear la configuración\n");
        return NULL;
    }
    
    config->tamano_tablero = 0;
    config->barcos = NULL;
    config->num_barcos = 0;
    
    return config;
}

int guardar_configuracion(Configuracion* config, const char* archivo) {
    FILE* fichero = NULL;
    
    fichero = fopen(archivo, "w");
    if (!fichero) {
        fprintf(stderr, "Error al guardar la configuración en %s\n", archivo);
        return 0;
    }
    
    fprintf(fichero, "%d\n", config->tamano_tablero);
    
    fprintf(fichero, "%d\n", config->num_barcos);
    for (int i = 0; i < config->num_barcos; i++) {
        fprintf(fichero, "%s-%c-%d\n", config->barcos[i].nombre, 
               config->barcos[i].id, config->barcos[i].cantidad);
    }
    
    fclose(fichero);
    return 1;
}

Configuracion* cargar_configuracion(const char* archivo) {
    Configuracion* config = NULL;
    int num_barcos;
    
    config = crear_configuracion();
    if (!config) {
        return NULL;
    }
    
    FILE* fichero = fopen(archivo, "r");
    if (!fichero) {
        fprintf(stderr, "Error al cargar la configuración desde %s\n", archivo);
        liberar_configuracion(config);
        return NULL;
    }
    
    fscanf(fichero, "%d", &config->tamano_tablero);
    
    fscanf(fichero, "%d", &num_barcos);
    config->barcos = (Barco*)malloc(num_barcos * sizeof(Barco));
    if (!config->barcos) {
        fprintf(stderr, "Error al reservar memoria para los barcos\n");
        liberar_configuracion(config);
        fclose(fichero);
        return NULL;
    }
    
    for (int i = 0; i < num_barcos; i++) {
        char nombre[21];
        char id;
        int cantidad;
        
        fscanf(fichero, "%[^-]-%c-%d", nombre, &id, &cantidad);
        strcpy(config->barcos[i].nombre, nombre);
        config->barcos[i].id = id;
        config->barcos[i].cantidad = cantidad;
    }
    
    config->num_barcos = num_barcos;
    fclose(fichero);
    return config;
}

void liberar_configuracion(Configuracion* config) {
    if (config != NULL) {
        if (config->barcos != NULL) {
            free(config->barcos);
        }
        free(config);
    }
}
