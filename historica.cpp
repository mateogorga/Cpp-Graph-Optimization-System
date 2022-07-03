#include "historica.h"
#include "novela.h"

Historica::Historica(string titulo, int minutos, int anio, Escritor* autor,
                    Genero genero, char* tema) : Novela (titulo, minutos, anio, autor, genero) {
    this -> genero = Genero::HISTORICA;
    this -> tema = tema;
    this -> tipo = "Novela Historica";
}

char* Historica::obtener_tema() {
    return tema;
}

void Historica::mostrar_tema() {
    cout << "Tema: ";
    for (int i = 0; tema[i]; i++)
        cout << tema[i];
    cout << endl;
}

void Historica::mostrar_datos() {

    cout << "Titulo de la lectura: " << titulo << endl;
    cout << "Duracion: " << minutos << " minutos" << endl;
    cout << "Fue escrita en: " << anio << endl;
    cout << "El autor es: "; 
    if(autor != 0)
        autor->mostrar_nombre_completo();
    else
        cout << "ANONIMO" << endl;;
    cout << "Genero HISTORICA" << endl;
    mostrar_tema();
}

Historica::~Historica() {
   delete [] tema; 
}

