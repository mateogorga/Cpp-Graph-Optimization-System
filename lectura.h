#ifndef LECTURA_H
#define LECTURA_H

#include <iostream>
#include "escritor.h"

const int MENOR = -1;
const int MAYOR = 1;
const int IGUAL = 0;
const char MINUTOS_L = 'm';
const char ANIO_L = 'l';

using namespace std;



class Lectura {

protected:
    string titulo;
    int minutos;
    int anio;
    Escritor* autor;
    string tipo;

public:
    //constructor
    Lectura(string titulo, int minutos, int anio, Escritor* autor, char tipo);
    //metodo virtual
    virtual void mostrar_datos() = 0;
    string obtener_titulo();
    int obtener_minutos();
    int obtener_anio();
    Escritor* obtener_autor();
    char obtener_tipo();

    //PRE: el parametro debe ser o minutos o anio.
    //POS: si el parametro recibido es minutos, llama al metodo comparar para los minutos, y si es anio
    //llama al metodo de comparar para anios.
    int comparar(Lectura* l, char parametro);

    //Metodo virtual
    //Se le pasa un tipo de dato string por ser el mas portable.
    //La funcion es lo mas generica posible en caso de querer redefinirla
    //particularmente para que muestre algo en cada tipo de lectura.
    virtual void mostrar_segun_parametro (string dato) = 0;

    //PRE: -
    //POS: devuelve –1 si el anio de la lectura que llama es menor a la que se pasa por parámetro, 1 si 
    // es mayor, y 0 si son iguales.
    int comparar(Lectura* l);

    //PRE: -
    //POS: devuelve –1 si los minutos de la lectura que llama son menores a la que se pasa por parámetro, 
    // 1 si son mayores, y 0 si son iguales. El parametro booleano es para diferenciar si la comparacion es
    // de minutos en lugar del anio.
    int comparar(Lectura* l, bool comparar_minutos);
    

    //OBTENER DATOS() que redefino en cada clase para que me devuelva su propio atributo?
    //void mostrar el atributo. que imprima el atributo y con eso puedo comparar los stri
    //ngs
    // o una funcion que no especifique el tipo de valor a retornar hasta que se instancia
    //el objet
    
    virtual~Lectura() = 0;
};

#endif //LECTURA_H
