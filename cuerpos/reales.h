#ifndef REALES
#define REALES

void *reales_crear(int cantidad, ...);

void reales_imprimir(void* real);

void* reales_copiar(void* real);

void reales_eliminar(void *real);

int reales_comparar(void *real1, void* real2);

void * reales_suma(void *real1, void* real2);

void* reales_producto(void *real1, void*real2);

#endif