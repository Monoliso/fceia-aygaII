#include "cuerpos/reales.h"
#include "espacios-vectoriales/matriz.h"

int main() {

    IO reales_io = {(fn_cons)reales_crear, (fn_imp)reales_imprimir, (fn_dup)reales_copiar, (fn_dest)reales_eliminar};
    Cuerpo reales = {(fn_comp)reales_comparar, (fn_sum)reales_suma, (fn_dif)reales_resta, 
        (fn_prod)reales_producto, (fn_div)reales_division, reales_io};
    
    Matriz m1 = matriz_crear(reales, "x");

    float f1[] = {1, 2};
    float f2[] = {-3, 1, 4};
    // float *m1[] = {f1, f2};
    


    matriz_cambiar_fila(m1, 0, (void* []){f1+0, f1+1, f1+2});
    matriz_cambiar_fila(m1, 1, (void* []){f2, f2+1, f2+2});

    matriz_imprimir(m1);

    // IO *io_reales = io_construir(reales_crear, reales_imprimir, reales_copiar, reales_eliminar);
    // Cuerpo* reales = cuerpo_construir(reales_comparar, reales_suma, reales_producto, io_reales);
    // reales.realidad.eliminar(i);

    // matriz_eliminar(m1);
    return 0;
}