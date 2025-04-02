#include <stdio.h>
#include <stdlib.h>
#include "configuracion.h"
#include "disparos.h"
#include "interfaz.h"

int main() {
    Configuracion* config = cargar_configuracion("config.txt");
    if (!config) {
        fprintf(stderr, "Error al cargar la configuración\n");
        return 1;
    }

    int opcion;
    do {
        mostrar_menu_principal();
        scanf("%d", &opcion);
        
        switch(opcion) {
            case 1:
                // Menú de configuración
                break;
            case 2:
                // Iniciar juego
                break;
        }
    } while(opcion != 3);

    liberar_configuracion(config);
    return 0;
}
