#ifndef MENU_H
#define MENU_H
#include "lectura.h"
#include "novela.h"
#include "cuento.h"
#include "escritor.h"
#include "historica.h"
#include "poema.h"
#include "hash_escritores.h"
#include "lista_lecturas.h"
#include "cola.h"
#include <iostream>
#include <fstream> 
#include <string>
#include <stdlib.h>
#include "grafo.h"

class Menu {

private:
    //PRE: Recibe tres int: cota inferior, variable, cota superior.
    //POST: Devuelve true en caso de que la variable respete sus cotas.
    //de lo contrario devuelve false.
    bool chequear_rango(int a, int x, int b); 


    //PRE: -
    //POST: pide los datos de un escritor al usuario y los guarda.
    void pedir_datos_escritor(string &nombre_comp, string &nacionalidad, int &nacimiento, int &fallecimiento, string& isni);
    

    //PRE: lista_aux tiene que estar cargada.
    //POST: traspasa las lecturas de la lista auxiliar a la cola, manteniendo el orden de la lista.
    void traspasar_lecturas(Cola &cola, Lista_lecturas& lista_aux); //VER si no tengo q pasar lista con &
    

    //PRE: str_genero debe ser ingresado en mayusculas
    //POS: carga una nueva novela a la lista de lecturas
    void cargar_novela(Lista_lecturas &l_lecturas, string titulo, int minutos, int anio, Escritor* autor, string str_genero, Grafo& grafo);


    //PRE: -
    //POS: carga un nuevo cuento a la lista de lecturas
    void cargar_cuento(Lista_lecturas &l_lecturas, string titulo, int minutos, int anio, Escritor* autor, Grafo& grafo);


    //PRE: -
    //POS: carga un nuevo poema a la lista de lecturas
    void cargar_poema(Lista_lecturas &l_lecturas, string titulo, int minutos, int anio, Escritor* autor, Grafo& grafo);


    //PRE: str_tema debe ser un string
    //POS: convierte el string en un punter char
    char* procesar_tema_historica(string str_tema);


    //PRE: str_genero debe ser un string
    //POS: convierte el string en un genero del Enum
    Genero procesar_str_genero(string str_genero);


    //PRE: -
    //POS: Le pide al usuario que ingrese los datos de la lectura y los guarda.
    void pedir_datos_lectura(string &titulo, int &minutos, int &anio, int &int_tipo);


    //PRE: respuesta1 debe valer 1 o 2.
    //POS: devuelve un puntero al escritor que decida el usuario.
    Escritor* asignar_escritor(Hash_escritores& t_escritores, int& respuesta1);

public:

    //Constructor
    Menu();


    void ejecutar_menu(Menu menu, Lista_lecturas &l_lecturas, Hash_escritores& t_escritores,
                        Cola& cola, Lista_lecturas& lista_aux, Grafo& grafo);

    //PRE: -
    //POS: imprime por pantalla un mensaje inicial para el usuario.
    void mensaje_inicial();
 

    //PRE: -
    //POS: Muestra las opciones del menu y devuelve un in con la respuesta seleccionada.
    int mostrar_menu();


    //PRE: la lectura no debe estar en la lista.
    //POS: agrega una nueva lectura a la lista.
    void agregar_lectura(Lista_lecturas& l_lecturas, Hash_escritores& t_escritores, Grafo& grafo);


    //PRE: la lectura debe estar en la lista
    //POS: elimina la lectura de la lista
    //void quitar_lectura(Lista_lecturas& l_lecturas);
    void quitar_lectura(Lista_lecturas& l_lecturas, Grafo& grafo);


    //PRE: -
    //POS: agrega un escritor ingresado por el usuario a la tabla de escritores 
    //     en la pos que le corresponda.
    void agregar_escritor(Hash_escritores& t_escritores);


    //PRE: -
    //POS: agrega un escritor ingresado por el usuario a la tabla de escritores
    //     en la pos que le corresponda, y devuelve un puntero a dicho escritor.
    Escritor* agregar_devolver_escritor(Hash_escritores& t_escritores);


    //PRE: -
    //POST: modifica el anio de fallecimiento del escritor elegido por el usuario, por el anio ingresado. 
    void cambiar_fallecimiento(Hash_escritores& t_escritores);


    //PRE: -
    //POST: imprime por pantalla todos los escritores de la tabla con sus respectivos atributos.
    void listar_escritores(Hash_escritores& t_escritores);


    //PRE: -
    //POS: devuelve una lectura random
    Lectura* lectura_random(Lista_lecturas& l_lecturas);


    //PRE: -
    //POS: imprime por pantalla todas las lecturas de la lista con sus atributos.
    void listar_lecturas(Lista_lecturas& l_lecturas);


    //PRE: tiene que ser un rango de anios valido
    //POS: devuelve las lecturas que se encuentran en ese rango de anios
    void listar_lecturas_entre_anios(Lista_lecturas& l_lecturas);


    //PRE: Recibe la tabla de escritores y la lista de lecturas cargadas.
    //POST: imprime por pantalla todas las lecturas del escritor que el usuario elija.
    void listar_lecturas_por_escritor(Lista_lecturas& l_lecturas, 
                                      Hash_escritores& t_escritores);
    

    //PRE: Recibe la lista de lecturas previamente cargada.
    //POST: Pide un int al usuario para poder procesarlo contra los generos.
    // Imprime las novelas de la lista que perteneces a dicho genero.
    void listar_novelas_por_genero(Lista_lecturas& l_lecturas);
    

    //PRE: la lista debe estar cargada con las lecturas.
    //POST: inserta en una cola todas las lecturas ordenadas por tiempo de lectura de menor a mayor, 
    // sin repetir lecturas.
    void lecturas_en_cola(Lista_lecturas& l_lecturas, Cola& cola, Lista_lecturas& lista_aux);


    //PRE: -
    //POST: le da la opcion al usuario de eliminar la lectura que tenia pendiente de la cola. Y si la
    // cola ya se encuentra vacia, lo informa.
    void lectura_leida(Cola& cola);

    //PRE: -
    //POS: elimina al escritor de la lista de escritores, haciendo que las lecturas que lo 
    //     tenian como autor ahora pasen a tener autor anonimo.
    void eliminar_escritor(Hash_escritores& t_escritores, Lista_lecturas& l_lecturas);
};

#endif //MENU_H






