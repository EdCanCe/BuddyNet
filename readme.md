# BuddyNet

BuddyNet es un proyecto realizado en la clase TC1031. Es una red social local donde se podrán ver publicaciones, filtrlas, darles votos(ya sean positivos o negativos); Se podrá darles follow a otros usuarios y dependiendo de eso cambiará el feed, ya que solo saldrán publicaciones de amigos, de amigos de amigos, y de los amigos de ellos (hasta 3 conexiones).

### Índice:
- [BuddyNet](#buddynet)
- [Índice](#índice)
- [Correciones](#correciones)
- [Competencias](#competencias)
    - [SICT0301](#sict0301-evalúa-los-componentes)
    - [SICT0302](#sict0302-toma-decisiones)
    - [SICT0303](#sict0303-implementa-acciones-científicas)

## Correciones:

**Hace un análisis de complejidad correcto y completo para todos los demás componentes del programa y determina la complejidad final del programa.:**

Se tenía un análisis únicamente de los algoritmos de ordenamiento o de inserción, obtención, etc. en las estructuras de datos. 

Se añadieron las complejidades para diferentes funciones del programa que sean lo suficientemente importantes como para escribirlas (ejemplo: no se pusieron de getters ni setters ya que es muy obvio la complejidad que van a tener; pero si de algoritmos de búsqueda).

## Competencias:

### SICT0301: Evalúa los componentes 
Solo se usa un algoritmo de ordenamiento, se usa un `Merge Sort` el cuál está ubicado en `Sorts.h`. Se usó este ya que el `Merge Sort` tiene una complejidad temporal de `O(n log(n))` y una complejidad espacial de `O(n)`. Hay otros algoritmos de ordenamiendo como el `Quick Sort`, sin embargo, para el peor de los casos termina siendo más lento que el `Merge Sort`.

Se usan 2 estructuras lineales, las cuales están ubicadas en `Structures.h`. Una de ellas es el `Stack` la cuál tiene una complejidad espacial de `O(n)`, mientras que para insertar, borrar y obtener su primer elemento es de `O(1)`. La otra estructura que se usa es un `Queue` que tiene las mismas complejidades que el `Stack`.

Como estructura no lineal se usa un Grafo al que se le implementó un `BFS`, dicho código está implementado en `Profile.h` en la clase de `Graph`. Tiene una complejidad temporal de `O(V'+E')`, es decir, la suma de los nodos y aristas posibles a alcanzar, hasta cumplir la máxima profundidad de 3 nodos. De la misma manera cuenta con una complejidad espacial de `O(V)` debido a que utiliza un `Queue` para guardar los próximos nodos a visitar y un `Vector` para guardar los nodos ya visitados.

En adición a las estructuras de datos y el algoritmos de ordenamiento mencionados anteriormente, éstos son algunos componentes del programa que vale la pena resaltar su comportamiento:

 - `profileExists()`:
    Se encuentra en `BuddyNet.h`, regresa un puntero hacia un perfil dándole su nombre de usuario como parámetro; tiene una complejidad temporal de `O(log n)`. Usa una **búsqueda binaria** ya que se añaden muy pocos usuarios en el programa, lo que signficaría que la desventaja de este algoritmo(ordenar el vector) no se repetiría mucho.

 - `postExists()`:
    Se encuentra en `BuddyNet.h`, regresa un puntero hacia una publicación dándole su ID como parámetro; tiene una complejidad temporal de `O(n)`. Usa una **búsqueda lineal** ya que el programa está pensado para tener varias inserciones, lo que haría caro los ordenamientos; haciendo que se vuelva temporalmente caro implementar una búsqueda binaria.

 - `showPosts()`:
    Se encuentra en `BuddyNet.h`, muestra las publicaciones de la red de amigos del usuario; tiene una complejidad temporal (simplificada) de `O(V' log(V'))` ya que desglosándola es de `O(V'+E'+V' log(V')+n log(V')+n)` debido a que usa un algoritmo de `BFS` para encontrar la red de amigos del usuario, la cuál se ordena, luego por cada uno de las publicaciones realiza una búsqueda binaria para ver si su autor está dentro de los amigos del usuario, y al final, se itera por cada una de las publicaciones que pudieron ser filtradas para que se impriman. En el caso de que sea `showPosts(Profile*)` la complejidad temporal es de `O(n)` ya que itera sobre las publicaciones creadas para comprobar si su autor es el perfil que se le dió como parámetro, para posteriormente iterar sobre dichas publicaciones para imprimirlas.

 - `createPost()`:
    Se encuentra en `BuddyNet.h`, permite al usuario crear una publicación; tiene una complejidad temporal de `O(n log n)` ya que en caso de que el vector de publicaciones esté ordenado por votos, se tendrá que ordenar por fecha, hacer la inserción y volver a ordernar por votos; debido a que se usa un `merge sort` es que se tiene esa complejidad.

 - `gotoSearch()`:
    Se encuentra en `BuddyNet.h`, lleva al usuario a un perfil o una publicación en específico; tiene una complejidad temporal de `O(n)`. Debido a que usa `postExists()` para encontrar la publicación dada tiene esa complejidad.

 - `freeMemory()`:
    Se encuentra en `BuddyNet.h`, libera la memoria usada; tiene una complejidad temporal de `O(n)` ya que itera entre las publicaciones y perfiles una vez.

 - `loadData()`:
    Se encuentra en `BuddyNet.h`, carga todos los datos de la base de datos al programa; tiene una complejidad temporal (simplificada) de `O(n*k log(n))`, ya que desglosándola es `O(P log(P) + C log(P) + C*k log(P) + N log(P) + N*K*C + N*K*log(P) + N + F log(P) + F*K log(P))` debido a las búsquedas realizadas con los nombres de usuario e ID's de publicaciones para obtener los punteros de usuarios y publicaciones respectivamente.

 - `storeData()`:
    Se encuentra en `BuddyNet.h`, guarda todos los datos del programa a la base de datos; tiene una complejidad temporal de `O(n)` ya que itera entre las publicaciones, sus datos y los perfiles una vez.

 - `upvote()`:
    Se encuentra en `Post.h`, le da un voto arriba a una publicación; tiene una complejidad temporal de `O(n)`. Debido a que se modificarían muy poco los votos en una misma ejecución del programa, **sale más barato** hacer una búsqueda lineal para encontrar si se cuentan con votos en la publicación, a tener que hacer un ordenamiento y una búsqueda binaria.

 - `downvote()`:
    Se encuentra en `Post.h`, le da un voto abajo a una publicación; tiene una complejidad temporal de `O(n)`. Debido a que se modificarían muy poco los votos en una misma ejecución del programa, **sale más barato** hacer una búsqueda lineal para encontrar si se cuentan con votos en la publicación, a tener que hacer un ordenamiento y una búsqueda binaria.

 - `erasevote()`:
    Se encuentra en `Post.h`, le borra un voto a una publicación; tiene una complejidad temporal de `O(n)`. Debido a que se modificarían muy poco los votos en una misma ejecución del programa, **sale más barato** hacer una búsqueda lineal para encontrar si se cuentan con votos en la publicación, a tener que hacer un ordenamiento y una búsqueda binaria.

 - `isInList()`:
    Se encuentra en `Profile.h`, regresa el índice de un perfil en un vector; tiene una complejidad temporal de `O(n)`. Debido a los usos que se le da a éste método se prefirió el uso de una búsqueda lineal.

La complejidad temporal final del programa no se puede evaluar debido a que depende de las acciones que decida realizar el usuario, la cantidad de veces que se realizarán los diferentes algoritmos dentro de éste programa. 

En el caso de la complejidad espacial se puede decir que ésta, debido a la manera que está implementada y que para las funciones donde se ocupan vectores siempre se están pasando las referencias de éstos envés de crear copias, solo habría 1 objeto realmente por cada dato, es decir, no habría redundancia de datos, minimizando la memoria usada, haciendo que la memoria tienda a ser de `O(n)`.

### SICT0302: Toma decisiones
La razón por la cuál se ocupaba un algoritmo de ordenamiento es debido a que se ocupaban ordenar las publicaciones para que los usuarios las pudieran visualizar de una mejor manera; y a que se ocupaba verificar si un perfil estaba en algún vector, por lo que para usar un algoritmo de `búsqueda binaria` se ocuparía que dicho vector esté ordenado. Debido a las complejidades que tiene y a su fácil implementación fue que se optó por usar el `Merge Sort`.

Se utilizó el `Stack` ya que se quería tener un registro de las notificaciones de un usuario, y debido a que funcionan con una estructura LIFO(Last in - first out) se escogió esa estructura.

Se utilizó un `Queue` para poder implementar un algoritmo de BFS en un **grafo** para encontrar la red de amigos del usuario, donde se va a limitar a 3 nodos de profundidad, para de esta forma asegurarse que el feed sea cercano al usuario y se fomente la ampliación de su red.

### SICT0303: Implementa acciones científicas
Para poder acceder a los datos del `Stack` se usan la funciones `top()` y `pop()`, las cuales regresan el elemento hasta arriba y eliminan el elemento de hasta arriba respectivamente. Dependiendo de las entradas del usuario se van eliminando y recorriendo la estructura. En el caso del `Queue` es igual, solo que envés de `top()` se usa `front()`.

Para consultar la red de amigos del usuario se usa un algoritmo de `BFS` limitándolo a un máximo de 3 nodos de profundidad.

Se hizo un sistema de lectura/escritura para poder guardar datos, esto se puede entontrar en la parte de abajo del archivo `BuddyNet.h`, en las funciones `loadData()` y `storeData()`, mientras que los datos se guardan en `Database.txt`.