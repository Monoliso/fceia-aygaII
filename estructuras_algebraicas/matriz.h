#include <stdlib.h>
#include "../cuerpos/universos.h"

#ifndef MATRIZ
#define MATRIZ

typedef struct __matriz__{
    Cuerpo universo;
    int nro_filas, nro_columnas;
    void ***contenido;
}* Matriz;

// La idea es que matriz sea una instancia (que en teoría podría ser un alias) de un cuerpo.
// Así, dependiendo del tipo de matriz se puede garantizar las operaciones básicas.

Matriz matriz_crear(Cuerpo, unsigned, unsigned);

void* matriz_copiar(Matriz);

void matriz_imprimir(Matriz);

void matriz_eliminar(Matriz);

void matriz_cambiar_fila(Matriz, int, void**);

#endif