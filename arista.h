
#ifndef TP3_MAIN_ARISTA_H
#define TP3_MAIN_ARISTA_H
#include <vector>
#include <algorithm>
#include <iostream>
#include <string.h>
#include "lectura.h"

using namespace std;

class Arista {
    int vertice1, vertice2, peso;

public:
    //PRE: Recibe dos enteros correspondientes a los vertices y un peso.
    //POST: Crea una arista.
    Arista(int v1, int v2, int peso);
    int obtener_vertice1();
    int obtener_vertice2();
    int obtener_peso();


    //PRE: Recibe una arista.
    //POST: Compara el peso de las aristas.
    bool operator < (const Arista& arista2) const;
};

#endif //TP3_MAIN_ARISTA_H
