// Copia del programa en old. Sin terminar.

#include "matriz.h"

Matriz matriz_elemental1(int dimension, int fila, int escalar) {
    Matriz E1 = matriz_ident(dimension);
    E1->contenido[fila][fila] *= escalar; 
    return E1;
}

Matriz matriz_elemental2(int dimension, int fila_origen, int fila_destino, int escalar) {
    Matriz E2 = matriz_ident(dimension);
    if (E2->contenido[fila_origen][fila_origen] != 0) E2->contenido[fila_destino][fila_origen] += escalar;
    return E2;
}

// TODO
Matriz matriz_elemental3(int dimension, int fila01, int fila02) {
    return NULL;
}

void matriz_OEF1(Matriz matriz, int nro_fila, int escalar) {
    
    for(int i = 0; i < matriz->nro_columnas; i++) {
        matriz->contenido[nro_fila][i] *= escalar;
    }
}

Matriz matriz_OEF1_01(Matriz matriz, int nro_fila, int escalar) {
    Matriz E1 = matriz_elemental1(matriz->nro_filas, nro_fila, escalar);
    Matriz resultado = matriz_mult(E1, matriz);

    // matriz_destruir_contenido(matriz);
    // M* direccion_origen = &matriz;
    // matriz_destruir(matriz);
    // *(direccion_origen) = resultado;

    matriz_destruir(E1);
    return resultado;
}

void matriz_OEF2(Matriz matriz, int fila_origen, int fila_destino, int escalar) {
    
    for(int i = 0; i < matriz->nro_columnas; i++) {
        matriz->contenido[fila_destino][i] += (matriz->contenido[fila_origen][i] * escalar);
    }
}

Matriz matriz_OEF2_01(Matriz matriz, int fila_origen, int fila_destino, int escalar) {
    Matriz E2 = matriz_elemental2(matriz->nro_filas, fila_origen, fila_destino, escalar);
    Matriz resultado = matriz_mult(E2, matriz);

    // M* direccion_origen = &matriz;
    // matriz_destruir(matriz);
    // *(direccion_origen) = resultado;

    matriz_destruir(E2);
    return resultado;
}

// https://stackoverflow.com/questions/23178016/swap-two-pointers-using-xor
void matriz_OEF3(Matriz matriz, int fila01, int fila02) {

    int* intercambio = matriz->contenido[fila01];
    matriz->contenido[fila01] = matriz->contenido[fila02];
    matriz->contenido[fila02] = intercambio;
}

// TODO
Matriz matriz_OEF3_01(Matriz* matriz, int fila01, int fila02) {
    // Construir
    return NULL;
}

Matriz eliminacion_gaussiana(Matriz matriz) {

    Matriz ERF_asociada = matriz_copiar(matriz);

    for(int i = 0; i < matriz->nro_columnas; i++) {
        for(int x = 0; x < matriz->nro_filas; x++) {
            
            if(matriz->contenido[x][i] != 0 && x != i) {
                matriz_OEF3(ERF_asociada, x, i);
            } else if (matriz->contenido[x][i] != 0) {
                matriz_OEF1(ERF_asociada, x, 1 / ERF_asociada->contenido[x][i]);
            }
        }
    }
    
    return NULL;
}