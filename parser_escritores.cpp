#include "parser_escritores.h"


const char PRIMER_CARACTER_DE_CODIGO = '(';
const int PRIMER_CARACTER = 0;

Parser_escritores::Parser_escritores() {

}


string Parser_escritores::obtener_datito(ifstream& archivo, string datito){
    while (datito == "" && !archivo.eof()) {
        getline(archivo, datito);
    }
    return datito;
}


string Parser_escritores::verificar_terminacion_abrupta(ifstream& archivo) {
    string fallecimiento, aux; 
        if (archivo >> aux) {
            aux = obtener_datito(archivo, aux);
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
                                                Hash_escritores& t_escritores, 
                                                string codigo_escritor) {
    
    codigo_escritor = codigo_escritor.erase(0, 1);
    codigo_escritor = codigo_escritor.erase(codigo_escritor.size() - 1, 1);
    Escritor* e;
    e =  new Escritor(nombre, nacionalidad, stoi(nacimiento), stoi(fallecimiento), 
                      codigo_escritor);
    t_escritores.alta(e);
}


string Parser_escritores::verificar_codigo(string aux) {
        if (aux[PRIMER_CARACTER] != PRIMER_CARACTER_DE_CODIGO) { 
        aux = "";
    }
    return aux;
}


string Parser_escritores::extraer_escritor (ifstream& archivo, string codigo_escritor, 
                                            Hash_escritores& t_escritores) {
    string nombre, nacionalidad, nacimiento, fallecimiento, aux;
    bool finEscritor = false;
    while (!archivo.eof() && !finEscritor) {
        codigo_escritor = obtener_datito(archivo, codigo_escritor);
        nombre = obtener_datito(archivo, nombre);
        nacionalidad = obtener_datito(archivo, nacionalidad);
        nacimiento = obtener_datito(archivo, nacimiento);
        aux = verificar_terminacion_abrupta(archivo);
        fallecimiento = verificar_fallecimineto(aux);
        finEscritor = true;
        crear_enlistar_escritor(nombre, nacionalidad, nacimiento, fallecimiento,
                                t_escritores, codigo_escritor);
    }
    codigo_escritor = verificar_codigo(aux);
    return codigo_escritor;
}


void Parser_escritores::procesar_datos(ifstream& archivo, Hash_escritores& t_escritores) {
    string codigo_escritor = "";
    while (!archivo.eof()) {
        codigo_escritor = extraer_escritor(archivo, codigo_escritor, t_escritores);
    }
}


Hash_escritores Parser_escritores::cargar_lista_escritores(string nombre_archivo){
    ifstream archivo;
    archivo.open(nombre_archivo);
    Hash_escritores t_escritores = Hash_escritores();

    if (!archivo) {
        cout << "No se pudo abrir el archivo de escritores" << endl;
    } else {
        procesar_datos(archivo, t_escritores);
    }
    
    archivo.close();
    return t_escritores;
}