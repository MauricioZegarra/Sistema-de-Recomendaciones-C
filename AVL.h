#ifndef AVL_H
#define AVL_H

#include "Nodo.h"
#include "Usuario.h"

class AVL {
private:
    enum { IZQUIERDO, DERECHO };
    Nodo *raiz;
    Nodo *actual;
    int contador;
    int altura;

public:
    AVL() : raiz(NULL), actual(NULL) {}
    ~AVL() { Podar(raiz); }
    void Insertar(const int dat);
    void Insertar(Usuario *usuario);
    void Borrar(const int id);
    Usuario* Buscar(const int id);
    bool Vacio(Nodo *r) { return r == NULL; }
    bool EsHoja(Nodo *r) { return !r->derecho && !r->izquierdo; }
    const int NumeroNodos();
    const int AlturaArbol();
    int Altura(const int id);
    double DistanciaEuclidiana(const int id1, const int id2);
    int &ValorActual() { return actual->usuario->id; }
    void Raiz() { actual = raiz; }
    void InOrden(void (*func)(Usuario*&, int), Nodo *nodo = NULL, bool r = true);
    void PreOrden(void (*func)(Usuario*&, int), Nodo *nodo = NULL, bool r = true);
    void PostOrden(void (*func)(Usuario*&, int), Nodo *nodo = NULL, bool r = true);

private:
    void Equilibrar(Nodo *nodo, int, bool);
    void RSI(Nodo* nodo);
    void RSD(Nodo* nodo);
    void RDI(Nodo* nodo);
    void RDD(Nodo* nodo);
    void Podar(Nodo* &);
    void auxContador(Nodo*);
    void auxAltura(Nodo*, int);
};

#endif // AVL_H

