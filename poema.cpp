#include "poema.h"
#include <iostream>

using namespace std;

Poema::Poema(string titulo, int minutos, int anio, Escritor* autor, int versos)
            :Lectura(titulo, minutos, anio, autor){
    this->versos = versos;
    this -> tipo = "Poema";
}

int Poema::obtener_versos(){
    return versos;
}

void Poema::mostrar_datos(){
    cout << "Titulo: " << titulo << endl;
    cout << "Minutos de lectura: " << minutos << endl; 
    cout << "Anio de publicacion: " << anio << endl;
    cout << "Autor: ";
    if(autor != 0)
        autor->mostrar_nombre_completo();
    else
        cout << "ANONIMO" << endl;
    cout << "Cantidad de versos: " << versos << endl;
}

void Poema::mostrar_segun_parametro(string dato) {

}