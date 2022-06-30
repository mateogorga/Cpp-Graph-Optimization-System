#ifndef PARSER_LECTURAS_H
#define PARSER_LECTURAS_H

#include <iostream>
#include <fstream>

#include "lectura.h"
#include "cuento.h"
#include "novela.h"
#include "historica.h"
#include "poema.h"
#include "lista_lecturas.h"
#include "escritor.h"
#include "hash_escritores.h"


using namespace std;

class Parser_lecturas {

    private:    

        //PRE: Recibe un archivo abierto y un string que puede ser vacio o no.
        //POST: Mientras el string sea vacio y exista archivo, va a buscar lineas hasta
        //que deje de ocurrir alguna de las condiciones. Esto se hace para manejar casos
        //donde haya mas de un espacio entre lecturas.
        string obtener_dato(ifstream& archivo, string dato);


        //PRE: Recibe el string del genero de la novela.
        //POST: Devuelve el genero en tipo de dato enum Genero.
        Genero procesar_str_genero(string str_genero);


        //PRE: Recibe el string con el tema de la novela historica.
        //POST: Devuelve un puntero a un vector de chars, donde cada posicion es una
        //letra del tema.
        char* procesar_tema(string str_tema);


        //PRE: Recibe el string de forma "(X)" donde la X es el numero con el que se 
        //identifica al autor en la lista de escritores. Recibe dicha lista.
        //POST: Devuelve un puntero a escritor extrayendo la X y usandola con el                //necesito que a la hora de devolver un puntero al autor, busque en la lista de escritores aquel que coincida con el ISNI recibido, enves de devolver la posicion que antes coincidia con el numero que figuraba en el txt
        //metodo de consulta. Recordar que la lista de escritores comienza en la
        //posicion 1. En caso de ser anonimo devuelve un puntero a nullptr.
        Escritor* procesar_autor (string numero_autor, Hash_escritores& le);


        //PRE: Recibe los datos listos para cargar, menos minutos y anios.
        //POST: Castea minutos y anios a integers. Crea un puntero a la novela
        //que instancia y la carga en la lista de lecturas.
        void cargar_novela(Lista_lecturas& ll, Hash_escritores& le,string titulo, 
                                   string minutos, string anio, Escritor* p_autor, 
                                   Genero genero);

        //PRE: Recibe los datos listos para cargar, menos minutos y anios.
        //POST: Castea minutos y anios a integers. Crea un puntero a la novela historica
        //que instancia y la carga en la lista de lecturas.
        void cargar_novela_historica(Lista_lecturas&ll, Hash_escritores& le, string titulo, 
                                   string minutos, string anio, Escritor* p_autor, 
                                   Genero genero, char* tema);

        //PRE: Recibe los datos listos para cargar, menos minutos y anios.
        //POST: Castea minutos y anios a integers. Crea un puntero al cuento
        //que instancia y lo carga en la lista de lecturas.
        void cargar_cuento(Lista_lecturas& ll, Hash_escritores& le, string titulo, 
                           string minutos, string anio, Escritor* p_autor, 
                           string titulo_libro);

        //PRE: Recibe los datos listos para cargar, menos minutos, anios y cantidad de 
        //veros.
        //POST: Castea minutos, anios y cantidad de versos a integer. Crea un puntero 
        //al poema que instancia y lo carga en la lista de lecturas.
        void cargar_poema(Lista_lecturas& ll, Hash_escritores& le, string titulo,
                          string minutos, string anio, Escritor* p_autor, 
                          string cantidad_versos);


        //PRE: Recibe el archivo de lecturas abierto luego de haber leido una N. La
        //lista de escritores previamente cargada y la lista de lecturas. Todos por 
        //referencia.
        //POST: Decide si llamar a cargar_novela o cargar_novela_historica, con los datos
        //procesados menos minutos y anio que los entrega como strings.
        void extraer_datos_novela(ifstream& archivo, Lista_lecturas& ll, 
                                  Hash_escritores& le);


        //PRE: Recibe el archivo de lecturas abierto luego de haber leido una C. La
        //lista de escritores previamente cargada y la lista de lecturas. Todos por 
        //referencia.
        //POST: Llama a la funcion cargar_cuento con los datos procesados menos minutos y
        //anio que los entrega como strings.
        void extraer_datos_cuento(ifstream& archivo, Lista_lecturas& ll, 
                                  Hash_escritores& le);


        //PRE: Recibe el archivo de lecturas abierto luego de haber leido una P. La
        //lista de escritores previamente cargada y la lista de lecturas. Todos por 
        //referencia.
        //POST: Llama a la funcion cargar_poema con los datos procesados menos minutos
        // anio y cantidad de versos que los entrega como strings.
        void extraer_datos_poema(ifstream& archivo, Lista_lecturas& ll,
                                 Hash_escritores& le);
       
        
        //PRE: Recibe archivo de lecturas abierto en la primer linea y una
        //lista de lecturas vacia.
        //POST: se ejecuta mientras exista archivo abierto. Compara las lineas de letras
        //para decidir que tipo de lectura carga. Llama a la carga correspondiente.
        void procesar_datos(ifstream& archivo, Lista_lecturas& ll, 
                            Hash_escritores& le);


    public:
        //Constructor.
        Parser_lecturas();

        //PRE: Recibe un archivo.txt de lecturas cuyos datos siguen el orden pedido 
        //en el enunciado del TP2. Recibe la lista de escritores creada por el 
        //Parser_escritores.
        //POST: devuelve una lista cargada con los datos por novela ordenada por anio
        //con punteros a sus escritores correspondientes.
        Lista_lecturas cargar_lista_lecturas(string nombre_archivo, 
                                             Hash_escritores& le);
    
        //Destructor.
        ~Parser_lecturas();
};

#endif //PARSER_LECTURAS_H