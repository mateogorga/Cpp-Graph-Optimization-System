Ya encontre la idea: 

En el grafo vamos a agregar dos atributos.
El primero es un "vector<int> arista", 
un vector de tres posiciones. Las primeras dos corresponden a las 
posiciones en el vector de strings llamado "nombres_lecturas", que significan en la arista sus
vertices.

El segundo es un "vector<vector<int>> arbol", una matriz 3xn, donde n es la cantidad de aristas.
Es decir, un vector de aristas.
Ordenamos las aristas dentro de esa matriz segun su tercera posicion (el peso).
Es lo que ya esta haciendo el algoritmo de mateo, pero antes lo hacia con objetos arista 
enves de vectores que seria una gran idea si fueramos a almacenar distintos tipos 

Con eso llegaría a la linea 62 que es donde se ejecuta el sort() de kruskal. Despues no entiendo
que hace el código. PERO ya se tendrían todos los elementos como para que sea un
metodo del grafo.



Corregir nombres de variables y completar pres y post
¿Uso el nombre "peso" o "siesta" para referirme al peso de las aristas?


Bugs: Al eliminar todas las lecturas no puedo seguir con el programa
Ver que pasa con el grafo al eliminar todas las lecturas
