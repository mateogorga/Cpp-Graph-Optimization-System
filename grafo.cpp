#include "grafo.h"
#include <iomanip>

const int ESPACIO_NOMBRES_FILAS = 25;
const int ESPACIO_COLUMNAS = 15;

const int CUENTO_A_NOVELA = 10;
const int CUENTO_A_NOVELA_HISTORICA = 15;
const int CUENTO_A_POEMA = 0;
const int CUENTO_A_CUENTO = 8;
const int POEMA_A_NOVELA = 5;
const int POEMA_A_NOVELA_HISTORICA = 20;
const int POEMA_A_POEMA = 1;
const int NOVELA_A_NOVELA = 30;
const int NOVELA_A_NOVELA_HISTORICA = 60;
const int NOVELA_HISORICA_A_NOVELA_HISORICA = 80;

const int NO_LEIDA = 0;
const int LEIDA = 1;

Grafo::Grafo() {
}
    
int Grafo::castear_a_int(size_t n) {
    int int_n = (int)n;
    return int_n;
}


void Grafo::actualizar_matriz(long unsigned int tamanio) {
            vector<vector<int>>  matriz_adyacente_anterior = matriz_adyacente;
            vector<vector<int>>  matriz_pesos_anterior = matriz_pesos;
            matriz_adyacente = vector<vector<int>>(tamanio, vector<int>(tamanio, 0));
            matriz_pesos = vector<vector<int>>(tamanio, vector<int>(tamanio, 888));
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


void Grafo::insertar_lectura(string nombre, string tipo, int minutos) {
    if (nombres_lecturas.size() == 0) {
        nombres_lecturas.push_back(nombre);
        tipos_lecturas.push_back(tipo);
        minutos_lecturas.push_back(minutos);
        
        actualizar_matriz(nombres_lecturas.size());
    } else if (!encontrar_lectura(nombre)) {
        nombres_lecturas.push_back(nombre);
        tipos_lecturas.push_back(tipo);
        minutos_lecturas.push_back(minutos);     
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
        minutos_lecturas.erase(minutos_lecturas.begin() + posicion);
        //uso begin + posicion para pasarle un iterador a erase()
        sacar_arista(castear_a_int(posicion));
    }
}



bool Grafo::buscar_arista (string origen, string destino) {
    long unsigned int posicion_origen = encontrar_posicion_lectura(origen);
    long unsigned int posicion_destino = encontrar_posicion_lectura(destino);
    return matriz_adyacente[posicion_origen][posicion_destino];
}


void Grafo::insertar_arista (string origen, string destino) {
    if ((encontrar_lectura(origen) && encontrar_lectura(destino)) && (origen != destino)) {
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



void Grafo::insertar_peso (string origen, string destino, int peso) {
    if (buscar_arista(origen, destino)) {
    long unsigned int posicion_origen = encontrar_posicion_lectura(origen);
    long unsigned int posicion_destino = encontrar_posicion_lectura(destino);
    matriz_pesos[posicion_origen][posicion_destino] = peso;
    matriz_pesos[posicion_destino][posicion_origen] = peso;
    //linea anterior hace que la matriz se carge simetricamente
    //por ser no dirigido por enunciado

    int v1 = castear_a_int(posicion_origen);
    int v2 = castear_a_int(posicion_destino);

    agregar_arista(v1, v2, peso);

    }
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


int Grafo::calcular_peso(string tipo_nodo_a, string tipo_nodo_b) {
    int siesta;
    if (tipo_nodo_a == tipo_nodo_b) {
        if (tipo_nodo_a == "Cuento") {
            siesta = CUENTO_A_CUENTO;
        } else if (tipo_nodo_a == "Poema") {
            siesta = POEMA_A_POEMA;
        } else if (tipo_nodo_a == "Novela") {
            siesta = NOVELA_A_NOVELA;
        } else if (tipo_nodo_a == "Novela Historica") {
            siesta = NOVELA_HISORICA_A_NOVELA_HISORICA;
        }
    //se supone que no son el mismo, porque no entro en el if de arriba
    } else if ((tipo_nodo_a == "Cuento" || tipo_nodo_b == "Cuento") && 
    (tipo_nodo_a == "Novela" || tipo_nodo_b == "Novela")) {
        siesta = CUENTO_A_NOVELA;

    } else if ((tipo_nodo_a == "Cuento" || tipo_nodo_b == "Cuento") && 
    (tipo_nodo_a == "Novela Historica" || tipo_nodo_b == "Novela Historica")) {
        siesta = CUENTO_A_NOVELA_HISTORICA;

    } else if ((tipo_nodo_a == "Cuento" || tipo_nodo_b == "Cuento") && 
    (tipo_nodo_a == "Poema" || tipo_nodo_b == "Poema")) {
        siesta = CUENTO_A_POEMA;

    } else if ((tipo_nodo_a == "Novela" || tipo_nodo_b == "Novela") && 
    (tipo_nodo_a == "Poema" || tipo_nodo_b == "Poema")) {
        siesta = POEMA_A_NOVELA;

    } else if ((tipo_nodo_a == "Novela Historica" || tipo_nodo_b == "Novela Historica")
     && (tipo_nodo_a == "Poema" || tipo_nodo_b == "Poema")) {
        siesta = POEMA_A_NOVELA_HISTORICA;

    } else if ((tipo_nodo_a == "Novela" || tipo_nodo_b == "Novela") &&
     (tipo_nodo_a == "Novela Historica" || tipo_nodo_b == "Novela Historica")) {
        siesta = NOVELA_A_NOVELA_HISTORICA;
    }
    return siesta;
}


void Grafo::cargar_grafo(Lectura* lectura_a_insertar) {
    string nombre_nodo_nuevo = lectura_a_insertar->obtener_titulo();
    string tipo_nodo_nuevo = lectura_a_insertar->obtener_tipo();
    int minutos_nodo_nuevo = lectura_a_insertar->obtener_minutos();
    insertar_lectura(nombre_nodo_nuevo, tipo_nodo_nuevo, minutos_nodo_nuevo);

    int cantidad_lecturas_en_vector = castear_a_int(nombres_lecturas.size());

    for (int i_lectura_vector = 0; i_lectura_vector < cantidad_lecturas_en_vector;
         i_lectura_vector++) {
        string nombre_nodo_viejo = nombres_lecturas[i_lectura_vector];
        string tipo_nodo_viejo = tipos_lecturas[i_lectura_vector];
        int siesta = calcular_peso(tipo_nodo_viejo, tipo_nodo_nuevo);
        insertar_arista(nombre_nodo_nuevo, nombre_nodo_viejo);
        insertar_peso(nombre_nodo_nuevo, nombre_nodo_viejo, siesta);
    } 
}


void Grafo::cargar_grafo(Lista_lecturas& ll) {
    int cantidad_lecturas_en_lista = ll.obtener_cantidad();

    cantidad_lecturas_en_lista++;

    for (int i_lectura_lista = 0; i_lectura_lista < cantidad_lecturas_en_lista;
         i_lectura_lista++) {
        Lectura* lectura_a_insertar = ll.consulta(i_lectura_lista);
        cargar_grafo(lectura_a_insertar);
    }
}

void Grafo::mostar_arbol_expansion_minima(vector<Arista> arista){
    int cantidad_aristas = castear_a_int(arista.size());
    Grafo arbol_minimo;

    //cantidad_aristas++;

    for (int i = 0; i < cantidad_aristas; i++) {
        int n_vertice_origen = arista[i].obtener_vertice1();
        int n_vertice_destino = arista[i].obtener_vertice2();
        int peso = arista[i].obtener_peso();

        arbol_minimo.insertar_lectura(nombres_lecturas[n_vertice_origen], 
                                      tipos_lecturas[n_vertice_origen], 
                                      minutos_lecturas[n_vertice_origen]);

        arbol_minimo.insertar_lectura(nombres_lecturas[n_vertice_destino], 
                                      tipos_lecturas[n_vertice_destino], 
                                      minutos_lecturas[n_vertice_destino]);

        arbol_minimo.insertar_arista(nombres_lecturas[n_vertice_origen],
                                     nombres_lecturas[n_vertice_destino]);

        arbol_minimo.insertar_peso(nombres_lecturas[n_vertice_origen],
                                    nombres_lecturas[n_vertice_destino], peso);
    }
    arbol_minimo.mostrar_grafo();
}



vector<vector<int>> Grafo::obtener_adyacencia() {
        return matriz_adyacente;
}

vector<vector<int>> Grafo::obtener_pesos(){
        return matriz_pesos;
}

vector<string> Grafo::obtener_nombres_lecturas() {
    return nombres_lecturas;
}

vector<string> Grafo::obtener_tipos_lecturas() {
    return tipos_lecturas;
}

vector<Arista> Grafo::obtener_vector_aristas() {
    return aristas;
}

vector<int> Grafo::obtener_lecturas_leidas() {
    return lecturas_leidas;
}

vector<int> Grafo::obtener_minutos_lecturas() {
    return minutos_lecturas;
}





void Grafo::agregar_arista(int v1, int v2, int peso) {
    Arista arista(v1, v2, peso);
    aristas.push_back(arista);
}

//ver si es necesaria esta funcion:
void Grafo::sacar_arista(int vertice_a_remover) {
    int cant_aritas = castear_a_int(aristas.size());
    for (int i = 0; i < cant_aritas; i++) {
        if (aristas[i].obtener_vertice1() == vertice_a_remover || aristas[i].obtener_vertice2() == vertice_a_remover)
            aristas.erase(aristas.begin() + i);
    }
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
    int cantidad = 0;
    sort(aristas.begin(), aristas.end());//ordena las aristas por menor peso

    int cant_lecturas = castear_a_int(nombres_lecturas.size());
    //esto se carga desde el vector de nombres de lecturas que se actualiza cuando saco o pongo lecturas
    int * subconjunto = new int[cant_lecturas];

    //inicializa todos los subconjuntos como conjuntos de un unico elemento
    memset(subconjunto, -1, sizeof(int) * cant_lecturas);

    int tamanio_aristas = castear_a_int(aristas.size());
    for(int i = 0; i < tamanio_aristas; i++) {
        int v1 = buscar(subconjunto, aristas[i].obtener_vertice1());
        int v2 = buscar(subconjunto, aristas[i].obtener_vertice2());
        //cout << "Compara: "<< nombres_lecturas[v1] << "   -   "<< nombres_lecturas[v2] << "   peso: " <<aristas[i].obtener_peso() <<"\n";

        if(v1 != v2) {
            //si son diferentes es porque no forman un ciclo
            arbol.push_back(aristas[i]);
            cantidad++;
            lecturas_leidas.push_back(0);
            lecturas_leidas.push_back(0);
            unir_subconjuntos(subconjunto, v1, v2);
        }
    }

    int tamanio_arbol= castear_a_int(arbol.size());
    int tiempo_lecturas = 0;

    for(int i = 0; i < tamanio_arbol; i++) {
        //int vertice1 = arbol[i].obtener_vertice1();
        //int vertice2 = arbol[i].obtener_vertice2();
        tiempo_lecturas = tiempo_lecturas + arbol[i].obtener_peso(); 
        //if (!lectura_leida[i]) ==> += minutos_lecura[i];
        //            ==> cout << nombres_lecturas[i];
        //+TIEMPO DE LECTURA DE CADA VERTICE
    }
    cout << "El orden de las lecturas es el siguiente: \n";
    for (int i = 0; i < cantidad; i++) {
        int pos1 = arbol[i].obtener_vertice1();
        if (lecturas_leidas[pos1] == 0) {
            cout << nombres_lecturas[pos1] << endl;
            lecturas_leidas[pos1] = 1;
            tiempo_lecturas = tiempo_lecturas + minutos_lecturas[pos1];
        }
        int pos2 = arbol[i].obtener_vertice2();
        if (lecturas_leidas[pos2] == 0) {
            cout << nombres_lecturas[pos2] << endl;
            lecturas_leidas[pos2] = 1;
            tiempo_lecturas = tiempo_lecturas + minutos_lecturas[pos2];
        }
    }
            //cout << "(" << nombres_lecturas[v1] << ", " << nombres_lecturas[v2] << ") = " << arbol[i].obtener_peso() << endl;
    
    mostar_arbol_expansion_minima(arbol);

    cout << "En total tardaras: " << tiempo_lecturas << " minutos\n";
    delete [] subconjunto;
}
