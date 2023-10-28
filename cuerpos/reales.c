#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>

float *reales_crear(char *matriz) {
    float* resultado = malloc(sizeof(float));
    return resultado;
}

void reales_imprimir(float* real) {
    printf("%-8.2f", *(real));
}

float *reales_copiar(float* real) {
    float* resultado = malloc(sizeof(float));
    *(resultado) =  *(real);
    return resultado;
}

void reales_eliminar(float *real) {
    free(real);
}

int reales_comparar(float *real1, float* real2) {
    return *(real1) == *(real2);
}

float *reales_suma(float *real1, float *real2) {
    float *resultado = malloc(sizeof(float));
    *resultado = *(real1) + *(real2);
    return resultado;
}

float *reales_resta(float *real1, float *real2) {
    float *resultado = malloc(sizeof (float));
    *resultado = *(real1) - *(real2);
    return resultado;
}

float *reales_producto(float *real1, float *real2) {
    float *resultado = malloc(sizeof(float));
    *resultado = *(real1) * *(real2);
    return resultado;
}

float *reales_division(float *real1, float *real2) {
    float *resultado = malloc(sizeof (float));
    *resultado = *(real1) / *(real2);
    return resultado;
}