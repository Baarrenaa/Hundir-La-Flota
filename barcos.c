#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "barcos.h"

Barco* cargar_barcos(const char* archivo, int* num_barcos) {
    FILE* fichero = NULL;
    Barco* barcos = NULL;
    char linea[50];
    int contador = 0;
    
    fichero = fopen(archivo, "r");
    if (!fichero) {
        fprintf(stderr, "Error al abrir el archivo %s\n", archivo);
        return NULL;
    }
    
    while (fgets(linea, sizeof(linea), fichero)) {
        if (strlen(linea) > 1) {  // Ignorar líneas vacías
            contador++;
        }
    }
    
    rewind(fichero);
    
    barcos = (Barco*)malloc(contador * sizeof(Barco));
    if (!barcos) {
        fclose(fichero);
        fprintf(stderr, "Error al reservar memoria para los barcos\n");
        return NULL;
    }
    
    int i = 0;
    while (fgets(linea, sizeof(linea), fichero) && i < contador) {
        if (strlen(linea) > 1) {  // Ignorar líneas vacías
            sscanf(linea, "%[^-]-%c-%d", barcos[i].nombre, &barcos[i].id, &barcos[i].cantidad);
            barcos[i].tamano = strlen(barcos[i].nombre);  // El tamaño es la longitud del nombre
            
            barcos[i].nombre[strlen(barcos[i].nombre)-1] = '\0';
        }
        i++;
    }
    
    fclose(fichero);
    *num_barcos = contador;
    return barcos;
}

void liberar_barcos(Barco* barcos, int num_barcos) {
    if (barcos != NULL) {
        free(barcos);
    }
}
