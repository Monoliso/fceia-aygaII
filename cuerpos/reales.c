#include <stdio.h>
#include <stdlib.h>
#include "../interfaces/cuerpo.h"

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

Cuerpo obtener_cuerpo() {
    Cuerpo reales = malloc(sizeof(Cuerpo));
    reales->comparacion = (fn_comp)reales_comparar;
    reales->suma = (fn_sum)reales_suma;
    reales->resta = (fn_dif)reales_resta;
    reales->producto = (fn_div)reales_producto;
    reales->division = (fn_div)reales_division;
    reales->mundo_real.crear = (fn_cons)reales_crear;
    reales->mundo_real.destruir = (fn_dest)reales_eliminar;
    reales->mundo_real.copiar = (fn_dup)reales_copiar;
    reales->mundo_real.imprimir = (fn_imp)reales_imprimir;
    return reales;
}