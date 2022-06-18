#ifndef CUENTO_H
#define CUENTO_H

#include "lectura.h"

class Cuento: public Lectura{

private:

    string libro;
    
public:

    //constructor
    Cuento(string titulo, int minutos, int anio, Escritor* autor, string libro);
    //imprime por pantalla toda la informacion sobre el cuento
    void mostrar_datos();
    string obtener_libro();
    void mostrar_segun_parametro (string dato);
};

#endif //CUENTO_H