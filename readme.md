# BuddyNet

BuddyNet es un proyecto realizado en la clase TC1031. Es una red social local donde se podrán ver publicaciones, filtrlas, darles votos(ya sean positivos o negativos); Se podrá darles follow a otros usuarios y dependiendo de eso cambiará el feed, ya que solo saldrán publicaciones de amigos, de amigos de amigos, y de los amigos de ellos (hasta 3 conexiones).

Hasta esta entrega lo único que falta para terminar en la idea original es implementar un algoritmo que permita que en el feed salgan únicamente las publicaciones de las 3 conexiones.

### Índice:
- [BuddyNet](#buddynet)
- [Índice](#índice)
- [Competencias](#competencias)
    - [SICT0301](#sict0301-evalúa-los-componentes)
    - [SICT0301](#sict0302-toma-decisiones)

## Competencias:

### SICT0301: Evalúa los componentes 
Solo se usa un algoritmo de ordenamiento, se usa un `Merge Sort` el cuál está ubicado en `Sorts.h`. Se usó este ya que el `Merge Sort` tiene una complejidad temporal de `O(n log(n))` y una complejidad espacial de `O(n)`. Hay otros algoritmos de ordenamiendo como el `Quick Sort`, sin embargo, para el peor de los casos termina siento más lento que el `Merge Sort`.

Se usan 2 estructuras lineales, las cuales están ubicadas en `Structures.h`. Una de ellas es el `Stack` la cuál tiene una complejidad espacial de `O(n)`, mientras que para insertar, borrar y obtener su primer elemento es de `O(1)`. La otra estructura que se usa es un `Queue` que tiene las mismas complejidades que el `Stack`.

### SICT0302: Toma decisiones
La razón por la cuál se ocupaba un algoritmo de ordenamiento es debido a que se ocupaban ordenar las publicaciones para que las personas las pudieran visualizar de una mejor manera, debido a las complejidades que tiene y a su fácil implementación fue que se optó por usar el `Merge Sort`.

Se utilizó el `Stack` ya que se quería tener un registro de las notificaciones de un usuario, y debido a que funcionan con una estructura LIFO(Last in - first out) se escogió esa estructura.

Se va a utilizar un `Queue` para poder implementar el algoritmo de Djikstra para poder buscar las 3 conexiones máximas entre los usuarios. Sin embargo, ese algoritmo aún no se ha desarrollado ya que alguna estructura no lineal podría ser útil para este caso en específico,

### SICT0303: Implementa acciones científicas
Para poder acceder a los datos del `Stack` se usan la funciones `top()` y `pop()`, las cuales regresan el elemento hasta arriba y eliminan el elemento de hasta arriba respectivamente. Dependiendo de las entradas del usuario se van eliminando y recorriendo la estructura.

Se hizo un sistema de lectura/escritura para poder guardar datos, esto se puede entontrar en la parte de abajo del archivo `BuddyNet.h`, en las funciones `loadData()` y `storeData()`, mientras que los datos se guardan en `Database.txt`.