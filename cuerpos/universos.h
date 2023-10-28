/* 
    Esta definición de los universos establece a Cuerpo e IO como estructuras, con la idea de que
    al no tener que mutar dicha memoria es innecesario tener que manejar la memoria de forma
    manual.
*/

#ifndef UNIVERSOS_ESTATICO
#define UNIVERSOS_ESTATICO

typedef void *(* fn_cons) (char *input);
typedef void *(* fn_imp) (void *input);
typedef void *(* fn_dup) (void *input);
typedef void *(* fn_dest) (void *input);

typedef void *(* fn_comp) (void *op1, void *op2);
typedef void *(* fn_sum) (void *op1, void *op2);
typedef void *(* fn_dif) (void *op1, void *op2);
typedef void *(* fn_prod) (void *op1, void *op2);
typedef void *(* fn_div) (void *op1, void *op2);

typedef struct io {
    fn_cons crear;
    fn_imp imprimir;
    fn_dup copiar;
    fn_dest destruir;
} IO;

typedef struct {
    fn_comp comparar;
    fn_sum suma;
    fn_dif resta;
    fn_prod producto;
    fn_div division;
    IO mundo_real;
} Cuerpo;

#endif