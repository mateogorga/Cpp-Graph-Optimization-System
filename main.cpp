#include "cuento.h"
#include "escritor.h"
#include "historica.h"
#include "poema.h"
#include "hash_escritores.h"
#include "novela.h"
#include "lectura.h"
#include "menu.h"
#include <iostream>
#include <string>
#include "parser_lecturas.h"
#include "parser_escritores.h"

const string ARCHIVO_LECTURAS = "lecturas.txt";
const string ARCHIVO_ESCRITORES = "escritores.txt";
using namespace std;

int main() {
    /*
    Parser_escritores parser_escritores = Parser_escritores();
    Lista_escritores l_escritores = parser_escritores.cargar_lista_escritores(ARCHIVO_ESCRITORES);

    Parser_lecturas parser_lecturas = Parser_lecturas();
    Lista_lecturas l_lecturas = parser_lecturas.cargar_lista_lecturas(ARCHIVO_LECTURAS, l_escritores);
    
    Menu menu;
    Lista_lecturas lista_aux;
    Cola cola;

    menu.mensaje_inicial();
    menu.ejecutar_menu(menu, l_lecturas, l_escritores, cola, lista_aux);    */
    Hash_escritores escritores;

    Escritor* p_escritor = new Escritor("Stephen King", "argentino", 2001, 2002, "123");
    escritores.alta(p_escritor);

    Escritor* p_escritor2 = new Escritor("Cortazar", "uruguayo", 2022, 2002, "555");
    escritores.alta(p_escritor2);

    escritores.listar();
    cout << endl << "Ahora obtener un escritor" << endl;
    int codigo;
    cin >> codigo;
    if(escritores.obtener_escritor(codigo))
        escritores.obtener_escritor(codigo)->mostrar_datos();

    /*
    cout << endl << "Agrego a Berne en la pos 1" << endl;

    Escritor escritor3("Julio Berne", "chino", 1845, 1900, "777");
    Escritor* p_escritor3;
    p_escritor3 = &escritor3;
    lista.alta(p_escritor3, 1);

    lista.listar();
    cout << endl << "Doy de baja al 2do" << endl;
    lista.baja(2);

    lista.listar();

    cout << endl << "Cambio el fallecimiento de Julio Berne por el anio 2022" << endl;
    lista.cambiar_fallecimiento(2022, 1);
    lista.listar();*/
    
    return 0;   
}
