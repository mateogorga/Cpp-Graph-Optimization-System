#include "menu.h"
#include <stdlib.h>
#include <cstdlib>


const int SI = 1;
const int NO = 2;
const int PRIMER_GENERO = 1;
const int ULTIMO_GENERO = 6;
const int MENU_OPCION_1 = 1;
const int MENU_OPCION_ULTIMA = 15;
const int NOVELA = 1;
const int CUENTO = 2;
const int POEMA = 3;

Menu::Menu(){

}

void Menu::ejecutar_menu(Menu menu, Lista_lecturas& l_lecturas, Hash_escritores& t_escritores,
                        Cola& cola, Lista_lecturas& lista_aux, Grafo& grafo){
    bool terminar_programa = false;
    int respuesta;
    while (!terminar_programa) {
        respuesta = menu.mostrar_menu();

        switch (respuesta) {
            case 1:
                menu.agregar_lectura(l_lecturas, t_escritores, grafo);
                break;
            case 2:
                menu.quitar_lectura(l_lecturas, grafo);
                break;
            case 3:
                menu.agregar_escritor(t_escritores);
                break;
            case 4:
                menu.cambiar_fallecimiento(t_escritores);
                break;
            case 5:
                menu.listar_escritores(t_escritores);
                break;
            case 6:
                menu.lectura_random(l_lecturas)->mostrar_datos();
                break;
            case 7:
                menu.listar_lecturas(l_lecturas);
                break;
            case 8:
                menu.listar_lecturas_entre_anios(l_lecturas);
                break;
            case 9:
                menu.listar_lecturas_por_escritor(l_lecturas, t_escritores);
                break;
            case 10:
                menu.listar_novelas_por_genero(l_lecturas);
                break;
            case 11:
                menu.lecturas_en_cola(l_lecturas, cola, lista_aux);
                
                break;
            case 12:
                menu.lectura_leida(cola);
                break;
            case 13:
                grafo.kruskal();
                break;

            case 14:
                menu.eliminar_escritor(t_escritores, l_lecturas);
                break;

            case 15:
                terminar_programa = true;
                break;

            default:
                break;
        }
    }
}


void Menu::mensaje_inicial() {
    string enter;
    cout << "\033[H\033[2J\033[3J" ;
    cout << "BIENVENIDOS A LOS MIL Y UN MARTES Y JUEVES" << endl << endl;
    cout << "Este programa especialmente diseniado para lectores y clubs de lecturas" << endl;
    cout << "le permitira organizar eficientemente la informacion" << endl;
    cout << "sobre sus lecturas y escritores favoritos." << endl;
    cout << "Desde crear y administrar listas de lecturas y escritores en tiempo real, " << endl;
    cout << "hasta crearse una cola de lecturas ordenadas por tiempo." << endl;
    cout << "Para interactuar con el programa tan solo debe ingresar por consola " << endl;
    cout << "el numero de la accion que desea realizar." << endl;
    cout << endl << endl;
    cout << "Ingrese cualquier letra seguida de enter para continuar . . ." << endl << endl;
    cin >> enter;
    cout << "\033[H\033[2J\033[3J" ;
}

bool Menu::chequear_rango(int a, int x, int b) {
    return (a <= x && b >= x);
}


int Menu::mostrar_menu() {
    bool respuesta_correcta = false;
    int respuesta;

    while (!respuesta_correcta) {
        cout << endl << endl;
        cout << "Ingrese el numero de la opcion que desee: " << endl;
        cout << "ENTRE 1 Y 14" << endl;
        cout << "1) Agregar una nueva lectura a la lista " << endl;
        cout << "2) Quitar una lectura de la lista " << endl;
        cout << "3) Agregar un escritor " << endl;
        cout << "4) Cambiar fecha de fallecimiento de un escritor " << endl;
        cout << "5) Listar los escritores " << endl;
        cout << "6) Sortear una lectura random para leer en una de las tertulias " << endl;
        cout << "7) Listar las lecturas " << endl;
        cout << "8) Listar las lecturas entre determinados años " << endl;
        cout << "9) Listar las lecturas de un determinado escritor que ingresa el usuario " << endl;
        cout << "10) Listar las novelas de determinado género " << endl;
        cout << "11) Armar una cola ordenada por tiempo de lectura " << endl;
        cout << "12) Lectura leida " << endl;
        cout << "13) Mostrar orden óptimo de lecturas y sus caminos" << endl;
        cout << "14) Eliminar escritor" << endl;
        cout << "15) Salir" << endl;
        cin >> respuesta;
        cin.ignore();

        respuesta_correcta = chequear_rango(MENU_OPCION_1, respuesta, MENU_OPCION_ULTIMA);
        if (!respuesta_correcta)
            cout << "LO LAMENTO, LA RESPUESTA DEBE SER ENTRE 1 Y 14" << endl;
    }
    return respuesta;
}

void Menu::pedir_datos_lectura(string &titulo, int &minutos, int &anio, int &int_tipo) {
    cout << "Ingrese el titulo: "<< endl;
    cin.ignore();
    getline(cin, titulo);
    cout << "Ingrese la cantidad de minutos: "<< endl;
    cin >> minutos;
    cout << "Ingrese el anio de publicacion: "<< endl;
    cin >> anio;
    cout << "Ingrese el tipo de lectura (el numero): "<< endl;
    cout << "1)Novela\n2)Cuento\n3)Poema"<< endl;
    cin >> int_tipo;
    while((int_tipo != NOVELA) && (int_tipo != CUENTO) && (int_tipo != POEMA)){
        cout << endl << "Entrada invalida. Por favor, ingrese un valor de los indicados." << endl;
        cin >> int_tipo;
    }
}

void Menu::cargar_novela(Lista_lecturas &l_lecturas, string titulo, int minutos, int anio, Escritor* autor, string str_genero, Grafo& grafo) {
    cout <<"Ingrese uno de estos generos, todo en mayusculas: " << endl;
    cout << "DRAMA" << endl;
    cout << "FICCION" << endl;
    cout << "SUSPENSO" << endl;
    cout << "TERROR" << endl;
    cout << "ROMANTICA" << endl;
    cout << "HISTORICA" << endl;
    cin >> str_genero;
    Genero genero = procesar_str_genero(str_genero);


    if (str_genero == "HISTORICA") {
        string str_tema;
        cout<<"Ingrese el tema: ";
        cin.ignore();
        getline(cin, str_tema);
        char* tema = procesar_tema_historica(str_tema);
        Historica* nueva_lectura = new Historica(titulo,minutos,anio,autor,HISTORICA,tema);
        l_lecturas.alta(nueva_lectura, ANIO_L);
        grafo.cargar_grafo(nueva_lectura);
    } else {
        Novela* nueva_lectura = new Novela(titulo,minutos,anio,autor,genero);
        l_lecturas.alta(nueva_lectura, ANIO_L);
        grafo.cargar_grafo(nueva_lectura);
    }

}


Genero Menu::procesar_str_genero(string str_genero) {
    Genero genero;
    if (str_genero == "DRAMA") {
        genero = DRAMA;
    } else if (str_genero == "FICCION") {
        genero = FICCION;
    } else if (str_genero == "SUSPENSO") {
        genero = SUSPENSO;
    } else if (str_genero == "TERROR") {
        genero = TERROR;
    } else if (str_genero == "ROMANTICA") {
        genero = ROMANTICA;
    } else if (str_genero == "HISTORICA") {
        genero = HISTORICA;
    }

    return genero;
}


char* Menu::procesar_tema_historica(string str_tema) {
    unsigned long int largo_tema;
    largo_tema = str_tema.length();
    char* tema = new char[largo_tema + 1];
    for (unsigned long int i = 0; i < largo_tema + 1; i++) {
        tema[i] = str_tema[i];
    }
    return tema;
}


void Menu::cargar_cuento(Lista_lecturas &l_lecturas, string titulo, int minutos, int anio, Escritor* autor, Grafo& grafo) {
    string str_libro;
    cout<<"Ingrese el libro en el que se encuentra el cuento: ";
    cin.ignore();
    getline(cin, str_libro);
    Cuento* nueva_lectura = new Cuento(titulo,minutos,anio,autor,str_libro);
    l_lecturas.alta(nueva_lectura, ANIO_L);
    grafo.cargar_grafo(nueva_lectura);
}


void Menu::cargar_poema(Lista_lecturas &l_lecturas, string titulo, int minutos, int anio, Escritor* autor, Grafo& grafo) {
    int cant_versos;
    cout<< "Ingrese la cantidad de versos: ";
    cin >> cant_versos;

    Poema* nueva_lectura = new Poema(titulo, minutos, anio, autor, cant_versos);
    l_lecturas.alta(nueva_lectura, ANIO_L);
    grafo.cargar_grafo(nueva_lectura);
}


 void Menu::quitar_lectura(Lista_lecturas &l_lecturas, Grafo& grafo) {
    l_lecturas.listar();
    int cota_sup = l_lecturas.obtener_cantidad();
    int posicion;
    bool posicion_valida = false;
    bool cero_lecturas = false;
    cout << endl << "Ingrese el numero de la lectura a quitar " << endl;
    cin >> posicion;
    posicion_valida = chequear_rango(1, posicion, cota_sup);
    while (!posicion_valida) {
        if (!cota_sup == 0) {
            cout << "La posicion ingresada es invalida, debe ser entre 1 y " << cota_sup << endl;
            cout << endl << "Ingrese el numero de la lectura a quitar " << endl;
            cin >> posicion;
            posicion_valida = chequear_rango(1, posicion, cota_sup);
        } else {
            cout << "No hay mas lecturas" << endl;
            posicion_valida = true;
            cero_lecturas = true;
        }       
    }
    if (!cero_lecturas) {
        grafo.eliminar_lectura(l_lecturas.consulta(posicion)->obtener_titulo());
        l_lecturas.baja(posicion);
    }
}

void Menu::agregar_lectura(Lista_lecturas &l_lecturas, Hash_escritores& t_escritores, Grafo& grafo) {
    string titulo, autor, str_genero;
    int minutos, anio, int_tipo;
    cout << "El autor de la lectura que desea agregar ya se encuentra en la tabla de escritores?" << endl;
    cout << "1.Si       2.No" << endl;
    int respuesta1;
    cin >> respuesta1;
    while((respuesta1 != SI) && (respuesta1 != NO)) {
        cout << "Entrada invalida. Por favor, ingrese '1' para si y '2' para no." << endl;
        cin >> respuesta1;
    }
    Escritor* pescritor = asignar_escritor(t_escritores, respuesta1);
    cout << endl << "Ahora si se le pediran los datos de la lectura." << endl << endl;
    pedir_datos_lectura(titulo, minutos, anio, int_tipo);
    if (int_tipo == 1) {
        cargar_novela(l_lecturas,titulo,minutos,anio,pescritor,str_genero, grafo);
    } else if (int_tipo == 2) {
        cargar_cuento(l_lecturas,titulo,minutos,anio,pescritor, grafo);
    } else {
        cargar_poema(l_lecturas,titulo,minutos,anio,pescritor, grafo);
    }
}


Escritor* Menu::asignar_escritor(Hash_escritores& t_escritores, int& respuesta1){
    Escritor* pescritor;
    if(respuesta1 == NO) {
        cout << endl << "Entonces es necesario que agregue la informacion del autor." << endl;
        pescritor = agregar_devolver_escritor(t_escritores);
    } else if (respuesta1 == SI){
        t_escritores.listar_segun_codigo();
        cout << endl;
        cout << "Ingrese el ISNI del escritor correspondiente" << endl;
        int respuesta2;
        cin >> respuesta2;
        while (t_escritores.obtener_escritor(respuesta2) == 0) { 
            cout << "El ISNI ingresado no corresponde a ningun escritor. Por favor ingrese uno valido" << endl;
            cin >> respuesta2;
        } 
        pescritor = t_escritores.obtener_escritor(respuesta2);
    }
    return pescritor;
}


void Menu::pedir_datos_escritor(string &nombre_comp, string &nacionalidad, int &nacimiento, int &fallecimiento, string& isni) {
    cout << "Ingrese el nombre completo del escritor: " << endl;
    cin.ignore();
    getline(cin, nombre_comp);
    cout << "Ingrese la nacionalidad del escritor: " << endl;
    getline(cin, nacionalidad);
    cout << "Ingrese el anio de nacimiento: " << endl;
    cin >> nacimiento;
    cout << "Ingrese el anio de fallecimiento. Si el escritor se encuentra vivo, ingrese -1" << endl;
    cin >> fallecimiento;
    cout << "Ingrese el ISNI del escritor: " << endl;
    cin >> isni;
}


Escritor* Menu::agregar_devolver_escritor(Hash_escritores& t_escritores) {
    string nombre_comp, nacionalidad, isni;
    int nacimiento, fallecimiento;
    pedir_datos_escritor(nombre_comp, nacionalidad, nacimiento, fallecimiento, isni);
    Escritor* nuevo_escritor = new Escritor(nombre_comp, nacionalidad, nacimiento, fallecimiento, isni);
    t_escritores.alta(nuevo_escritor);
    return nuevo_escritor;
}


void Menu::agregar_escritor(Hash_escritores& t_escritores) {
    string nombre_comp, nacionalidad, isni;
    int nacimiento, fallecimiento;
    pedir_datos_escritor(nombre_comp, nacionalidad, nacimiento, fallecimiento, isni);
    Escritor* nuevo_escritor = new Escritor(nombre_comp, nacionalidad, nacimiento, fallecimiento, isni);
    t_escritores.alta(nuevo_escritor);
}


void Menu::cambiar_fallecimiento(Hash_escritores& t_escritores) {
    t_escritores.listar();
    int isni;
    cout << endl << "Ingrese el ISNI del escritor al que le desea cambiar el anio" << endl;
    cin >> isni;
    if(t_escritores.obtener_escritor(isni) == 0)
        cout << "El ISNI ingresado no corresponde a ningun escritor." << endl;
    else{
        cout << "Ingrese el anio de fallecimiento a agregar: " << endl; 
        int anio;
        cin >> anio;
        t_escritores.obtener_escritor(isni)->cambiar_fallecimiento(anio);
    }
}


void Menu::listar_escritores(Hash_escritores& t_escritores){ 
    t_escritores.listar();
}


void Menu::listar_lecturas(Lista_lecturas& l_lecturas) {
    l_lecturas.listar();
}


void Menu::listar_lecturas_por_escritor(Lista_lecturas& l_lecturas, 
                                        Hash_escritores& t_escritores) {
    
    int respuesta;
    t_escritores.listar_segun_codigo();
    cout << endl;
    cout << "Ingrese el ISNI del escritor cuyas lecturas desea listar" << endl;
    cout << "(En caso de que el autor no posea ninguna novela escrita, el";
    cout << " campo permancera vacio)" << endl;
    cin >> respuesta;
    if (t_escritores.obtener_escritor(respuesta) == 0) { 
        cout << "El ISNI ingresado no corresponde a ningun escritor" << endl;
    } else {
        int i = 1;
        while (i <= l_lecturas.obtener_cantidad()) {
            if (l_lecturas.consulta(i)->obtener_autor() 
                && respuesta == stoi(l_lecturas.consulta(i)->obtener_autor()->obtener_codigo())) {
                cout << endl;
                l_lecturas.consulta(i)->mostrar_datos();
            }
            i++; 
        }
    }
}


void Menu::listar_novelas_por_genero(Lista_lecturas& l_lecturas) {
    bool respuesta_correcta = false;
    int genero_numero;
    cout << "Ingrese el numero del genero cuyas lecturas desea listar" << endl;
    cout<< "1: DRAMA" << endl;
    cout<< "2: FICCION" << endl;
    cout<< "3: SUSPENSO" << endl;
    cout<< "4: TERROR" << endl;
    cout<< "5: ROMANTICA" << endl;
    cout<< "6: HISTORICA" << endl;
    cin >> genero_numero;
    respuesta_correcta = chequear_rango(PRIMER_GENERO, genero_numero, ULTIMO_GENERO);

    while (!respuesta_correcta) {
        cout << "LO LAMENTO, LA RESPUESTA DEBE SER ENTRE 1 Y 6" << endl;
        cin >> genero_numero;
        respuesta_correcta = chequear_rango(PRIMER_GENERO, genero_numero, ULTIMO_GENERO);
    }

    genero_numero--;
    int i = 1;
    string genero_numero1 = to_string(genero_numero);
    while (i <= l_lecturas.obtener_cantidad()) {
        l_lecturas.consulta(i)->mostrar_segun_parametro(genero_numero1);
        cout << endl;
        i++;
    }
}



void Menu::lecturas_en_cola(Lista_lecturas& l_lecturas, Cola& cola, Lista_lecturas& lista_aux) {
    Lectura* actual;

    int cant = l_lecturas.obtener_cantidad();
    for(int i = 1; i <= cant; i++) {
        if(l_lecturas.consulta(i)->obtener_titulo() != l_lecturas.consulta(i - 1)->obtener_titulo()) {
            actual = l_lecturas.consulta(i);
            lista_aux.alta(actual, MINUTOS_L);
        }

    }
    traspasar_lecturas(cola, lista_aux);
    cout << endl <<"La cola de lecturas se creo correctamente. La primer lectura que debe leer es: " << endl << endl;
    
        cola.consulta()->mostrar_datos();
}


void Menu::traspasar_lecturas(Cola& cola, Lista_lecturas& lista_aux) {
    int cant = lista_aux.obtener_cantidad();

    for(int i = 1; i <= cant; i++) {
        cola.alta(lista_aux.consulta(i));
    }

    for( int i = 1; i <= cant; i++) {
        lista_aux.obtener_nodo(i)->cambiar_dato();
        delete lista_aux.consulta(i);
    }

}

void Menu::lectura_leida(Cola& cola) {
    
    if (!cola.vacia()) {
        cout << endl << "La lectura que tenia pendiente es: " << endl << endl;
        cola.consulta()->mostrar_datos();
        cout << endl << "Esta lectura ya fue leida? Ingrese el numero de su respuesta." << endl;
        cout << "1.Si      2.No" << endl;
        int respuesta;
        cin >> respuesta;
        if(respuesta == SI) {
            cola.baja();
            cout << endl << "La siguiente lectura que debe leer es: " << endl << endl;
            if (!cola.vacia())
                cola.consulta()->mostrar_datos();
        } else if (respuesta != SI && respuesta != NO) {
            cout << "La respuesta ingresada es invalida." << endl;
        }
        
    } else 
        cout << endl << "No quedan lecturas pendientes en la cola" << endl;
}


Lectura* Menu::lectura_random(Lista_lecturas &l_lecturas) {
    int cant_lecturas = l_lecturas.obtener_cantidad();

    int posicion = 1+rand()%(cant_lecturas-1);

    return l_lecturas.consulta(posicion);
}

void Menu::listar_lecturas_entre_anios(Lista_lecturas &l_lecturas) {
    int desde;
    int hasta;
    int contador = 1;
    int cant_lecturas = l_lecturas.obtener_cantidad();

    cout << "Ingrese el primer anio: ";
    cin >> desde;
    cout << "Ingrese el segundo anio: ";
    cin >> hasta;

    while (cant_lecturas >= contador) {
        if (l_lecturas.consulta(contador)->obtener_anio() >= desde and l_lecturas.consulta(contador)->obtener_anio()<=hasta) {
            cout << endl;
            l_lecturas.consulta(contador)->mostrar_datos();
        }
        contador++;
    }
}

void Menu::eliminar_escritor(Hash_escritores& t_escritores, Lista_lecturas& l_lecturas){
    t_escritores.listar_segun_codigo();
    cout << endl << "Ingrese el ISNI del escritor que desea eliminar" << endl;
    int isni;
    cin >> isni;
    if(t_escritores.obtener_escritor(isni) == 0)
        cout << "El ISNI ingresado no corresponde a ningun escritor." << endl;
    else {
        l_lecturas.modificar_escritor(t_escritores.obtener_escritor(isni));
        t_escritores.baja(isni);
    }
}