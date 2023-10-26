# Comentarios de desarrollo

## Introdución de elementos en la matriz (ya instanciada)
Una lista de argumentos, antes que funciones variadicas, tiene la flexibilidad de servir para una API como una aplicación individual. Esto se debe a que uno no puede evaluar con distintos elementos las funciones en tiempo de ejecución, pero puede pasar objetos que se construyen mientras se evalua.

Como no queda claro si esto va a ser una API o va a ejecutarse directamente, elijo una *lista*.

Posibles funciones para añadir elementos:

```C
Pila x = pushear(1, 2, 3, ...)

matriz_cambiar_fila(matriz, 2, {void*});
matriz_cambiar_fila(matriz, 2, ...);
matriz_cambiar_fila(matriz, 2, Pila x);

```

## Generación de instancia con los argumentos establecidos
Otro acercamiento es instanciar con los elementos. De vuelta, tiene que ser un arreglo.

```C
matriz_crear(cuerpo, "n1 n2 n3; ...");
```
Temita: si son objetos más complejos? Cómo se puede hacer la conversión?
Bueno, supongo que a partir del constructor. El constructor debería poder construir un dato a partir del string.
Esa es la clave: un constructor me permite transformar entradas del mundo (strings) en tipos de datos con semántica dentro del programa.