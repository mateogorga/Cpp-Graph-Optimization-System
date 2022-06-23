#include "parser_escritores.h"


const char PRIMER_CARACTER_DE_CODIGO = '(';
const int PRIMER_CARACTER = 0;

Parser_escritores::Parser_escritores() {

}


string Parser_escritores::obtener_dato(ifstream& archivo, string dato){
    while (dato == "" && !archivo.eof()) 
    {
        getline(archivo, dato);
    }
    return dato;
}


string Parser_escritores::verificar_terminacion_abrupta(ifstream& archivo) {
    string fallecimiento, aux; 
        if (archivo >> aux) {
            aux = obtener_dato(archivo, aux);
        } else {
            aux = "-1";
        }
    return aux;
}


string Parser_escritores::verificar_fallecimineto(string aux) {
        string fallecimiento = "-1";
        if (aux[PRIMER_CARACTER] != PRIMER_CARACTER_DE_CODIGO) { 
            fallecimiento = aux;
            aux = "";
        }
    return fallecimiento;
}


void Parser_escritores::crear_enlistar_escritor(string nombre, string nacionalidad, 
                                                string nacimiento, string fallecimiento,
                                                Lista_escritores& l_escritores, 
                                                string codigo_escritor) {
    Escritor* e;
    e =  new Escritor(nombre, nacionalidad, stoi(nacimiento), stoi(fallecimiento), 
                      codigo_escritor);
    int pos = l_escritores.obtener_cantidad() + 1;
    l_escritores.alta(e, pos);
}


string Parser_escritores::verificar_codigo(string aux) {
        if (aux[PRIMER_CARACTER] != PRIMER_CARACTER_DE_CODIGO) { 
        aux = "";
    }
    return aux;
}


string Parser_escritores::extraer_escritor (ifstream& archivo, string codigo_escritor, 
                                            Lista_escritores& l_escritores) {
    string nombre, nacionalidad, nacimiento, fallecimiento, aux;
    bool finEscritor = false;
    while (!archivo.eof() && !finEscritor) {
        codigo_escritor = obtener_dato(archivo, codigo_escritor);
        nombre = obtener_dato(archivo, nombre);
        nacionalidad = obtener_dato(archivo, nacionalidad);
        nacimiento = obtener_dato(archivo, nacimiento);
        aux = verificar_terminacion_abrupta(archivo);
        fallecimiento = verificar_fallecimineto(aux);
        finEscritor = true;
        crear_enlistar_escritor(nombre, nacionalidad, nacimiento, fallecimiento,
                                l_escritores, codigo_escritor);
    }
    codigo_escritor = verificar_codigo(aux);
    return codigo_escritor;
}


void Parser_escritores::procesar_datos(ifstream& archivo, Lista_escritores& l_escritores) {
    string codigo_escritor = "";
    while (!archivo.eof()) {
        codigo_escritor = extraer_escritor(archivo, codigo_escritor, l_escritores);
    }
}


Lista_escritores Parser_escritores::cargar_lista_escritores(string nombre_archivo){
    ifstream archivo;
    archivo.open(nombre_archivo);
    Lista_escritores l_escritores = Lista_escritores();

    if (!archivo) {
        cout << "No se pudo abrir el archivo de escritores" << endl;
    } else {
        procesar_datos(archivo, l_escritores);
    }
    
    archivo.close();
    return l_escritores;
}