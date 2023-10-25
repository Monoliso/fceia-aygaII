#include "matriz.h"
#include <stdio.h>

// ---------------- Manejo de memoria ----------------

// Genera una matriz nula con las dimensiones dadas. Debería estar restringido
// para los enteros en adelante, pero comprobar si es cuerpo válido es muy
// complicado.
Matriz matriz_crear(Cuerpo cuerpo, unsigned nro_filas, unsigned nro_columnas) {

    Matriz resultado = malloc(sizeof(struct __matriz__));

    resultado->universo = cuerpo;
    resultado->nro_filas = nro_filas;
    resultado->nro_columnas = nro_columnas;

    resultado->contenido = malloc(sizeof(void *)* resultado->nro_filas);
    for(int i = 0; i < resultado->nro_filas; i++) {
        resultado->contenido[i] = calloc(resultado->nro_columnas, sizeof(void*));
    }
    return resultado;
}

void matriz_imprimir(Matriz matriz) {
    for(int i = 0; i < matriz->nro_filas; i++) {
        for(int x = 0; x < matriz->nro_columnas; x++) {
            matriz->universo.mundo_real.imprimir(matriz->contenido[i][x]);
        }
        puts("");
    }
}

void* matriz_copiar(Matriz matriz) {
    return NULL;
}

void matriz_eliminar(Matriz matriz) {

    for(int i = 0; i < matriz->nro_filas; i++) {
        for(int x = 0; x < matriz->nro_columnas; x++) {
            matriz->universo.mundo_real.eliminar(matriz->contenido[i][x]);
        }
        free(matriz->contenido[i]);
    }

    // cuerpo_destruir(matriz->universo);
    free(matriz->contenido);
    free(matriz);
};

void matriz_cambiar_fila(Matriz matriz, int nro_fila, void** fila) {

    for (int i = 0; i < matriz->nro_columnas; i++) {
        matriz->contenido[nro_fila][i] = matriz->universo.mundo_real.crear(1, fila[i]);;
    }
}


// ---------------- Operaciones ----------------