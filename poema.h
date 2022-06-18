#ifndef POEMA_H
#define POEMA_H

#include "lectura.h"

class Poema: public Lectura{

private:

    int versos;

public:
    //constructor
    Poema(string titulo, int minutos, int anio, Escritor* autor, int versos);

    
    int obtener_versos();

    //PRE: -
    //POST: Imprime por pantalla los datos del poema.
    void mostrar_datos();


    void mostrar_segun_parametro(string dato);

};

#endif //POEMA_H