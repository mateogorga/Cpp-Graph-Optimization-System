#ifndef GRAFO_H
#define GRAFO_H

#include <vector>
#include <string>
#include <iostream>
#include "lista_lecturas.h"

using namespace std;

class Grafo {
    private:

        vector<string> nombres_lecturas;
        vector<string> tipos_lecturas;
        //voy a hacer un vector de strings donde guardo el tipo de lectura en la misma
        //posicion que su nombre. vere si lo hago matriz despues
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
        void insertar_lectura(string nombre, string tipo);

        
        //PRE:
        //POST:
        void eliminar_lectura(string nombre);


        //PRE:
        //POST:
        void insertar_arista (string origen, string destino);


        //PRE:
        //POST:
        void eliminar_arista (string origen, string destino);



        //PRE:
        //POST:
        void insertar_peso (string origen, string destino, int peso);


        //PRE:
        //POST:
        void mostrar_grafo();


        void cargar_grafo(Lista_lecturas& ll);

    };

    #endif //GRAFO_H