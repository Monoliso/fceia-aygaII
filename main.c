#include "cuerpos/reales.h"
#include "estructuras_algebraicas/matriz.h"

int main() {

    IO reales_io = {reales_crear, reales_imprimir, reales_copiar, reales_eliminar};
    Cuerpo reales = {reales_comparar, reales_suma, reales_producto, reales_io};
    Matriz m1 = matriz_crear(reales, 2, 3);

    float f1[] = {1, 2};
    float f2[] = {-3, 1, 4};
    // float *m1[] = {f1, f2};
    


    matriz_cambiar_fila(m1, 0, (void* []){f1+0, f1+1, f1+2});
    matriz_cambiar_fila(m1, 1, (void* []){f2, f2+1, f2+2});

    matriz_imprimir(m1);

    // IO *io_reales = io_construir(reales_crear, reales_imprimir, reales_copiar, reales_eliminar);
    // Cuerpo* reales = cuerpo_construir(reales_comparar, reales_suma, reales_producto, io_reales);
    // reales.realidad.eliminar(i);

    matriz_eliminar(m1);
    return 0;
}