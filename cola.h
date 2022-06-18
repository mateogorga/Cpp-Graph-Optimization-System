#ifndef COLA_H
#define COLA_H

#include "nodo.h"
#include "lectura.h"

class Cola {
    // Atributos
private:
    Nodo<Lectura*>* primero;
    Nodo<Lectura*>* ultimo;
    // Metodos
public:
    
    //PRE: -
    //POS: construye una Cola vacia.
    Cola();

    //PRE: la lectura sea valida.
    //POS: agrega una lectura al final de la Cola.
    void alta(Lectura* lectura);

    //PRE: -
    //POS: elimina la primer lectura de la cola.
    void baja();

    //PRE: la cola no puede estar vacia.
    //POS: devuelve la primer lectura de la cola.
    Lectura* consulta();

    //PRE: -
    //POS: devuelve true si la Cola esta vacia, false en caso contrario.
    bool vacia();

    // Destructor
    ~Cola();
};

#endif //COLA_H