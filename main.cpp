#include "cuento.h"
#include "escritor.h"
#include "historica.h"
#include "poema.h"
#include "lista_escritores.h"
#include "novela.h"
#include "lectura.h"
#include "menu.h"
#include <iostream>
#include <string>
#include "parser_lecturas.h"
#include "parser_escritores.h"
#include "grafo.h"
#include "arbol.h"

const string ARCHIVO_LECTURAS = "lecturas.txt";
const string ARCHIVO_ESCRITORES = "escritores.txt";
using namespace std;

int main() {
    /*
    Menu menu;

    Parser_escritores parser_escritores = Parser_escritores();
    Hash_escritores t_escritores = parser_escritores.cargar_lista_escritores(ARCHIVO_ESCRITORES);
    Parser_lecturas parser_lecturas = Parser_lecturas();
    Lista_lecturas l_lecturas = parser_lecturas.cargar_lista_lecturas(ARCHIVO_LECTURAS, t_escritores);

    Lista_lecturas lista_aux;
    Cola cola;
    Grafo grafo;
    grafo.cargar_grafo(l_lecturas);
     */
    Arbol g(400);
    g.agregar_arista(100, 200, 0);
    g.agregar_arista(100, 100, 1);
    g.agregar_arista(100, 400, 20);
    g.agregar_arista(100, 300, 5);
    g.agregar_arista(200, 100, 0);
    g.agregar_arista(200, 300, 10);
    g.agregar_arista(200, 400, 15);
    g.agregar_arista(200, 100, 0);
    g.agregar_arista(100, 100, 1);
    g.agregar_arista(100, 300, 5);
    g.agregar_arista(100, 400 ,20);
    g.agregar_arista(100, 200, 0);
    g.agregar_arista(400, 100, 20);
    g.agregar_arista(400, 100, 20);
    g.agregar_arista(400, 300, 60);
    g.agregar_arista(400, 200, 15);
    g.agregar_arista(300, 100, 5);
    g.agregar_arista(300, 200 ,10);
    g.agregar_arista(300, 100, 5);
    g.agregar_arista(300, 400, 60);


    g.kruskal();


    //menu.mensaje_inicial();
    //menu.ejecutar_menu(menu, l_lecturas, t_escritores, cola, lista_aux, grafo, arbol);


    return 0;
}


/*
 * #include <vector>
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




Grafo::Grafo(int cant_lecturas) {
    this->cant_lecturas = cant_lecturas;
}

void Grafo::agregar_arista(int v1, int v2, int peso) {
    Arista arista(v1, v2, peso);
    aristas.push_back(arista);
}

int Grafo::buscar(int *subconjunto, int i) {
    if (subconjunto[i] == -1) {
        return i;
    }
    return buscar(subconjunto, subconjunto[i]);
}

void Grafo::unir_subconjuntos(int *subconjunto, int v1, int v2) {
    int v1_set = buscar(subconjunto, v1);
    int v2_set = buscar(subconjunto, v2);
    subconjunto[v1_set] = v2_set;
}

void Grafo::kruskal() {
    vector<Arista> arbol;
    int tamanio_aristas = aristas.size();

    sort(aristas.begin(), aristas.end());//ordena las aristas por menor peso

    int * subconjunto = new int[cant_lecturas];

    //inicializa todos los subconjuntos como conjuntos de un unico elemento
    memset(subconjunto, -1, sizeof(int) * cant_lecturas);

    for(int i = 0; i < tamanio_aristas; i++) {
        int v1 = buscar(subconjunto, aristas[i].obtener_vertice1());
        int v2 = buscar(subconjunto, aristas[i].obtener_vertice2());

        if(v1 != v2) {
            //si son diferentes es porque no forman un ciclo
            arbol.push_back(aristas[i]);
            unir_subconjuntos(subconjunto, v1, v2);
        }
    }

    int tamanio_arbol = arbol.size();
    int tiempo_lecturas = 0;

    for(int i = 0; i < tamanio_arbol; i++) {
        char v1 = 'A' + arbol[i].obtener_vertice1();
        char v2 = 'A' + arbol[i].obtener_vertice2();
        tiempo_lecturas = tiempo_lecturas + arbol[i].obtener_peso();
        cout << "(" << v1 << ", " << v2 << ") = " << arbol[i].obtener_peso() << endl;
    }

    cout << "En total tardaras: " << tiempo_lecturas << " minutos\n";
}



 Grafo g(7);

    g.agregar_arista(0, 1, 7);
    g.agregar_arista(0, 3, 5);
    g.agregar_arista(1, 2, 8);
    g.agregar_arista(1, 3, 9);
    g.agregar_arista(1, 4, 7);
    g.agregar_arista(2, 4, 5);
    g.agregar_arista(3, 4, 15);
    g.agregar_arista(3, 5, 6);
    g.agregar_arista(4, 5, 8);
    g.agregar_arista(4, 6, 9);
    g.agregar_arista(5, 6 ,11);

    g.kruskal();
 */
