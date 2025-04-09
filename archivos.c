#include <stdio.h>
#include <stdlib.h>
#include "archivos.h"

int guardar_partida(const char* archivo, Configuracion* config) {
    FILE* fichero = NULL;
    
    fichero = fopen(archivo, "w");
    if (!fichero) {
        fprintf(stderr, "Error al guardar la partida en %s\n", archivo);
        return 0;
    }
    

