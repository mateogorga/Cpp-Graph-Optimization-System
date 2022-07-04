#ifndef ESCRITOR_H
#define ESCRITOR_H

#include <iostream>

using namespace std;

class Escritor {

private: 
    string nombre_completo;
    string nacionalidad;
    int nacimiento;
    int fallecimiento;
    string codigo;

public:

    //constructor
    Escritor(string nombre_completo, string nacionalidad, int nacimiento,
             int fallecimiento, string codigo);

    //PRE: -
    //POS: imprime por pantalla la informacion del escritor.
    void mostrar_datos();
    
    //PRE: -
    //POS: modifica el anio de fallecimiento del escritor por el anio pasado.
    void cambiar_fallecimiento(int anio);

    //PRE: -
    //POS: imprime por pantalla el nombre del escritor.
    void mostrar_nombre_completo();

    //PRE: -
    //POS: imprime por pantalla el codigo del escritor.
    void mostrar_codigo();

    string obtener_nombre_completo();
    string obtener_nacionalidad();
    int obtener_nacimiento();
    int obtener_fallecimiento();
    string obtener_codigo();
};

#endif //ESCRITOR_H
