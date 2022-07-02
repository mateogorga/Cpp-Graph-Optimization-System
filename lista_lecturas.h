#ifndef LISTA_ENLAZADA_LISTA_ENLAZADA_H
#define LISTA_ENLAZADA_LISTA_ENLAZADA_H
#include "nodo.h"
#include "lectura.h"

const int INICIO_CONTADOR = 1;

class Lista_lecturas {

    // Atributos
private:
    Nodo<Lectura*>* primero;
    int cantidad;


    // Metodos
public:

    //PRE: -
    //POS: construye una Lista vacia.
    Lista_lecturas();

    //PRE: -
    //POS: devuelve un puntero al nodo que se encuentra en la poscicion pasada.
    Nodo<Lectura*>* obtener_nodo(int pos);

  
    //PRE: e es un Dato valido y 1 <= pos <= obtener_cantidad() + 1
    //POS: agrega el puntero a lectura pasado en la lista de forma ordenada. Si el parametro
    // es minutos lo ordena por minutos de lectura, y si es anio lo ordena por anio de publicacion.
    // Este orden lo hace de forma creciente.
    void alta(Lectura* e, char parametro);


    //PRE: 1 <= pos <= obtener_cantidad()
    //POS: da de baja al elemento que esta en pos, se empieza por 1
    void baja(int pos);


    //PRE: 1 <= pos <= obtener_cantidad()
    //POS: devuelve el elemento que esta en pos, se empieza por 1
    Lectura* consulta(int pos);


    //PRE: -
    //POS: devuelve true si la Lista esta vacia, false de lo contrario.
    bool vacia();
    

    //PRE: -
    //POS: devuelve la cantidad de elementos que posee la lista.
    int obtener_cantidad();


    //PRE: -
    //POS: Imprime por pantalla todos los elementos de la lista con sus atributos.
    void listar();

    //PRE: -
    //POS: modifica el atributo autor del escritor pasado, haciendo que apunte a null.
    void modificar_escritor(Escritor* escritor);

    // Destructor
    ~Lista_lecturas();
};

#endif //LISTA_ENLAZADA_LISTA_ENLAZADA_H
