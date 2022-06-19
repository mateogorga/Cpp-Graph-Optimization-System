#include "hash_escritores.h"

Hash_escritores::Hash_escritores(){
    //tengo que instanciar las listas vacias?
}

int Hash_escritores::hashing(int clave){
    return (clave % MAX_ESCRITORES);
}

void Hash_escritores::agregar_escritor(Escritor* escritor){
    int pos = hashing(stoi(escritor->obtener_codigo()));
    vec_escritores[pos]->alta(escritor, vec_escritores[pos]->obtener_cantidad());
}
/*
Escritor* Hash_escritores::obtener_escritor(int clave){
    int pos = hashing(clave);
    return vec_escritores[pos]->buscar_pos(clave);
}*/

void Hash_escritores::listar(){

}

Hash_escritores::~Hash_escritores(){

}