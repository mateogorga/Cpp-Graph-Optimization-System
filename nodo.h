#ifndef NODO_H
#define NODO_H



template <class Tipo>
class Nodo {
    // Atributos
private:
    Tipo dato;
    Nodo<Tipo>* siguiente;

    // Metodos
public:
    
    //PRE: el dato debe ser del tipo valido.
    //POS: construye un nodo con su respectivo dato.
    Nodo(Tipo dato);
    
    //PRE: -
    //POS: hace que siguiente apunte a n.
    void cambiar_siguiente(Nodo<Tipo>* n);
    Tipo obtener_dato();
    Nodo<Tipo>* obtener_siguiente();
    void cambiar_dato();
    ~Nodo();

};

template <class Tipo>
Nodo<Tipo>::Nodo(Tipo dato) {
    this->dato = dato; 
    siguiente = 0;
}

template <class Tipo>
void Nodo<Tipo>::cambiar_siguiente(Nodo<Tipo>* n) {
    siguiente = n;
}

template <class Tipo>
Tipo Nodo<Tipo>::obtener_dato() {
    return dato;
}

template <class Tipo>
Nodo<Tipo>* Nodo<Tipo>::obtener_siguiente() {
    return siguiente;
}

template <class Tipo>
void Nodo<Tipo>::cambiar_dato() {
    this->dato = nullptr;
}

template <class Tipo>
Nodo<Tipo>::~Nodo() {
    delete dato;
}


#endif // NODO_H
