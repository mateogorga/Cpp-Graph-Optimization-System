#ifndef TP3_MAIN_ARBOL_H
#define TP3_MAIN_ARBOL_H
#include "lista_lecturas.h"
#include "grafo.h"
#include <vector>

using namespace std;
class Arbol {
public:
    Arbol();
    Arbol(int cant_lecturas);
    //vector<vector<int>> kruskal();
    void cargar_arbol(Lista_lecturas ll, Grafo grafo);
    void ordenar_arbol(Grafo& grafo, int cant_lecturas);
private:
    const int INF = -1;
    int lecturas; //cantidad de lecturas
    vector <vector<int>> ady; //matriz de adyacencia
};

#endif //TP3_MAIN_ARBOL_H