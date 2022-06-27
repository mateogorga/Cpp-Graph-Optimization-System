#include <vector>
#include <string>
#include <iostream>
using namespace std;

class Grafo {
    private:

        /*
         *      0   1   2   3   4   5
         * 0    -1  10  10  10  15
         * 1    10          15  30
         * 2    10          5   5
         * 3                -1   0
         * 4                0   -1
         * 5                30  10
         */

        /*3-4-2-5-0-1*/
        /*BUSCAR EL VALOR CERO DENTRO DE LA MATRIZ*/
        /*VECTOR STRING PARA CARGAR TITULOS*/
        /*VECTOR INT PARA CARGAR SIESTAS*/
        /*VECTOR INT PARA TIEMPOS DE LECTURA*/

        /*BUSCAR EL SIGUIENTE VALOR MAYOR AL ANTERIOR*/


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

        vector<string> nombres_lecturas;
        vector<vector<int>> matriz_adyacente;
        vector<vector<int>> matriz_pesos;
    
        //PRE:
        //POST:
        void insertar_lectura(string nombre, char tipo);


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