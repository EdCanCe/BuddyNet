# BuddyNet

BuddyNet es un proyecto realizado en la clase TC1031. Es una red social local donde se podrán ver publicaciones, filtrlas, darles votos(ya sean positivos o negativos); Se podrá darles follow a otros usuarios y dependiendo de eso cambiará el feed, ya que solo saldrán publicaciones de amigos, de amigos de amigos, y de los amigos de ellos (hasta 3 conexiones).

Por el momento solo cuenta con la opción de crear y acceder a una cuenta, ver, ordenar y crear publicaciones.

Al ser solo el primer avance, faltan refinar partes. Por ejemplo, en un futuro implementar un algoritmo de camino más corto en grafos para ver la "distancia" que tienen 2 perfiles entre sí, para así verificar si mostrar sus publicaciones o no.
De la misma manera faltaría implementar un sistema para leer y escribir los datos en archivos, terminar la documentación, permitir realizar votos y comentarios, etc.

### Índice:
- [BuddyNet](#buddynet)
- [Índice](#índice)
- [Competencias](#competencias)
    - [SICT0301](#sict0301-evalúa-los-componentes)
    - [SICT0301](#sict0302-toma-decisiones)

## Competencias:

### SICT0301: Evalúa los componentes 
Solo se usa un algoritmo de ordenamiento, se usa un `Merge Sort` pero toma el nombre de `orderByVotes()` dentro de `BuddyNet.h`. Debido a que es un `Merge Sort` tiene una complejidad `O(n log n)`.

### SICT0302: Toma decisiones
Como se mencionó anteriormente, se usó un `Merge Sort` para poder ordenar las publicaciones por medio de sus votaciones. Se usó este algoritmo debido a su fácil implementación y a su rapidez.