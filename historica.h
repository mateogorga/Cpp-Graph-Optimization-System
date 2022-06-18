#ifndef HISTORICA_H
#define HISTORICA_H

#include "novela.h"

class Historica : public Novela {

private:
    char* tema;
    Genero genero = Genero::HISTORICA;

public:
    //constructor
    Historica(string titulo, int minutos, int anio, Escritor* autor, Genero genero,
                char* tema);

    char* obtener_tema(); 

    //PRE: -
    //POS: imprime por pantalla el tema de la novela historica.
    void mostrar_tema();

    //PRE: -
    //POS: imprime por pantalla los atributos de la novela.
    void mostrar_datos();

    ~Historica();
};

#endif // HISTORICA_H