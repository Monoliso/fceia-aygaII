#ifndef REALES
#define REALES

float *reales_crear(char *matriz);

void reales_imprimir(float *real);

float *reales_copiar(float *real);

void reales_eliminar(float *real);

int reales_comparar(float *real1, float *real2);

float *reales_suma(float *real1, float *real2);

float *reales_producto(float *real1, float *real2);

float *reales_resta(float *real1, float *real2);

float *reales_division(float *real1, float *real2);

#endif