#include "cuento.h"

Cuento::Cuento(string titulo, int minutos, int anio, Escritor* autor, string libro)
            :Lectura(titulo, minutos, anio, autor){
    this->libro = libro;
    this->tipo = "Cuento";
}

string Cuento::obtener_libro(){
    return libro;
}

void Cuento::mostrar_datos(){
    cout << "Titulo: " << titulo << endl;
    cout << "Minutos de lectura: " << minutos << endl; 
    cout << "Anio de publicacion: " << anio << endl;
    cout << "Autor: "; 
    autor->mostrar_nombre_completo();
    cout << "Libro en el que se publico: " << libro << endl;
}


void Cuento::mostrar_segun_parametro(string dato) {
    
}
