#ifndef GRAFO_H
#define GRAFO_H


#include <vector>
#include <string>
#include <iostream>
using namespace std;

class Grafo {
    private:

        vector<string> nombres_lecturas;
        vector<vector<int>> matriz_adyacente;
        vector<vector<int>> matriz_pesos;


        //PRE:
        //POST:
        void actualizar_matriz(long unsigned int tamanio);


        //PRE:
        //POST:
        bool encontrar_lectura(string nombre);


        //PRE:
        //POST:
        long unsigned int encontrar_posicion_lectura(string nombre);


        //PRE:
        //POST:
        bool buscar_arista (string origen, string destino);

         
    public:
    
        //PRE:
        //POST:
        void insertar_lectura(string nombre);


        //PRE:
        //POST:
        void eliminar_lectura(string nombre);


        //PRE:
        //POST:
        void insertar_arista (string origen, string destino);


        //PRE:
        //POST:
        void insertar_peso (string origen, string destino, int peso);


        //PRE:
        //POST:
        void eliminar_arista (string origen, string destino);


        //PRE:
        //POST:
        void mostrar_grafo();

    };

    #endif //GRAFO_H