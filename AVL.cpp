#include "AVL.h"
#include <iostream>
#include <cmath>

using namespace std;

void AVL::Podar(Nodo* &nodo)
{
    if (nodo) {
        Podar(nodo->izquierdo);
        Podar(nodo->derecho);
        delete nodo;
        nodo = NULL;
    }
}

void AVL::Insertar(Usuario *usuario)
{
    Nodo *padre = NULL;

    cout << "Insertar Usuario ID: " << usuario->id << endl;
    actual = raiz;
    while (!Vacio(actual) && usuario->id != actual->usuario->id) {
        padre = actual;
        if (usuario->id > actual->usuario->id) actual = actual->derecho;
        else if (usuario->id < actual->usuario->id) actual = actual->izquierdo;
    }

    if (!Vacio(actual)) return;
    if (Vacio(padre)) raiz = new Nodo(usuario);
    else if (usuario->id < padre->usuario->id) {
        padre->izquierdo = new Nodo(usuario, padre);
        Equilibrar(padre, IZQUIERDO, true);
    }
    else if (usuario->id > padre->usuario->id) {
        padre->derecho = new Nodo(usuario, padre);
        Equilibrar(padre, DERECHO, true);
    }
}

void AVL::Equilibrar(Nodo *nodo, int rama, bool nuevo)
{
    bool salir = false;

    while (nodo && !salir) {
        if (nuevo)
            if (rama == IZQUIERDO) nodo->FE--;
            else nodo->FE++;
        else
            if (rama == IZQUIERDO) nodo->FE++;
            else nodo->FE--;
        if (nodo->FE == 0) salir = true;
        else if (nodo->FE == -2) {
            if (nodo->izquierdo->FE == 1) RDD(nodo);
            else RSD(nodo);
            salir = true;
        }
        else if (nodo->FE == 2) {
            if (nodo->derecho->FE == -1) RDI(nodo);
            else RSI(nodo);
            salir = true;
        }
        if (nodo->padre)
            if (nodo->padre->derecho == nodo) rama = DERECHO; else rama = IZQUIERDO;
        nodo = nodo->padre;
    }
}

void AVL::RDD(Nodo* nodo)
{
    cout << "RDD" << endl;
    Nodo *Padre = nodo->padre;
    Nodo *P = nodo;
    Nodo *Q = P->izquierdo;
    Nodo *R = Q->derecho;
    Nodo *B = R->izquierdo;
    Nodo *C = R->derecho;

    if (Padre)
        if (Padre->derecho == nodo) Padre->derecho = R;
        else Padre->izquierdo = R;
    else raiz = R;

    Q->derecho = B;
    P->izquierdo = C;
    R->izquierdo = Q;
    R->derecho = P;

    R->padre = Padre;
    P->padre = Q->padre = R;
    if (B) B->padre = Q;
    if (C) C->padre = P;

    switch (R->FE) {
    case -1: Q->FE = 0; P->FE = 1; break;
    case 0:  Q->FE = 0; P->FE = 0; break;
    case 1:  Q->FE = -1; P->FE = 0; break;
    }
    R->FE = 0;
}

void AVL::RDI(Nodo* nodo)
{
    cout << "RDI" << endl;
    Nodo *Padre = nodo->padre;
    Nodo *P = nodo;
    Nodo *Q = P->derecho;
    Nodo *R = Q->izquierdo;
    Nodo *B = R->izquierdo;
    Nodo *C = R->derecho;

    if (Padre)
        if (Padre->derecho == nodo) Padre->derecho = R;
        else Padre->izquierdo = R;
    else raiz = R;

    P->derecho = B;
    Q->izquierdo = C;
    R->izquierdo = P;
    R->derecho = Q;

    R->padre = Padre;
    P->padre = Q->padre = R;
    if (B) B->padre = P;
    if (C) C->padre = Q;

    switch (R->FE) {
    case -1: P->FE = 0; Q->FE = 1; break;
    case 0:  P->FE = 0; Q->FE = 0; break;
    case 1:  P->FE = -1; Q->FE = 0; break;
    }
    R->FE = 0;
}

void AVL::RSD(Nodo* nodo)
{
    cout << "RSD" << endl;
    Nodo *Padre = nodo->padre;
    Nodo *P = nodo;
    Nodo *Q = P->izquierdo;
    Nodo *B = Q->derecho;

    if (Padre)
        if (Padre->derecho == P) Padre->derecho = Q;
        else Padre->izquierdo = Q;
    else raiz = Q;

    P->izquierdo = B;
    Q->derecho = P;

    P->padre = Q;
    if (B) B->padre = P;
    Q->padre = Padre;

    P->FE = 0;
    Q->FE = 0;
}

void AVL::RSI(Nodo* nodo)
{
    cout << "RSI" << endl;
    Nodo *Padre = nodo->padre;
    Nodo *P = nodo;
    Nodo *Q = P->derecho;
    Nodo *B = Q->izquierdo;

    if (Padre)
        if (Padre->derecho == P) Padre->derecho = Q;
        else Padre->izquierdo = Q;
    else raiz = Q;

    P->derecho = B;
    Q->izquierdo = P;

    P->padre = Q;
    if (B) B->padre = P;
    Q->padre = Padre;

    P->FE = 0;
    Q->FE = 0;
}

void AVL::Borrar(const int id)
{
    Nodo *padre = NULL;
    Nodo *nodo;
    Usuario *aux;

    actual = raiz;
    while (!Vacio(actual)) {
        if (id == actual->usuario->id) {
            if (EsHoja(actual)) {
                if (padre) {
                    if (padre->derecho == actual) padre->derecho = NULL;
                    else if (padre->izquierdo == actual) padre->izquierdo = NULL;
                }
                delete actual;
                actual = NULL;
                if ((padre && padre->derecho == actual && padre->FE == 1) || (padre && padre->izquierdo == actual && padre->FE == -1)) {
                    padre->FE = 0;
                    actual = padre;
                    padre = actual->padre;
                }
                if (padre) {
                    if (padre->derecho == actual) Equilibrar(padre, DERECHO, false);
                    else Equilibrar(padre, IZQUIERDO, false);
                }
                return;
            }
            else {
                padre = actual;
                if (actual->derecho) {
                    nodo = actual->derecho;
                    while (nodo->izquierdo) {
                        padre = nodo;
                        nodo = nodo->izquierdo;
                    }
                }
                else {
                    nodo = actual->izquierdo;
                    while (nodo->derecho) {
                        padre = nodo;
                        nodo = nodo->derecho;
                    }
                }
                aux = actual->usuario;
                actual->usuario = nodo->usuario;
                nodo->usuario = aux;
                actual = nodo;
            }
        }
        else {
            padre = actual;
            if (id > actual->usuario->id) actual = actual->derecho;
            else if (id < actual->usuario->id) actual = actual->izquierdo;
        }
    }
}


Usuario* AVL::Buscar(const int id)
{
    actual = raiz;

    while (!Vacio(actual)) {
        if (id == actual->usuario->id) return actual->usuario;
        else if (id > actual->usuario->id) actual = actual->derecho;
        else if (id < actual->usuario->id) actual = actual->izquierdo;
    }

    return nullptr;
}

const int AVL::NumeroNodos()
{
    contador = 0;
    auxContador(raiz);
    return contador;
}

void AVL::auxContador(Nodo *nodo)
{
    if (nodo) {
        auxContador(nodo->izquierdo);
        auxContador(nodo->derecho);
        contador++;
    }
}

const int AVL::AlturaArbol()
{
    altura = 0;
    auxAltura(raiz, 0);
    return altura;
}

void AVL::auxAltura(Nodo *nodo, int a)
{
    if (nodo) {
        auxAltura(nodo->izquierdo, a + 1);
        auxAltura(nodo->derecho, a + 1);
    }
    if (a > altura) altura = a;
}

int AVL::Altura(const int id)
{
    int altura = 0;
    actual = raiz;

    while (!Vacio(actual)) {
        if (id == actual->usuario->id) return altura;
        else {
            altura++;
            if (id > actual->usuario->id) actual = actual->derecho;
            else if (id < actual->usuario->id) actual = actual->izquierdo;
        }
    }
    return -1;
}

double AVL::DistanciaEuclidiana(const int id1, const int id2) {
    Usuario* usuario1 = Buscar(id1);
    Usuario* usuario2 = Buscar(id2);

    // Verificar si ambos usuarios existen en el árbol
    if (usuario1 == nullptr || usuario2 == nullptr) {
        return -1; // Indicar que uno o ambos usuarios no fueron encontrados
    }

    // Obtener las calificaciones de ambos usuarios
    int* calificacionesUsuario1 = usuario1->calificaciones;
    int* calificacionesUsuario2 = usuario2->calificaciones;

    // Calcular la distancia euclidiana
    double distancia = 0.0;
    for (int i = 0; i < 3; ++i) { // Suponiendo que siempre son 3 calificaciones
        distancia += pow(calificacionesUsuario1[i] - calificacionesUsuario2[i], 2);
    }

    return sqrt(distancia);
}

void AVL::InOrden(void (*func)(Usuario*&, int), Nodo *nodo, bool r)
{
    if (r) nodo = raiz;
    if (nodo->izquierdo) InOrden(func, nodo->izquierdo, false);
    func(nodo->usuario, nodo->FE);
    if (nodo->derecho) InOrden(func, nodo->derecho, false);
}

void AVL::PreOrden(void (*func)(Usuario*&, int), Nodo *nodo, bool r)
{
    if (r) nodo = raiz;
    func(nodo->usuario, nodo->FE);
    if (nodo->izquierdo) PreOrden(func, nodo->izquierdo, false);
    if (nodo->derecho) PreOrden(func, nodo->derecho, false);
}

void AVL::PostOrden(void (*func)(Usuario*&, int), Nodo *nodo, bool r)
{
    if (r) nodo = raiz;
    if (nodo->izquierdo) PostOrden(func, nodo->izquierdo, false);
    if (nodo->derecho) PostOrden(func, nodo->derecho, false);
    func(nodo->usuario, nodo->FE);
}
