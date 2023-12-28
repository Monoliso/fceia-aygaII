#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "interfaces/lista.h"

struct __lista__ {
    int dimension, capacidad;
    void** elementos;
};

Lista lista_crear() {
    Lista nuevo_arreglo = malloc(sizeof(struct __lista__));
    nuevo_arreglo->capacidad = CAPACIDAD_INICIAL;
    nuevo_arreglo->dimension = 0;
    nuevo_arreglo->elementos = malloc(sizeof(void*) * nuevo_arreglo->capacidad);
    return nuevo_arreglo;
}

void lista_destruir(Lista arreglo) {
    free(arreglo->elementos);
    free(arreglo);
}

Lista lista_agregar(Lista arreglo, void* nuevo_elemento) {
    if (arreglo->dimension == arreglo->capacidad) {
        arreglo->capacidad *= 2;
        arreglo->elementos = realloc(arreglo->elementos, sizeof(void*)*arreglo->capacidad);
    }
    
    arreglo->elementos[arreglo->dimension] = nuevo_elemento;
    arreglo->dimension++;
    return arreglo;
}

void** lista_obtener(Lista arreglo) {
    void** resultado = malloc(sizeof(void*) * arreglo->dimension);
    return memcpy(resultado, arreglo->elementos, arreglo->dimension);
}

void* lista_elemento(Lista arreglo, int indice) { 
    if(indice > arreglo->dimension) {
        fprintf(stderr, "El indice excede la dimension del arreglo");
        return NULL;
    }
    return arreglo->elementos[indice]; 
}

Lista lista_concat(Lista arreglo01, Lista arreglo02) {
    int dimension_total = arreglo01->dimension + arreglo02->dimension;

    Lista nuevo_arreglo = malloc(sizeof(struct __lista__));
    nuevo_arreglo->capacidad = dimension_total*2;
    nuevo_arreglo->dimension = dimension_total;
    nuevo_arreglo->elementos = malloc(sizeof(void*)*dimension_total*2);
    memcpy(nuevo_arreglo->elementos, arreglo01->elementos, arreglo01->dimension);
    return memcpy(nuevo_arreglo->elementos+arreglo01->dimension, arreglo02->elementos, 
        arreglo02->dimension);
}

Lista lista_agregar_inicio(Lista arreglo, void* elemento) {

    arreglo->dimension++;
    void** vieja_lista = arreglo->elementos;
    int nueva_capacidad = 0;
    if(arreglo->capacidad == arreglo->dimension) {
        arreglo->capacidad *= 2;
        arreglo->elementos = malloc(arreglo->capacidad);
        nueva_capacidad = 1;
    }

    for(int i = arreglo->dimension; i > 0; i--) {
        arreglo->elementos[i] = vieja_lista[i-1];
    }
    arreglo->elementos[0] = elemento;
    
    if(nueva_capacidad) free(vieja_lista);
    return arreglo;
}

unsigned lista_dimension(Lista arreglo) { 
    if(!arreglo) return 0;
    return arreglo->dimension; 
}