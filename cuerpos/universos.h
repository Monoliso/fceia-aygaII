/* 
    Esta definición de los universos establece a Cuerpo e IO como estructuras, con la idea de que
    al no tener que mutar dicha memoria es innecesario tener que manejar la memoria de forma
    manual.
*/

#ifndef UNIVERSOS_ESTATICO
#define UNIVERSOS_ESTATICO

typedef struct io {
    void *(* crear) (int, ...);
    void (*imprimir) (void *);
    void *(* copiar) (void *);
    void (* eliminar) (void *);
} IO;

typedef struct {
    int (* comparar) (void * op1, void * op2);
    void * (* suma) (void* op1, void* op2);
    void * (* producto) (void* op1, void* op2);
    IO mundo_real;
} Cuerpo;

#endif