#ifndef PARSER_ESCRITORES_H
#define PARSER_ESCRITORES_H


#include <iostream>
#include <fstream>
#include "lista_escritores.h"


using namespace std;

class Parser_escritores {

    private:    
        //PRE: Recibe archivo de escritores abierto en la primer linea y una
        //lista de escritores vacia.
        //POST: se ejecuta mientras exista archivo abierto. LLama a funcion 
        //extrar_escritor.
        void procesar_datos(ifstream& archivo, Lista_escritores& l_escritores);


        //PRE: Recibe archivo de escritores abierto, una lista de escriores y
        //el codigo del escritor que puede ser vacio.
        //POST: llama a funciones obtener_dato y crear_enlistar_escritor y
        //verificar_fallecimiento. Devuelve un string con el codigo del escritor. 
        //IMPORTANTE: Reutiliza el 
        //codigo devuelto. Si es vacio, obtener_dato lo buscará, sino ese codigo
        //en realidad pertenece al siguiente escritor. En este ultimo caso, obtener_dato
        //no busca otra linea, entonces el codigo se mantiene.
        string extraer_escritor (ifstream& archivo, string codigo_escritor,
                                 Lista_escritores& l_escritores);
        

        //PRE: Recibe archivo abierto y un dato tipo string.
        //POST: Si el string es vacio, busca una nueva linea en elarchivo, sino
        //lo devuelve.
        string obtener_dato(ifstream& archivo, string dato);

        
        //PRE: Recibe archivo abierto. El arvhico puede terminar abruptamente antes de
        //informar la fecha de fallecimiento del autor en caso de haberla.
        //POST: Si no termina el archivo devuelve el fallecimiento, de lo contrario,
        //devuelve un -1.
        string verificar_terminacion_abrupta(ifstream& archivo);


        //PRE: Recibe un string correspondiente a la ultima linea de informacion de un 
        //autor o la primer del siguiente.
        //POST: Si tiene una fecha la devuelve, sino devuelve -1.
        string verificar_fallecimineto(string aux);


        //PRE: Recibe los datos correspondientes para crear un escritor.
        //POST: Carga el escritor en memoria y carga la lista con un puntero al 
        //mismo.
        void crear_enlistar_escritor(string nombre, string nacionalidad, 
                                     string nacimiento, string fallecimiento,
                                     Lista_escritores& l_escritores, 
                                     string codigo_escritor);


        //PRE: Recibe una linea del archivo de escritores (puede ser anio de
        //fallecimiento, vacia o codigo del siguiente escritor)
        //POST: Devuele vacio si la linea correspondia a un anio o vacio, sino de-
        //vuelve el codigo.
        string verificar_codigo(string aux);

    public:
        //constructor
        Parser_escritores();

        //PRE: Recibe un archivo.txt de escritores cuyos datos siguen el orden pedido 
        //en el enunciado del TP2.
        //POST: devuelve una lista cargada con los datos por escritor.
        Lista_escritores cargar_lista_escritores(string nombre_archivo);

        //destructor
        ~Parser_escritores(){};
};

#endif //PARSER_H