/* 
    Esta definición de universos establece a Cuerpo e IO como punteros, por lo que hay que hacer
    una administración de memoria manual. No queda claro cuál es mejor.
*/

#ifndef UNIVERSOS_DINAMICO
#define UNIVERSOS_DINAMICO

typedef struct __io__ {
    void *(* crear) (int, ...);
    void (*imprimir) (void *);
    void *(* copiar) (void *);
    void (* eliminar) (void *);
}* IO;

typedef struct __cuerpo__ {
    int (* comparar) (void * op1, void * op2);
    void * (* suma) (void* op1, void* op2);
    void * (* producto) (void* op1, void* op2);
    IO* mundo_real;
}* Cuerpo;

Cuerpo cuerpo_construir(
    int (* comparar) (void * op1, void * op2),
    void * (* suma) (void* op1, void* op2),
    void * (* producto) (void* op1, void* op2),
    IO mundo_real
);

void cuerpo_destruir(Cuerpo);


IO io_construir(
    void *(* crear) (int, ...),
    void (*imprimir) (void *),
    void *(* copiar) (void *),
    void (* eliminar) (void *)
);

void io_destruir(IO);

#endif