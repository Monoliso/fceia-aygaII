#include "int-sist-ecuaciones-lineales.c"

int main() {

    int temp[] = {1, 2, 0, 
                  -3, 1, 4};
    M a = matriz_crear(2, 3);
    matriz_cambiar_valores(a, temp);

    // matriz_cambiar_fila(a, 0, (int []){1, 2, 0});
    // matriz_cambiar_fila(a, 1, (int []){-3, 1, 4});

    int temp1[]= {0, 1, -5, 3,
                  2, 1, 0, -2, 
                  7, 5, -2, 10};
    M b = matriz_crear(3, 4);
    matriz_cambiar_valores(b, temp1);

    M c = matriz_mult(a, b);
    matriz_destruir_multiples(3, a, b, c);
    return 0;
}