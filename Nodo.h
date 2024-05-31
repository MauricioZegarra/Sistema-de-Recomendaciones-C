#ifndef NODO_H
#define NODO_H

#include "Usuario.h"

class AVL;

class Nodo {
public:
    Nodo(Usuario *usuario, Nodo *pad = NULL, Nodo *izq = NULL, Nodo *der = NULL) :
        usuario(usuario), padre(pad), izquierdo(izq), derecho(der), FE(0) {}

    Usuario *usuario;
    int FE;
    Nodo *izquierdo;
    Nodo *derecho;
    Nodo *padre;
    friend class AVL;
};

#endif // NODO_H

