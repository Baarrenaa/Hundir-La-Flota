#ifndef ARCHIVOS_H
#define ARCHIVOS_H

int guardar_partida(const char* archivo, Configuracion* config);
int cargar_partida(const char* archivo, Configuracion** config);

#endif
