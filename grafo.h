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

        //PRE: El tamanio no puede ser negativo.
        //POST: Actualiza la matriz de adyacencia.
        void actualizar_matriz(long unsigned int tamanio);


        //PRE: Recibe string para buscar en el vector de lecturas del grafo.
        //POST: Retorna true si la lectura se encuentra en el grafo, de lo contrario
        //retorna false.
        bool encontrar_lectura(string nombre);


        //PRE: La lectura debe existir en el vector de lecturas del grafo.
        //POST: Devuelve la posicion donde se encuentra la lectura.
        long unsigned int encontrar_posicion_lectura(string nombre);


        //PRE: Las lecturas deben estar cargadas en el grafo
        //POST: Retorna true si existe arista entre las lecturas, de lo contrario
        //retorna false.
        bool buscar_arista (string origen, string destino);

         
    public:

        //PRE:
        //POST: Genera un objeto grafo vacio.
        Grafo();
        vector<vector<int>> obtener_adyacencia();
        vector<vector<int>> obtener_pesos();
    
        //PRE: El grafo debe existir, el tipo de lectura debe pertenecer a las 
        //contempladas por el grafo.
        //POST: Si la lectura ya se encontraba en el grafo no hace nada, de lo 
        //contrario la agrega y carga su peso.
        void insertar_lectura(string nombre, string tipo);

        
        //PRE:
        //POST: Si la lectura se encuentra en el grafo la elimina.
        void eliminar_lectura(string nombre);


        //PRE:
        //POST: Si las lecturas se encuentran en el grafo y son distintas, carga 
        //una arista entre ellas.
        void insertar_arista(string origen, string destino);


        //PRE: Debe existir arista entre las lecturas.
        //POST: Agrega la informacion del peso de la arista al grafo. Si la arista ya
        //tenia un peso cargado, este se sobre-escribe.
        void insertar_peso(string origen, string destino, int peso);


        //PRE:
        //POST: Si las aristas entre lecturas existen las elimina, de lo contrario no
        //hace nada.
        void eliminar_arista(string origen, string destino);


        //PRE:
        //POST:
        void mostrar_grafo();


        void cargar_grafo(Lista_lecturas& ll);


        void cargar_grafo(Lectura* lectura_a_insertar);

    };

    #endif //GRAFO_H