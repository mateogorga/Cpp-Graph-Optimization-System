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

    std::cout << "Titulo de la lectura: " << titulo << endl;
    std::cout << "Duracion: " << minutos << " minutos" << endl;
    std::cout << "Fue escrita en: " << anio << endl;
    std::cout << "El autor es: "; 
    autor->mostrar_nombre_completo();
    std::cout << "Genero HISTORICA" << endl;
    mostrar_tema();
}

Historica::~Historica() {
   delete [] tema; 
}

