#include <stdio.h>
#include <algorithm>
#include <cstring>
#include "arbol.h"


Arbol::Arbol() {}


Arbol::Arbol(int cant_lecturas) {

    this->lecturas = cant_lecturas;
    this->ady = vector<vector<int>>(cant_lecturas);

    for (int i = 0; i < cant_lecturas; i++)
        ady[i] = vector<int>(cant_lecturas, INF);
}


void Arbol::cargar_arbol(Lista_lecturas ll, Grafo grafo) {
    int cant_lecturas = ll.obtener_cantidad();

    /*MATRIZ[CANT_LECTURA, CANT_LECTURA]*/
    for(int i = 0; i < cant_lecturas; i++) {
        string titulo = ll.consulta(i)->obtener_titulo();
        char tipo = ll.consulta(i)->obtener_tipo();
        grafo.insertar_lectura(titulo,tipo);


        if(i > 1) { //inserta la arista y el peso
            string titulo_ant = ll.consulta(i-1)->obtener_titulo();
            char tipo_ant = ll.consulta(i-1)->obtener_tipo();

            grafo.insertar_arista(titulo_ant, titulo);

            if (tipo == 'C') {
                if (tipo_ant == 'N') {
                    /*siesta = 10;*/
                    grafo.insertar_peso(titulo_ant, titulo, 10);
                }
                if (tipo_ant == 'H') {
                    grafo.insertar_peso(titulo_ant, titulo, 15);
                }
                if (tipo_ant == 'P') {
                    grafo.insertar_peso(titulo_ant, titulo, 0);
                }
                if (tipo_ant == 'C') {
                    grafo.insertar_peso(titulo_ant, titulo, 8);
                }}

            if (tipo == 'P') {
                if (tipo_ant == 'N') {
                    grafo.insertar_peso(titulo_ant, titulo, 5);
                }
                if (tipo_ant == 'H') {
                    grafo.insertar_peso(titulo_ant, titulo, 20);
                }
                if (tipo_ant == 'C') {
                    grafo.insertar_peso(titulo_ant, titulo, 0);
                }
                if (tipo_ant == 'P') {
                    grafo.insertar_peso(titulo_ant, titulo, 1);
                }}

            if (tipo == 'N') {
                if (tipo_ant == 'N') {
                    grafo.insertar_peso(titulo_ant, titulo, 30);
                }
                if (tipo_ant == 'H') {
                    grafo.insertar_peso(titulo_ant, titulo, 60);
                }
                if (tipo_ant == 'C') {
                    grafo.insertar_peso(titulo_ant, titulo, 10);
                }
                if (tipo_ant == 'P') {
                    grafo.insertar_peso(titulo_ant, titulo, 5);
                }}

            if (tipo == 'H') {
                if (tipo_ant == 'N') {
                    grafo.insertar_peso(titulo_ant, titulo, 60);
                }
                if (tipo_ant == 'H') {
                    grafo.insertar_peso(titulo_ant, titulo, 80);
                }
                if (tipo_ant == 'C') {
                    grafo.insertar_peso(titulo_ant, titulo, 15);
                }
                if (tipo_ant == 'P') {
                    grafo.insertar_peso(titulo_ant, titulo, 20);
                }}

            /*MATRIZ[I,I]=siesta;*/
        }
    }
    ordenar_arbol(grafo);
}


void Arbol::ordenar_arbol(Grafo grafo, int cn) {
    int nodoA;
    int nodoB;
    int arcos = 1;
    vector< vector<int> > adyacencia = grafo.matriz_adyacente;
    vector< vector<int> > arbol();
    vector<int> pertenece(cn); // indica a que árbol pertenece el nodo

    for(int i = 0; i < cn; i++){
        arbol[i] = vector<int> (cn, 0);
        pertenece[i] = i;
    }

    while(arcos < cn){
        // Encontrar  el arco mínimo que no forma ciclo y guardar los nodos y la distancia.
        int min = INF;
        for(int i = 0; i < cn; i++)
            for(int j = 0; j < cn; j++)
                if(min > adyacencia[i][j] && adyacencia[i][j]!=0 && pertenece[i] != pertenece[j]){
                    min = adyacencia[i][j];
                    nodoA = i;
                    nodoB = j;
                }

        // Si los nodos no pertenecen al mismo árbol agrego el arco al árbol mínimo.
        if(pertenece[nodoA] != pertenece[nodoB]){
            arbol[nodoA][nodoB] = min;
            arbol[nodoB][nodoA] = min;

            // Todos los nodos del árbol del nodoB ahora pertenecen al árbol del nodoA.
            int temp = pertenece[nodoB];
            pertenece[nodoB] = pertenece[nodoA];
            for(int k = 0; k < cn; k++)
                if(pertenece[k] == temp)
                    pertenece[k] = pertenece[nodoA];

            arcos++;
        }
    }
}
