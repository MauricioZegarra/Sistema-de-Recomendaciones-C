#ifndef NODO_H
#define NODO_H

#include "Usuario.h"

class AVL;
template <typename T>
class Nodo {

public:
    Nodo(T*val, Nodo *pad = NULL, Nodo *izq = NULL, Nodo *der = NULL) : val(val), padre(pad), izquierdo(izq), derecho(der), FE(0) {}

    T *val;
    int FE;
    Nodo *izquierdo;
    Nodo *derecho;
    Nodo *padre;
    friend class AVL;
};

#endif // NODO_H

