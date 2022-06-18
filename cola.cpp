#include "cola.h"

Cola::Cola() {
    primero = 0;
    ultimo = 0;
}

void Cola::alta(Lectura* lectura) {
    Nodo<Lectura*>* nuevo = new Nodo<Lectura*>(lectura);
    if (primero)
        ultimo->cambiar_siguiente(nuevo);
    else
        primero = nuevo;
    ultimo = nuevo;
}

void Cola::baja() {
    Nodo<Lectura*>* borrar = primero;
    primero = primero->obtener_siguiente();
    if (! primero)
        ultimo = 0;
    borrar->cambiar_dato();
    delete borrar;  
}

Lectura* Cola::consulta() {
    return primero->obtener_dato();
}

bool Cola::vacia() {
    return (ultimo == 0);
}


Cola::~Cola() { 
    while (! vacia())
        baja();
}