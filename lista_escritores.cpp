#include "lista_escritores.h"

const int INICIO_CONTADOR = 1;
const int PRIMER_POS = 1;

Lista_escritores::Lista_escritores() {
    primero = 0;
    cantidad = 0;
}

bool Lista_escritores::vacia() {
    return (cantidad == 0);
}

int Lista_escritores::obtener_cantidad() {
    return cantidad;
}


Escritor* Lista_escritores::consulta(int pos) {
    Nodo<Escritor*>* aux = obtener_nodo(pos);
    return aux->obtener_dato();
}

void Lista_escritores::alta(Escritor* e, int pos) {
    Nodo<Escritor*>* nuevo = new Nodo<Escritor*>(e);
    if (pos == PRIMER_POS) {
        nuevo->cambiar_siguiente(primero);
        primero = nuevo;
    }
    else {
        Nodo<Escritor*>* anterior = obtener_nodo(pos - 1);
        nuevo->cambiar_siguiente(anterior->obtener_siguiente());
        anterior->cambiar_siguiente(nuevo);
    }
    cantidad++;
}

void Lista_escritores::baja(int pos) {
    Nodo<Escritor*>* borrar = primero;
    if (pos == PRIMER_POS) {
        primero = primero->obtener_siguiente();
    }
    else {
        Nodo<Escritor*>* anterior = obtener_nodo(pos - 1);
        borrar = anterior->obtener_siguiente();
        anterior->cambiar_siguiente(borrar->obtener_siguiente());
    }
    cantidad--;
    delete borrar;
}

Nodo<Escritor*>* Lista_escritores::obtener_nodo(int pos) {
    Nodo<Escritor*>* aux = primero;
    int contador = INICIO_CONTADOR;
    while (contador < pos) {
        aux = aux->obtener_siguiente();
        contador++;
    }
    return aux;
}

void Lista_escritores::listar() {
    if(vacia() == false) {
        Nodo<Escritor*>* aux = primero;
        int contador = INICIO_CONTADOR;
        while(contador <= cantidad){
            cout << endl;
            aux->obtener_dato()->mostrar_datos();
            if(contador < cantidad){
                aux = aux->obtener_siguiente();
            }
            contador++;
        }
    } else
        cout << "La lista de escritores se encuentra vacia" << endl;
}

void Lista_escritores::cambiar_fallecimiento(int anio, int pos) {    
    Nodo<Escritor*>* aux = obtener_nodo(pos);
    aux->obtener_dato()->cambiar_fallecimiento(anio);
}

void Lista_escritores::listar_nombres() {
    if(vacia() == false) {
        cout << "A continuacion se mostraran los nombres de todos los escritores en la lista: " << endl;
        Nodo<Escritor*>* aux = primero;
        int contador = INICIO_CONTADOR;
        while(contador <= cantidad){
            cout << endl;
            cout << contador << ". ";
            aux->obtener_dato()->mostrar_nombre_completo();
            aux = aux->obtener_siguiente(); 
            contador++;
        }
    } else
        cout << "La lista de escritores se encuentra vacia" << endl;
}

Lista_escritores::~Lista_escritores() {
    while (! vacia())
        baja(1);
}