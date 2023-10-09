#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <stdarg.h>

typedef struct {
    int nro_filas, nro_columnas;
    int **contenido;
} Matriz;

typedef Matriz* M;

Matriz* matriz_crear(int cant_filas, int cant_colum) {
    M resultado = malloc(sizeof(Matriz));
    resultado->contenido = malloc(sizeof(int *)*cant_filas);
    resultado->nro_filas = cant_filas;
    resultado->nro_columnas = cant_colum;

    for(int i = 0; i < cant_filas; i++) {
        resultado->contenido[i] = calloc(cant_colum, sizeof(int));
    }

    return resultado;
}

static void matriz_destruir_contenido(Matriz* matriz) {
    for(int i = 0; i < matriz->nro_filas; i++) {
        free(matriz->contenido[i]);
    }
}

void matriz_destruir(Matriz* matriz) {
    matriz_destruir_contenido(matriz);
    free(matriz->contenido);
    free(matriz);
}

// Chat-GPT
void matriz_destruir_multiples(int total, ...) {
    // Declare a va_list to hold the variable arguments
    va_list args;

    // Initialize the va_list with the variable arguments
    va_start(args, total);

    // Loop through the variable arguments and add them to the total
    for (int i = 0; i < total; i++) {
        matriz_destruir(va_arg(args, Matriz*));
    }

    // Clean up the va_list
    va_end(args);
}

Matriz* matriz_ident(int dimension) {

    M identidad = matriz_crear(dimension, dimension);
    for(int i = 0; i < dimension; i++) {
        identidad->contenido[i][i] = 1;
    }
    return identidad;
}

void matriz_imprimir(Matriz* matriz) {
    for(int i = 0; i < matriz->nro_filas; i++) {
        for(int x = 0; x < matriz->nro_columnas; x++) {
            printf("%i ", matriz->contenido[i][x]);
        }
        puts("");
    }
}

Matriz* matriz_copiar(Matriz* matriz) {
    
    M copia = matriz_crear(matriz->nro_filas, matriz->nro_columnas);

    for(int i = 0; i < matriz->nro_filas; i++) {
        for(int x = 0; x < matriz->nro_columnas; x++) {
            copia->contenido[i][x] = matriz->contenido[i][x];
        }
    }

    return copia;
}

void matriz_cambiar_fila(Matriz* matriz, int nro_fila, int* fila) {

    for (int i = 0; i < matriz->nro_columnas; i++) {
        matriz->contenido[nro_fila][i] = fila[i];
    }
}

// Santa biblia: https://stackoverflow.com/questions/2828648/how-to-pass-a-multidimensional-array-to-a-function-in-c-and-c
void matriz_cambiar_valores(Matriz* matriz, int* nuevos_valores) {
    
    for (int i = 0; i < matriz->nro_filas; i++) {
        for(int x = 0; x < matriz->nro_columnas; x++) {
            matriz->contenido[i][x] = nuevos_valores[i*matriz->nro_columnas + x];
        }
    }
}

Matriz* matriz_mult_escalar(Matriz* matriz, int escalar) {

    M resultado = matriz_copiar(matriz);

    for(int i = 0; i < matriz->nro_filas; i++) {
        for(int x = 0; x < matriz->nro_columnas; x++) {
            resultado->contenido[i][x] *= escalar;
        }
    }

    return resultado;
}

Matriz* matriz_mult(Matriz* matriz01, Matriz* matriz02) {

    if (matriz01->nro_columnas != matriz02->nro_filas) {
        // Algo con errno para manejar el error
        return NULL;
    }

    M resultado = matriz_crear(matriz01->nro_filas, matriz02->nro_columnas);

    for(int i = 0; i < matriz01->nro_filas; i++) {
        for(int j = 0; j < matriz02->nro_columnas; j++) {
            for(int k = 0; k < matriz02->nro_filas; k++) {
                resultado->contenido[i][j] += (matriz01->contenido[i][k] * matriz02->contenido[k][j]); 
            }
        }
    }

    return resultado;
}
