#include "interfaces/cuerpo.h"
#include "interfaces/matriz.h"
#include <stdio.h>

typedef enum {
    ESCALON = 'E',
    SUMA = '+',
    RESTA = '-'
} Operaciones;

int main(int argc, char *argv[]) {
    
    Matriz m1 = NULL;
    Matriz m2 = NULL;

    if (argc < 3) {
        fprintf(stderr, "La cantidad de argumentos es insuficiente.\n");
        exit(1);
    }

    switch(argv[0][0]) {
        case ESCALON:
            m1 = matriz_crear(obtener_cuerpo(), argv[1]);
            if (m1) {matriz_imprimir(m1); break;}
            else exit(1);
        default: {
            fprintf(stderr, "La operación no se puede realizar\n");
            exit(1);
        }
    }

    if (m1) matriz_eliminar(m1);
    if (m2) matriz_eliminar(m2);
    return 0;
}