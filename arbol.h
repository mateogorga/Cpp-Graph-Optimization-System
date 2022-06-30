
#ifndef TP3_MAIN_ARBOL_H
#define TP3_MAIN_ARBOL_H
#include <vector>
#include <algorithm>
#include <iostream>
#include <string.h>

using namespace std;

class Arista {
    int vertice1, vertice2, peso;

public:
    Arista(int v1, int v2, int peso);
    int obtener_vertice1();
    int obtener_vertice2();
    int obtener_peso();
    bool operator < (const Arista& arista2) const;
};


class Arbol {
    int cant_lecturas;
    vector<Arista> aristas;

public:
<<<<<<< HEAD
    Arbol();

    vector<vector<int>> kruskal();
    void cargar_arbol(Lista_lecturas ll, Grafo grafo);
    void ordenar_arbol(Grafo grafo, int cant_lecturas);
private:
    const int INF = -1;
    int lecturas; //cantidad de lecturas
    vector< vector<int> > ady; //matriz de adyacencia
=======
    Arbol(int cant_lecturas);
    void agregar_arista(int v1, int v2, int peso);
    int buscar(int subconjunto[], int i);//busca el subconjunto de un elemento "i"
    void unir_subconjuntos(int subconjunto[], int v1, int v2);
    void kruskal();
>>>>>>> 69da520a41c9ec7f24d7aed18ceffeb3b91b57da
};

#endif //TP3_MAIN_ARBOL_H
