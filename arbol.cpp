#include <vector>
#include <algorithm>
#include <iostream>
#include <string.h>
#include "arbol.h"

using namespace std;

Arista::Arista(int v1, int v2, int peso) {
    vertice1 = v1;
    vertice2 = v2;
    this->peso = peso;
}

int Arista::obtener_vertice1() {
    return vertice1;
}

int Arista::obtener_vertice2() {
    return vertice2;
}

int Arista::obtener_peso() {
    return peso;
}

bool Arista::operator<(const Arista &arista2) const {
    return (peso < arista2.peso);
}




Arbol::Arbol(int cant_lecturas) {
    this->cant_lecturas = cant_lecturas;
}

void Arbol::agregar_arista(int v1, int v2, int peso) {
    Arista arista(v1, v2, peso);
    aristas.push_back(arista);
}

int Arbol::buscar(int *subconjunto, int i) {
    if (subconjunto[i] == -1) {
        return i;
    }
    return buscar(subconjunto, subconjunto[i]);
}

void Arbol::unir_subconjuntos(int *subconjunto, int v1, int v2) {
    int v1_set = buscar(subconjunto, v1);
    int v2_set = buscar(subconjunto, v2);
    subconjunto[v1_set] = v2_set;
}

void Arbol::kruskal() {
    vector<Arista> arbol;
    int tamanio_aristas = aristas.size();

    sort(aristas.begin(), aristas.end());//ordena las aristas por menor peso
    //for(int i = 0; i < tamanio_aristas; i++){
        //cout << aristas[i].obtener_vertice1() << " - " << aristas[i].obtener_vertice2() << " - "<<aristas[i].obtener_peso()<< "\n";
    //}

    int * subconjunto = new int[cant_lecturas];

    //inicializa todos los subconjuntos como conjuntos de un unico elemento
    memset(subconjunto, -1, sizeof(int) * cant_lecturas);

    for(int i = 0; i < tamanio_aristas; i++) {
        int v1 = buscar(subconjunto, aristas[i].obtener_vertice1());
        int v2 = buscar(subconjunto, aristas[i].obtener_vertice2());
        cout << "Compara: "<< v1 << "   -   "<< v2 << "   peso: " <<aristas[i].obtener_peso() <<"\n";

        if(v1 != v2) {
            //si son diferentes es porque no forman un ciclo
            arbol.push_back(aristas[i]);
            unir_subconjuntos(subconjunto, v1, v2);
        }
    }

    int tamanio_arbol = arbol.size();
    int tiempo_lecturas = 0;

    for(int i = 0; i < tamanio_arbol; i++) {
        int v1 = arbol[i].obtener_vertice1();
        int v2 = arbol[i].obtener_vertice2();
        tiempo_lecturas = tiempo_lecturas + arbol[i].obtener_peso();
        cout << "(" << v1 << ", " << v2 << ") = " << arbol[i].obtener_peso() << endl;
    }

    cout << "En total tardaras: " << tiempo_lecturas << " minutos\n";
}

