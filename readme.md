# BuddyNet

BuddyNet es un proyecto realizado en la clase TC1031. Es una red social local donde se podrán ver publicaciones, filtrlas, darles votos(ya sean positivos o negativos); Se podrá darles follow a otros usuarios y dependiendo de eso cambiará el feed, ya que solo saldrán publicaciones de amigos, de amigos de amigos, y de los amigos de ellos (hasta 3 conexiones).

### Índice:
- [BuddyNet](#buddynet)
- [Índice](#índice)
- [Competencias](#competencias)
    - [SICT0301](#sict0301-evalúa-los-componentes)
    - [SICT0302](#sict0302-toma-decisiones)
    - [SICT0303](#sict0303-implementa-acciones-científicas)

## Competencias:

### SICT0301: Evalúa los componentes 
Solo se usa un algoritmo de ordenamiento, se usa un `Merge Sort` el cuál está ubicado en `Sorts.h`. Se usó este ya que el `Merge Sort` tiene una complejidad temporal de `O(n log(n))` y una complejidad espacial de `O(n)`. Hay otros algoritmos de ordenamiendo como el `Quick Sort`, sin embargo, para el peor de los casos termina siendo más lento que el `Merge Sort`.

Se usan 2 estructuras lineales, las cuales están ubicadas en `Structures.h`. Una de ellas es el `Stack` la cuál tiene una complejidad espacial de `O(n)`, mientras que para insertar, borrar y obtener su primer elemento es de `O(1)`. La otra estructura que se usa es un `Queue` que tiene las mismas complejidades que el `Stack`.

Como estructura no lineal se usa un Grafo al que se le implementó un `BFS`, dicho código está implementado en `Profile.h` en la clase de `Graph`. Tiene una complejidad temporal de `O(V'+E')`, es decir, la suma de los nodos y aristas posibles a alcanzar hasta cumplir la máxima profundidad de 3 nodos. De la misma manera cuenta con una complejidad espacial de `O(V)` debido a que utiliza un `Queue` para guardar los próximos nodos a visitar y un `Vector` para guardar los nodos ya visitados.

### SICT0302: Toma decisiones
La razón por la cuál se ocupaba un algoritmo de ordenamiento es debido a que se ocupaban ordenar las publicaciones para que las personas las pudieran visualizar de una mejor manera, debido a las complejidades que tiene y a su fácil implementación fue que se optó por usar el `Merge Sort`.

Se utilizó el `Stack` ya que se quería tener un registro de las notificaciones de un usuario, y debido a que funcionan con una estructura LIFO(Last in - first out) se escogió esa estructura.

Se utilizó un `Queue` para poder implementar un algoritmo de BFS en un **grafo** para encontrar la red de amigos del usuario, donde se va a limitar a 3 nodos de profundidad, para de esta forma asegurarse que el feed sea cercano al usuario y se fomente la ampliación de su red.

### SICT0303: Implementa acciones científicas
Para poder acceder a los datos del `Stack` se usan la funciones `top()` y `pop()`, las cuales regresan el elemento hasta arriba y eliminan el elemento de hasta arriba respectivamente. Dependiendo de las entradas del usuario se van eliminando y recorriendo la estructura. En el caso del `Queue` es igual, solo que envés de `top()` se usa `front()`.

Para consultar la red de amigos del usuario se usa un algoritmo de `BFS` limitándolo a un máximo de 3 nodos de profundidad.

Se hizo un sistema de lectura/escritura para poder guardar datos, esto se puede entontrar en la parte de abajo del archivo `BuddyNet.h`, en las funciones `loadData()` y `storeData()`, mientras que los datos se guardan en `Database.txt`.