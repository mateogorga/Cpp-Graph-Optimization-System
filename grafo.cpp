#include "grafo.h"
#include <iomanip>

const int ESPACIO_NOMBRES_FILAS = 25;
const int ESPACIO_COLUMNAS = 15;

void Grafo::actualizar_matriz(long unsigned int tamanio) {
            vector<vector<int>>  matriz_adyacente_anterior = matriz_adyacente;
            vector<vector<int>>  matriz_pesos_anterior = matriz_pesos;
            matriz_adyacente = vector<vector<int>>(tamanio, vector<int>(tamanio, 0));
            matriz_pesos = vector<vector<int>>(tamanio, vector<int>(tamanio, 0));
            for (long unsigned int fila = 0; fila < matriz_adyacente_anterior.size(); fila++) {
                for (long unsigned int columna = 0; columna < matriz_adyacente_anterior.size(); columna++) {
                    matriz_adyacente[fila][columna] = matriz_adyacente_anterior[fila][columna];
                    matriz_pesos[fila][columna] = matriz_pesos_anterior[fila][columna];
                }
            }
}


bool Grafo::encontrar_lectura(string nombre) {
    bool lectura_agregada = false;
    long unsigned int tamanio_vector = nombres_lecturas.size(); 
    long unsigned int i = 0;
    while (!lectura_agregada && i < tamanio_vector) {
        if (nombres_lecturas[i] == nombre)
            lectura_agregada = true;
        i++;
    }
    return lectura_agregada;
}



long unsigned int Grafo::encontrar_posicion_lectura(string nombre) {
    bool lectura_agregada = false;
    long unsigned int tamanio_vector = nombres_lecturas.size(); 
    long unsigned int i = 0;
    while (!lectura_agregada && i < tamanio_vector) {
        if (nombres_lecturas[i] == nombre)
            lectura_agregada = true;
        i++;
    }
    i--; //para empezar del 0
    return i;
}


void Grafo::insertar_lectura(string nombre, string tipo) {
    if (nombres_lecturas.size() == 0) {
        nombres_lecturas.push_back(nombre);
        tipos_lecturas.push_back(tipo);
        actualizar_matriz(nombres_lecturas.size());
    } else if (!encontrar_lectura(nombre)) {
        nombres_lecturas.push_back(nombre);
        tipos_lecturas.push_back(tipo);
        actualizar_matriz(nombres_lecturas.size());
    }
}




void Grafo::eliminar_lectura(string nombre) {
    if (encontrar_lectura(nombre)) {
        long unsigned int posicion = encontrar_posicion_lectura (nombre);
        for (long unsigned int fil = 0; fil < nombres_lecturas.size(); fil++) {
            matriz_adyacente[fil].erase(matriz_adyacente[fil].begin() + posicion);
            matriz_pesos[fil].erase(matriz_pesos[fil].begin() + posicion);
        }
        matriz_adyacente.erase(matriz_adyacente.begin() + posicion);
        matriz_pesos.erase(matriz_pesos.begin() + posicion);
        nombres_lecturas.erase(nombres_lecturas.begin() + posicion);
    }
}


//supongoq eu los nodos o existen o fueron agregados
bool Grafo::buscar_arista (string origen, string destino) {
    long unsigned int posicion_origen = encontrar_posicion_lectura(origen);
    long unsigned int posicion_destino = encontrar_posicion_lectura(destino);
    return matriz_adyacente[posicion_origen][posicion_destino];
}


void Grafo::insertar_arista (string origen, string destino) {
    if (encontrar_lectura(origen) && encontrar_lectura(destino)) {
        long unsigned int posicion_origen = encontrar_posicion_lectura(origen);
        long unsigned int posicion_destino = encontrar_posicion_lectura(destino);
        if (!buscar_arista(origen, destino)) {
            matriz_adyacente[posicion_origen][posicion_destino] = 1;
            matriz_adyacente[posicion_destino][posicion_origen] = 1;
            //linea anterior hace que la matriz se carge simetricamente
            //por ser no dirigido por enunciado       
        }
    }

}


//los pesos van a ser fijos SUPONGO QUE EXISTE ARISTA
//supongo que solo se agraga una vez, sino se pisa
void Grafo::insertar_peso (string origen, string destino, int peso) {
    long unsigned int posicion_origen = encontrar_posicion_lectura(origen);
    long unsigned int posicion_destino = encontrar_posicion_lectura(destino);
    matriz_pesos[posicion_origen][posicion_destino] = peso;
    matriz_pesos[posicion_destino][posicion_origen] = peso;
    //linea anterior hace que la matriz se carge simetricamente
    //por ser no dirigido por enunciado
}   


void Grafo::eliminar_arista (string origen, string destino) {
    if (encontrar_lectura(origen) && encontrar_lectura(destino)) {
        long unsigned int posicion_origen = encontrar_posicion_lectura(origen);
        long unsigned int posicion_destino = encontrar_posicion_lectura(destino);
        if (buscar_arista(origen, destino)) {
            matriz_adyacente[posicion_origen][posicion_destino] = 0;
        }
    }
}


void Grafo::mostrar_grafo() {
    long unsigned int cantidad_lecturas = nombres_lecturas.size();
    cout << endl;
    cout << "ARISTAS" << endl;
    cout<< setw(ESPACIO_NOMBRES_FILAS) << " ";
    for (long unsigned int columna = 0; columna < cantidad_lecturas; columna++) {
        cout << setw(ESPACIO_COLUMNAS)<< nombres_lecturas[columna];
    }
    cout << endl;
    for (long unsigned int fila = 0; fila < cantidad_lecturas; fila++) {
        cout << setw(ESPACIO_NOMBRES_FILAS) << nombres_lecturas[fila];
        for (long unsigned int columna = 0; columna < cantidad_lecturas; columna++) {
            cout << setw(ESPACIO_COLUMNAS) << matriz_adyacente[fila][columna];
        }
        cout << endl;
    }
    cout << endl;
    cout << endl;
    cout << "PESOS" << endl;
    cout<< setw(ESPACIO_NOMBRES_FILAS) << " ";;
    for (long unsigned int columna = 0; columna < cantidad_lecturas; columna++) {
        cout << setw(ESPACIO_COLUMNAS) << nombres_lecturas[columna];
    }
    cout << endl;
    for (long unsigned int fila = 0; fila < cantidad_lecturas; fila++) {
        cout << setw(ESPACIO_NOMBRES_FILAS) << nombres_lecturas[fila];
        for (long unsigned int columna = 0; columna < cantidad_lecturas; columna++) {
            cout << setw(ESPACIO_COLUMNAS)<< matriz_pesos[fila][columna];
        }
        cout << endl;
    }
}


int calcular_siesta(string nodo_a, string nodo_b) {
    //IMPLEMENTAR MATRIZ DINAMICA?
}


void Grafo::cargar_grafo(Lista_lecturas& ll){
    int cantidad_lecturas_en_lista = ll.obtener_cantidad();
    for (int i_lectura_lista = 0; i_lectura_lista < cantidad_lecturas_en_lista; i_lectura_lista++) {
        //inserto el nodo de la lista al grafo
        insertar_lectura(ll.consulta(i_lectura_lista)->obtener_titulo(),
                         ll.consulta(i_lectura_lista)->obtener_tipo());

        //calculo la cantidad de elementos en el vector del grafo
        size_t aux = nombres_lecturas.size();
        int cantidad_lecturas_en_vector = (int)aux;

        //guardo el tipo y nombre de lectura que agregue recien
        string nombre_nodo_nuevo = ll.consulta(i_lectura_lista)->obtener_titulo();
        string tipo_nodo_nuevo = ll.consulta(i_lectura_lista)->obtener_tipo();
        
        for (int i_lectura_vector = 0; i_lectura_vector < cantidad_lecturas_en_vector ; i_lectura_vector++) {

            //aca ya trabajo para la matriz
            //busco para cada elemtno del vector del grafo, su tipo y su nombre
            string nombre_nodo_viejo = ll.consulta(i_lectura_vector)->obtener_titulo();
            string tipo_nodo_viejo = ll.consulta(i_lectura_vector)->obtener_tipo();

            //mando tipos de nodo viejo y nuevo a una funcion que me devuelva el valor de la siesta
            int siesta = calcular_siesta(tipo_nodo_viejo, tipo_nodo_nuevo);

            //inserto la arista
            //inserto el peso de la misma
            insertar_arista(nombre_nodo_nuevo, nombre_nodo_viejo);
            insertar_peso(nombre_nodo_nuevo, nombre_nodo_viejo, siesta);
        } 
    }
}
