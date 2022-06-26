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

const string ARCHIVO_LECTURAS = "lecturas.txt";
const string ARCHIVO_ESCRITORES = "escritores.txt";
using namespace std;

int main() {
    
    Menu menu;

    Parser_escritores parser_escritores = Parser_escritores();
    Hash_escritores t_escritores = parser_escritores.cargar_lista_escritores(ARCHIVO_ESCRITORES);
    Parser_lecturas parser_lecturas = Parser_lecturas();
    Lista_lecturas l_lecturas = parser_lecturas.cargar_lista_lecturas(ARCHIVO_LECTURAS, t_escritores);
    
    Lista_lecturas lista_aux;
    Cola cola;
    Grafo grafo;
    //grafo.cargar_grafo(l_lecturas);

    //grafo.insertar_arista(l_lecturas.consulta(5)->obtener_titulo(), l_lecturas.consulta(2)->obtener_titulo());
    //grafo.insertar_arista(l_lecturas.consulta(3)->obtener_titulo(), l_lecturas.consulta(4)->obtener_titulo());
    //grafo.insertar_peso(l_lecturas.consulta(5)->obtener_titulo(), l_lecturas.consulta(2)->obtener_titulo(), 20);

  



    menu.mensaje_inicial();
    menu.ejecutar_menu(menu, l_lecturas, t_escritores, cola, lista_aux, grafo);    
/*    
    Hash_escritores escritores;

    Escritor* p_escritor = new Escritor("Stephen King", "estadounidense", 1947, -1, "123");
    escritores.alta(p_escritor);

    Escritor* p_escritor2 = new Escritor("Cortazar", "uruguayo", 1914, 1984, "555");
    escritores.alta(p_escritor2);

    escritores.listar();
    cout << endl << "Ahora pruebo obtener un escritor. Ingrese el codigo:" << endl;
    int codigo;
    cin >> codigo;
    cout << endl;
    if(escritores.obtener_escritor(codigo) != 0)
        escritores.obtener_escritor(codigo)->mostrar_datos();
    else
        cout << "No hay un escritor con ese codigo" << endl;

    cout << endl << "Ahora eliminamos uno, ingrese al q quiere eliminar" << endl;
    int isni;
    cin >> isni;
    escritores.baja(isni);
    escritores.listar();*/
    return 0;   
}