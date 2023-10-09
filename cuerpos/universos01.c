#include <stdlib.h>
#include "universos01.h"

Cuerpo cuerpo_construir(
    int (* comparar) (void * op1, void * op2),
    void * (* suma) (void* op1, void* op2),
    void * (* producto) (void* op1, void* op2),
    IO mundo_real
) {
    Cuerpo resultado = malloc(sizeof(struct __cuerpo__));
    resultado->comparar = comparar;
    resultado->suma = suma;
    resultado->producto = producto;
    resultado->mundo_real = mundo_real;
    return resultado;
};

void cuerpo_destruir(Cuerpo universo) {
    free(universo);
}

IO io_construir(
    void *(* crear) (int, ...),
    void (*imprimir) (void *),
    void *(* copiar) (void *),
    void (* eliminar) (void *)
) {
    IO resultado = malloc(sizeof(struct __io__));
    resultado->crear = crear;
    resultado->imprimir = imprimir;
    resultado->copiar = copiar;
    resultado->eliminar = eliminar;
    return resultado;
};

void io_destruir(IO mundo_real) {
    free(mundo_real);
};