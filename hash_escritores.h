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
    //POS: 
    Hash_escritores();

    //PRE: no deben haber mas de 20 escritores.
    //POS: inserta al escritor pasado en posicion que le corresponde en funcion al resultado de la
    //     funcion de hashing aplicada al codigo del escritor.
    void alta(Escritor* escritor);
    
    //PRE:
    //POS: 
    Escritor* obtener_escritor(int clave);
    
    //void eliminar_escritor(); no va a hacer falta no?
    
    //PRE:
    //POS:
    void listar();

    //PRE:
    //POS:
    void modificar_fallecimiento(int anio);

    //Destructor
    ~Hash_escritores();
private:

    //PRE:
    //POS:
    int hashing(int clave);
};

#endif //HASH_ESCRITORES_H