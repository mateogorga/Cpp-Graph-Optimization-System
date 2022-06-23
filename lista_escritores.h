#ifndef LISTA_H
#define LISTA_H

#include "nodo.h"
#include "escritor.h"

const int POS_INVALIDA = -1;

class Lista_escritores {

//Atrubutos   
private:
    Nodo<Escritor*>* primero;
    int cantidad;

//Metodos publicos
public:

    //PRE: -
    //POS: construye una Lista vacia.
    Lista_escritores();

    //PRE: la posicion tiene que ser mayor a 0.
    //POS: da de alta un nuevo escritor en la lista, en la posicion pasada.
    void alta(Escritor* e, int pos);

    //PRE: 0 < pos <= cantidad
    //POS: da de baja un elemento de la lista sin alterar el orden de la misma.
    void baja(int pos);

    //PRE: 0 < pos <= cantidad
    //POS: devuelve el puntero a escritor que se encuentra en la posicion pasada.
    Escritor* consulta(int pos);

    //PRE: -
    //POS: devuelve un puntero al escritor de la lista cuyo codigo es el pasado por parametro.
    //     En caso de no encontrarse este codigo, devuelve un puntero a nullptr.
    Escritor* buscar_segun_codigo(int codigo);

    //PRE: 0 < pos <= cantidad.
    //POS: cambia el anio de fallecimiento del escritor en la posicion pasada.
    void cambiar_fallecimiento(int anio, int pos);

    //PRE: -
    //POS: devuelve true si la lista se encuentra vacia, y false en caso contrario.
    bool vacia();

    //PRE: -
    //POS: devuelve la cantidad de elementos que posee la lista.
    int obtener_cantidad();

    //PRE: -
    //POS: imprime por pantalla todos los elementos de la lista con sus atributos.
    void listar();

    //PRE: -
    //POS: imprime por pantalla todos los nombres de los escritores, enumerandolos.
    void listar_nombres();

    //PRE: 
    //POS: 
    int obtener_pos_segun_clave( int clave);

    // Destructor
    ~Lista_escritores();

//Metodos privados
private:

    //PRE: 0 < pos <= cantidad
    //POS: devuelve el nodo que se encuentra en la posicion pasada.
    Nodo<Escritor*>* obtener_nodo(int pos);

};

#endif // LISTA_H