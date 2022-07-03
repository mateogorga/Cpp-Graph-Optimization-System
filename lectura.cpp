#include "lectura.h"


Lectura::Lectura(string titulo, int minutos, int anio, Escritor* autor) {
    this -> titulo = titulo;
    this -> minutos = minutos;
    this -> anio = anio;
    this -> autor = autor;
}

string Lectura::obtener_titulo() {
    return titulo;
}

int Lectura::obtener_minutos() {
    return minutos;
}

int Lectura::obtener_anio() {
    return anio;
}

Escritor* Lectura::obtener_autor() {
    return autor;
}

string Lectura::obtener_tipo() {
    return tipo;
}

int Lectura::comparar(Lectura* l, char parametro){
    int resultado;
    if(parametro == MINUTOS_L)
        resultado = comparar(l, true);
    else if (parametro == ANIO_L)
        resultado = comparar(l);
    return resultado;
}

int Lectura::comparar(Lectura *l) {
    int anio_cargada = anio;
    int anio_nueva = l->obtener_anio();
    int resultado;

    if (anio_cargada < anio_nueva) {
        resultado = MENOR;
    } else if (anio_cargada > anio_nueva) {
        resultado = MAYOR;
    } else {
        resultado = IGUAL;
    }
    return resultado;
}

int Lectura::comparar(Lectura *l, bool comparar_minutos) {
    int minutos_cargada = minutos;
    int minutos_nueva = l->obtener_minutos();
    int resultado;

    if (minutos_cargada < minutos_nueva) {
        resultado = MENOR;
    } else if (minutos_cargada > minutos_nueva) {
        resultado = MAYOR;
    } else {
        resultado = IGUAL;
    }
    return resultado;
}

void Lectura::modificar_autor(){
    autor = 0;
}

Lectura::~Lectura() {};