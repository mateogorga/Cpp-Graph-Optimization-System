#include "hash_escritores.h"

Hash_escritores::Hash_escritores() {
    for(int i = 0; i < TAMANIO_TABLA; i++){
        Lista_escritores* p = new Lista_escritores;
        vec_escritores[i] = p;
    }
}

int Hash_escritores::hashing(int clave) {
    return (clave % TAMANIO_TABLA);
}

void Hash_escritores::alta(Escritor* escritor) {
    int pos = hashing(stoi(escritor->obtener_codigo()));
    vec_escritores[pos]->alta(escritor, vec_escritores[pos]->obtener_cantidad() + 1);
}

Escritor* Hash_escritores::obtener_escritor(int clave) {
    int pos = hashing(clave);
    return vec_escritores[pos]->buscar_segun_codigo(clave);
}

void Hash_escritores::listar() {
    int contador = 0;
    for(int i = 0; i < TAMANIO_TABLA; i++){
        if(vec_escritores[i]->vacia() == false)
            vec_escritores[i]->listar();
        else    
            contador++;
    }
    if(contador == TAMANIO_TABLA)
        cout << "La tabla de hashing de escritores se encuentra vacia" << endl;
}

Hash_escritores::~Hash_escritores() {

}