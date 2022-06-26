#include "grafo.h"

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


void Grafo::insertar_lectura(string nombre) {
    if (nombres_lecturas.size() == 0) {
        nombres_lecturas.push_back(nombre);
        actualizar_matriz(nombres_lecturas.size());
    } else if (!encontrar_lectura(nombre)) {
        nombres_lecturas.push_back(nombre);
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
    if (!encontrar_lectura(origen))
        insertar_lectura(origen);
    if (!encontrar_lectura(destino))
        insertar_lectura(destino);
    long unsigned int posicion_origen = encontrar_posicion_lectura(origen);
    long unsigned int posicion_destino = encontrar_posicion_lectura(destino);
    if (!buscar_arista(origen, destino)) {
        matriz_adyacente[posicion_origen][posicion_destino] = 1;
        matriz_adyacente[posicion_destino][posicion_origen] = 1;
        //linea anterior hace que la matriz se carge simetricamente
        //por ser no dirigido por enunciado       
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
    cout << "                  ";
    for (long unsigned int columna = 0; columna < cantidad_lecturas; columna++) {
        cout << "     " << nombres_lecturas[columna];
    }
    cout << endl;
    for (long unsigned int fila = 0; fila < cantidad_lecturas; fila++) {
        cout << "     " << nombres_lecturas[fila];
        cout << "      ";
        for (long unsigned int columna = 0; columna < cantidad_lecturas; columna++) {
            cout << "     " << matriz_adyacente[fila][columna];
        }
        cout << endl;
    }
    cout << endl;
    cout << endl;
    cout << "PESOS" << endl;
    cout << "                  ";
    for (long unsigned int columna = 0; columna < cantidad_lecturas; columna++) {
        cout << "     " << nombres_lecturas[columna];
    }
    cout << endl;
    for (long unsigned int fila = 0; fila < cantidad_lecturas; fila++) {
        cout << "     " << nombres_lecturas[fila];
        cout << "      ";
        for (long unsigned int columna = 0; columna < cantidad_lecturas; columna++) {
            cout << "     " << matriz_pesos[fila][columna];
        }
        cout << endl;
    }
}
