# tp3
Mateo:
Impresion de texto que avisa que no se leyeron los archivos
Arbol expansion minima

--asegurarme de copiar bien la matriz de adyacencia y de pesos
--imprimirla
kruskal esas matrices--> se va guardando en la matriz arbol 
imprimir matriz arbol


Marco:

Ya encontre la idea: la arista es un vector de tres posiciones.
Las primeras dos corresponden a las posiciones de las lecturas 
del vector de strings nombres lecturas, que significan en la arista sus
vertices.

La matriz arbol es una matriz 3xn, donde n es la cantidad de aristas.
Ordenamos las aristas dentro de esa matriz segun su tercera posicion (el peso).
Es lo que ya esta haciendo el algoritmo de mateo, pero con objetos arista enves de vectores.

Con eso llegaría a la linea 62 que donde se ejecuta el sort de kruskal. Despues no entiendo
que hace el código. PERO ya se tendrían todos los elementos como para que sea un
metodo del grafo.

    Finalmente modularizar, corregir nombres de variables y completar pres y post
    ¿Uso el nombre "peso" o "siesta" para referirme al peso de las aristas?


Bugs: Al eliminar todas las lecturas no puedo seguir ocn el programa
Ver que pasa con el grafo al eliminar todas las lecturas
