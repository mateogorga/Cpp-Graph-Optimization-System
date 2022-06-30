#include "parser_lecturas.h"


const string CUENTO = "C";
const string POEMA = "P";
const string NOVELA = "N";


Parser_lecturas::Parser_lecturas() {}




string Parser_lecturas::obtener_dato(ifstream& archivo, string dato){
    while (dato == "" && !archivo.eof()) 
    {
        getline(archivo, dato);
    }
    return dato;
}


Genero Parser_lecturas::procesar_str_genero(string str_genero){
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
        cout << "carga historica" << endl;
    }
    return genero;
}

char* Parser_lecturas::procesar_tema(string str_tema) {
    unsigned long int largo_tema;
    largo_tema = str_tema.length();
    char* tema = new char[largo_tema + 1];
    for (unsigned long int i = 0; i < largo_tema + 1; i++) {
        tema[i] = str_tema[i];
    }
    return tema;
}

Escritor* Parser_lecturas::procesar_autor(string numero_autor, Hash_escritores& le) {
    int codigo_autor;
    Escritor* p_autor;
    if (numero_autor == "ANONIMO") {
        p_autor = nullptr;
    } else {
        numero_autor = numero_autor.erase(0, 1);
        numero_autor = numero_autor.erase(numero_autor.size() - 1, 1);
        codigo_autor = stoi(numero_autor);
        p_autor = le.obtener_escritor(codigo_autor);
    };
    return p_autor;
}



void Parser_lecturas::cargar_novela(Lista_lecturas& ll, Hash_escritores& le, string titulo, 
                                   string minutos, string anio, Escritor* p_autor, 
                                   Genero genero) {
    int int_minutos = stoi(minutos);
    int int_anio = stoi(anio);
    Novela* n = new Novela(titulo, int_minutos, int_anio, p_autor, genero);
    ll.alta(n, ANIO_L);
}


void Parser_lecturas::cargar_novela_historica(Lista_lecturas& ll, Hash_escritores& le,
                                              string titulo, string minutos, string anio,
                                              Escritor* p_autor, Genero genero, char* tema) {
    int int_minutos = stoi(minutos);
    int int_anio = stoi(anio);
    Historica* h = new Historica(titulo, int_minutos, int_anio, p_autor, genero, tema);
    ll.alta(h, ANIO_L);
}


void Parser_lecturas::extraer_datos_novela(ifstream& archivo, Lista_lecturas& ll,
                                           Hash_escritores& le) {
    string titulo, minutos, anio, str_genero, str_tema, autor;
    Genero genero;
    char* tema;

    getline(archivo, titulo);
    titulo = obtener_dato(archivo, titulo);
    getline(archivo, minutos);
    getline(archivo, anio);
    getline(archivo, str_genero);
    genero = procesar_str_genero(str_genero);
    if (genero == HISTORICA) {
        getline(archivo, str_tema); 
        tema = procesar_tema(str_tema);
    }
    getline(archivo, autor);
    Escritor* p_autor = procesar_autor(autor, le);

    if (genero == HISTORICA) {
        cargar_novela_historica(ll, le, titulo, minutos, anio, p_autor, genero, tema);                        
    } else {
        cargar_novela(ll, le, titulo, minutos, anio, p_autor, genero);
    }
}


void Parser_lecturas::cargar_cuento(Lista_lecturas& ll, Hash_escritores& le, string titulo, 
                                   string minutos, string anio, Escritor* p_autor, 
                                   string titulo_libro) {
    int int_minutos = stoi(minutos);
    int int_anio = stoi(anio);
    Cuento* c = new Cuento(titulo, int_minutos, int_anio, p_autor, titulo_libro);
    ll.alta(c, ANIO_L);
}


void Parser_lecturas::extraer_datos_cuento(ifstream& archivo, Lista_lecturas& ll, 
                                           Hash_escritores& le) {
    string titulo, minutos, anio, titulo_libro, autor;

    getline (archivo, titulo);
    titulo = obtener_dato(archivo, titulo);
    getline(archivo, minutos);
    getline(archivo, anio);
    getline(archivo, titulo_libro);
    getline(archivo, autor);
    Escritor* p_autor = procesar_autor(autor, le);

    cargar_cuento(ll, le, titulo, minutos, anio, p_autor, titulo_libro);
}


void Parser_lecturas::cargar_poema(Lista_lecturas& ll, Hash_escritores& le, string titulo, 
                                   string minutos, string anio, Escritor* p_autor, 
                                   string cantidad_versos) {
    int int_minutos = stoi(minutos);
    int int_anio = stoi(anio);
    int int_cantidad_versos = stoi(cantidad_versos);
    Poema* p = new Poema(titulo, int_minutos, int_anio, p_autor, int_cantidad_versos);
    ll.alta(p, ANIO_L);
}


void Parser_lecturas::extraer_datos_poema(ifstream& archivo, Lista_lecturas& ll, 
                                          Hash_escritores& le) {
    string titulo, minutos, anio, cantidad_versos, autor;

    getline (archivo, titulo);
    titulo = obtener_dato(archivo, titulo);
    getline(archivo, minutos);
    getline(archivo, anio);
    getline(archivo, cantidad_versos);
    getline(archivo, autor);
    Escritor* p_autor = procesar_autor(autor, le);

    cargar_poema(ll, le, titulo, minutos, anio, p_autor, cantidad_versos);
} 


void Parser_lecturas::procesar_datos(ifstream& archivo, Lista_lecturas& ll,
                                        Hash_escritores& le) {
    string palabra;   

    while (archivo >> palabra) {
        if (palabra == NOVELA) {
            extraer_datos_novela(archivo, ll, le);     
        } else if (palabra == CUENTO) {    
            extraer_datos_cuento(archivo, ll, le);            
        } else  if (palabra == POEMA) {
            extraer_datos_poema(archivo, ll, le);
        } 
    }
}

Lista_lecturas Parser_lecturas::cargar_lista_lecturas(string nombre_archivo, 
                                                      Hash_escritores& le){
    ifstream archivo;
    archivo.open(nombre_archivo);
    Lista_lecturas ll = Lista_lecturas();

    if (!archivo) {
        cout << "No se pudo abrir el archivo de lecturas" << endl;
    } else { 
        procesar_datos(archivo, ll, le);
    }
    archivo.close();
    return ll;
}

Parser_lecturas::~Parser_lecturas() {}
