#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>

void *reales_crear(int cantidad, ...) {
    va_list args;
    va_start(args, cantidad);

    float* resultado = malloc(sizeof(float));
    *(resultado) = *( (float*)va_arg(args, void*) );

    va_end(args);
    return resultado;
}

void reales_imprimir(void* real) {
    printf("%-8.2f", *((float*) real));
}

void* reales_copiar(void* real) {
    float* resultado = malloc(sizeof(float));
    *(resultado) =  * ((float*)real);
    return resultado;
}

void reales_eliminar(void *real) {
    free((float*) real);
}

int reales_comparar(void *real1, void* real2) {
    return *((float*)real1) == *((float*)real2);
}

void * reales_suma(void *real1, void* real2) {
    float *resultado = malloc(sizeof(float));
    *resultado = *((float*)real1) + *((float*)real2);
    return resultado;
}

void* reales_producto(void *real1, void*real2) {
    float *resultado = malloc(sizeof(float));
    *resultado = *((float*)real1) * *((float*)real1);
    return resultado;
}