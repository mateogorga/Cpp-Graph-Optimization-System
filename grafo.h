#ifndef GRAFO_H
#define GRAFO_H

#include <vector>
#include <string>
#include <iostream>
#include "lista_lecturas.h"
#include "arista.h"

using namespace std;

class Grafo {

    private:
    
        vector<string> nombres_lecturas;
        vector<string> tipos_lecturas;
        //GUARDAR LOS ENTEROS DE DURACIOS DE LECTURAS <== vector<int> minutos_lecura;
        //[0, 1, 1,1,] leida, no leida <== vector<int> lectura_leida;  empezar en 0
        vector<vector<int>> matriz_adyacente;
        vector<vector<int>> matriz_pesos;
        vector<Arista> aristas;
        
        //PRE: Recibe un parametro size_t de valor n.
        //POST: Retorna el mismo valor pero de tipo int.
        int castear_a_int (size_t n);

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


        //PRE: Recibe dos tipos de lecturas que se encuentren agrgadas como constantes al
        //grafo
        //POST: Retorna el valor que corresponde a la arista entre dos lecturas de ese tipo.
        int calcular_peso(string tipo_nodo_a, string tipo_nodo_b);


         
    public:

        //PRE:
        //POST: Genera un objeto grafo vacio.
        Grafo();
        vector<vector<int>> obtener_adyacencia();
        vector<vector<int>> obtener_pesos();
        vector<string> obtener_nombres_lecturas();
        vector<string> obtener_tipos_lecturas();
        vector<Arista> obtener_vector_aristas();

        //PRE: El grafo debe existir, el tipo de lectura debe pertenecer a las 
        //contempladas por el grafo.
        //POST: Si la lectura ya se encontraba en el grafo no hace nada, de lo 
        //contrario la agregasu matriz de adyacencia.
        void insertar_lectura(string nombre, string tipo);

        
        //PRE:
        //POST: Si la lectura se encuentra en el grafo la elimina y actualiza sus matrices.
        void eliminar_lectura(string nombre);


        //PRE:
        //POST: Si las lecturas se encuentran en el grafo y son distintas, carga 
        //una arista entre ellas (carga un uno en su matriz de adyacencia)
        void insertar_arista(string origen, string destino);


        //PRE: Debe existir arista entre las lecturas.
        //POST: Agrega la informacion del peso de la arista al grafo. Si la arista ya
        //tenia un peso cargado, este se sobre-escribe.
        void insertar_peso(string origen, string destino, int peso);


        //PRE:
        //POST: Si las aristas entre lecturas existen las elimina, (cero en su matriz de
        //adyacencia) de lo contrario no hace nada.
        void eliminar_arista(string origen, string destino);


        //PRE:
        //POST: Imprime por consola las matrices de adyacencia del grafo. Primero la de
        //aristas, luego la de sus pesos. Ambas matrices acompañadas por los nombres de
        //las lecturas.
        void mostrar_grafo();


        //PRE: El grafo debe existir, puede recibir tanto una lista de lecturas como un punter
        // a una lectura en particular.
        //POST: Si recibe una lista, la recorre y carga el grafo con la informacion pertinante
        //de todas las lecturas de la lista. Si recibe solo el puntero a la lectura, carga su 
        //informacion pertinente al grafo.
        void cargar_grafo(Lista_lecturas& ll);


        //PRE:El grafo debe existir, puede recibir tanto una lista de lecturas como un punter
        // a una lectura en particular.
        //POST: Si recibe una lista, la recorre y carga el grafo con la informacion pertinante
        //de todas las lecturas de la lista. Si recibe solo el puntero a la lectura, carga su 
        //informacion pertinente al grafo.
        void cargar_grafo(Lectura* lectura_a_insertar);



            
        void agregar_arista(int v1, int v2, int peso);
        void sacar_arista(int vertice_a_remover);
        int buscar(int subconjunto[], int i);//busca el subconjunto de un elemento "i"
        void unir_subconjuntos(int subconjunto[], int v1, int v2);
        void kruskal();
};

#endif //GRAFO_H