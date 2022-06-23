#ifndef HASH_ESCRITORES_H
#define HASH_ESCRITORES_H

#include "escritor.h"
#include "lista_escritores.h"

const int TAMANIO_TABLA = 29; // 0.8 => 20 / m --> m = 25 tomo el num primo mas cercano --> 29
const int MAX_ESCRITORES = 20;

class Hash_escritores{

//Atributos
private:
    Lista_escritores* vec_escritores[TAMANIO_TABLA];

//Metodos
public:
    
    //PRE: -
    //POS: inicializa el vector con punteros a listas de escritores en todas las posciones.
    Hash_escritores();

    //PRE: no deben haber mas de 20 escritores.
    //POS: inserta al escritor pasado en posicion que le corresponde en funcion al resultado de la
    //     funcion de hashing aplicada al codigo del escritor.
    void alta(Escritor* escritor);
    
    //PRE: la clave debe ser un numero entero positivo.
    //POS: devuelve un puntero al escritor que posee la clave pasada. De no encontrarse,
    //     devuelve un puntero a nullptr.
    Escritor* obtener_escritor(int clave);
    
    //PRE: la clave debe ser un numero entero positivo.
    //POS: elimina de la tabla al escritor en base a su clave.
    void baja(int clave);
    
    //PRE: -
    //POS: muestra por pantalla a los escritores almacenados con su respectiva informacion.
    void listar();

    //Destructor
    ~Hash_escritores();
private:

    //PRE: la clave debe ser un numero entero positivo.
    //POS: devuelve clave % MAX_ESCRITORES
    int hashing(int clave);
};

#endif //HASH_ESCRITORES_H