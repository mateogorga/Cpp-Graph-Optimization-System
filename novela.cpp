#include "lectura.h"
#include "novela.h"

Novela::Novela(string titulo, int minutos, int anio, Escritor* autor, Genero genero)
            :Lectura(titulo, minutos, anio, autor){
    this->genero = genero;
    this -> tipo = "Novela";
}

Genero Novela::obtener_genero() {
    return genero;
};


//podriamos imprimirlo aca adentro y que la funcion sea void, 
//pero quizas en un futuro sea util tener una funcion que me trans
//forme de genero a string en las Novelas.
string obtener_string_genero(Genero genero){
    string str_genero;
    switch (genero)
    {
    case (Genero::DRAMA):
        str_genero = "DRAMA";
        break;
    case Genero::FICCION:
        str_genero = "FICCION";
        break;
    case Genero::SUSPENSO:
        str_genero = "SUSPENSO";
        break;
    case Genero::TERROR:
        str_genero = "TERROR";
        break;
    case Genero::ROMANTICA:
        str_genero = "ROMANTICA";
        break;
    case Genero::HISTORICA:
        str_genero = "HISTORICA";
        break;
    };
    return str_genero;
}

void Novela::mostrar_datos() {

    std::cout << "Titulo de la lectura: " << titulo << endl;
    std::cout << "Duracion: " << minutos << " minutos" << endl;
    std::cout << "Fue escrita en: " << anio << endl;
    std::cout << "El autor es: "; 
    autor->mostrar_nombre_completo();
    string str_genero = obtener_string_genero(genero);
    std::cout << "Genero: " << str_genero << endl;

}



void Novela::mostrar_segun_parametro(string dato) {
    int int_dato = stoi(dato);
    if (int_dato == obtener_genero())
        mostrar_datos();
}
