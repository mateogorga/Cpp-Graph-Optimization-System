#include <vector>
#include <algorithm>
#include <iostream>
#include <string.h>
#include "arista.h"

using namespace std;

Arista::Arista(int v1, int v2, int peso) {
    vertice1 = v1;
    vertice2 = v2;
    this->peso = peso;
}

int Arista::obtener_vertice1() {
    return vertice1;
}

int Arista::obtener_vertice2() {
    return vertice2;
}

int Arista::obtener_peso() {
    return peso;
}

bool Arista::operator<(const Arista &arista2) const {
    return (peso < arista2.peso);
}
