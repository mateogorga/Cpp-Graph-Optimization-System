#include "escritor.h"

const int SIGUE_VIVO = -1;

Escritor::Escritor(string nombre_completo, string nacionalidad, int nacimiento,
                   int fallecimiento, string codigo) {
    this -> nombre_completo = nombre_completo;
    this -> nacionalidad = nacionalidad;
    this -> nacimiento = nacimiento;
    this -> fallecimiento = fallecimiento;
    this -> codigo = codigo;
}

void Escritor::mostrar_datos() {

    cout << "Nombre del escritor: " << nombre_completo << endl;
    cout << "ISNI de identificacion: " << codigo << endl;
    cout << "Nacionalidad: " << nacionalidad << endl;
    cout << "Nacio en: " << nacimiento << endl;
    if(fallecimiento != SIGUE_VIVO)
        cout<<"Fallecio en: " << fallecimiento << endl;
    else
        cout << "Se encuentra vivo." << endl;
}

void Escritor::mostrar_nombre_completo() {
    cout << nombre_completo << endl;
}

string Escritor::obtener_nombre_completo() {
    return nombre_completo;
}

string Escritor::obtener_nacionalidad() {
    return nacionalidad;
}

int Escritor::obtener_nacimiento() {
    return nacimiento;
}

int Escritor::obtener_fallecimiento() {
    return fallecimiento;
}

void Escritor::cambiar_fallecimiento(int anio) {
    fallecimiento = anio;
}

string Escritor::obtener_codigo() {
    return codigo;
}