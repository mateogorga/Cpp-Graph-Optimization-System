#include "cuento.h"
#include "escritor.h"
#include "historica.h"
#include "poema.h"
#include "lista_escritores.h"
#include "novela.h"
#include "lectura.h"
#include "menu.h"
#include <iostream>
#include <string>
#include "parser_lecturas.h"
#include "parser_escritores.h"
#include "grafo.h"
#include "arbol.h"

const string ARCHIVO_LECTURAS = "lecturas.txt";
const string ARCHIVO_ESCRITORES = "escritores.txt";
using namespace std;

int main() {
    
    Parser_escritores parser_escritores = Parser_escritores();
    Lista_escritores l_escritores = parser_escritores.cargar_lista_escritores(ARCHIVO_ESCRITORES);

    Parser_lecturas parser_lecturas = Parser_lecturas();
    Lista_lecturas l_lecturas = parser_lecturas.cargar_lista_lecturas(ARCHIVO_LECTURAS, l_escritores);

    Arbol arbol;
    arbol.cargar_arbol(l_lecturas);
    
    Menu menu;
    Lista_lecturas lista_aux;
    Cola cola;

    menu.mensaje_inicial();
    menu.ejecutar_menu(menu, l_lecturas, l_escritores, cola, lista_aux);
    
    return 0;   
}
