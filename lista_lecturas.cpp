#include "lista_lecturas.h"

// Constructor
Lista_lecturas::Lista_lecturas() {
    primero = 0;
    cantidad = 0;
}

bool Lista_lecturas::vacia() {
    return (cantidad == 0);
}

int Lista_lecturas::obtener_cantidad() {
    return cantidad;
}


Lectura* Lista_lecturas::consulta(int pos) {
    Nodo<Lectura*>* aux = obtener_nodo(pos);
    return aux->obtener_dato();
}

void Lista_lecturas::alta(Lectura* e, char parametro) {
    Nodo<Lectura*>* nuevo = new Nodo<Lectura*>(e);
    if ((primero == 0) || (nuevo->obtener_dato()->comparar(primero->obtener_dato(), parametro) == MENOR)) {
        nuevo->cambiar_siguiente(primero);
        primero = nuevo;
    } else {
        Nodo<Lectura*>* aux = primero;
        while((aux->obtener_siguiente() != 0) && (aux->obtener_siguiente()->obtener_dato()->comparar(nuevo->obtener_dato(), parametro) == MENOR)){
            aux = aux->obtener_siguiente();
        }
        if(aux->obtener_siguiente() != 0){
            nuevo->cambiar_siguiente(aux->obtener_siguiente());
        }
        aux->cambiar_siguiente(nuevo);
    }
    cantidad++;
}


void Lista_lecturas::baja(int pos) {
    Nodo<Lectura*>* borrar = primero;
    if (pos == 1) {
        primero = primero->obtener_siguiente();
    }
    else {
        Nodo<Lectura*>* anterior = obtener_nodo(pos - 1);
        borrar = anterior->obtener_siguiente();
        anterior->cambiar_siguiente(borrar->obtener_siguiente());
    }
    cantidad--;
    delete borrar;
    //creo que este delete no va.
}

Nodo<Lectura*>* Lista_lecturas::obtener_nodo(int pos) {
    Nodo<Lectura*>* aux = primero;
    int contador = 1;
    while (contador < pos) {
        aux = aux->obtener_siguiente();
        contador++;
    }
    return aux;
}

void Lista_lecturas::listar(){ 
    if(vacia() == false){
        Nodo<Lectura*>* aux = primero;
        int contador = 1;
        while(contador <= cantidad){
            cout << endl;
            cout << contador << ". ";
            aux->obtener_dato()->mostrar_datos();
            aux = aux->obtener_siguiente();
            contador++;
        }
    }else{
        cout << endl << "La lista de lecturas se encuentra vacia." << endl;
    }
}


Lista_lecturas::~Lista_lecturas()  {
    while (! vacia())
        baja(1);
}
