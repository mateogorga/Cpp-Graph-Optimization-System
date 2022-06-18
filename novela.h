#ifndef NOVELA_H
#define NOVELA_H

#include "lectura.h"

enum Genero {DRAMA, FICCION, SUSPENSO, TERROR, ROMANTICA, HISTORICA};


class Novela : public Lectura
{
private:
    Genero genero;


public:
    //constructor
    Novela(string titulo, int minutos, int anio, Escritor* autor, Genero genero);

    Genero obtener_genero();

    //PRE: -
    //POST: imprime por pantalla los datos de la novela
    void mostrar_datos();

    //PRE: El dato debe ser un caracter numerico.
    //POST: imprimirá por pantalla aquellas novelas que coincidan con el genero 
    //pasado como dato.
    void mostrar_segun_parametro (string dato);
};


#endif // NOVELA_H