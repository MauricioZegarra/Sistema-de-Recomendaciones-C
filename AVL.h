#ifndef AVL_H
#define AVL_H
#include<iostream>
#include "Usuario.h"
#include <cmath>
using namespace std;

template <typename T>
class AVL
{
private:
    enum
    {
        IZQUIERDO,
        DERECHO
    };
   class Nodo
    {
    public:
        T *val;
        Nodo *izquierdo;
        Nodo *derecho;
        Nodo *padre;
        int fe; // factor de equilibrio
      
        Nodo(T *v, Nodo *p = NULL) : val(v), izquierdo(NULL), derecho(NULL), padre(p), fe(0) {}
    };
 

    Nodo  *raiz;
    Nodo  *actual;
    int contador;
    int altura;

    void Equilibrar(Nodo *nodo, int rama, bool nuevo)
    {

        bool salir = false;
        while (nodo && !salir)
        {
            if (nuevo)
            {
                if (rama == IZQUIERDO)
                    nodo->fe--;
                else
                    nodo->fe++;
            }
            else
            {
                if (rama == IZQUIERDO)
                    nodo->fe++;
                else
                    nodo->fe--;
            }

            if (nodo->fe == 0)
            {
                salir = true;
            }
            else if (nodo->fe == -2)
            {
                if (nodo->izquierdo->fe == 1)
                    RDD(nodo);
                else
                    RSD(nodo);
                salir = true;
            }
            else if (nodo->fe == 2)
            {
                if (nodo->derecho->fe == -1)
                    RDI(nodo);
                else
                    RSI(nodo);
                salir = true;
            }

            if (nodo->padre)
            {
                if (nodo->padre->derecho == nodo)
                    rama = DERECHO;
                else
                    rama = IZQUIERDO;
            }

            nodo = nodo->padre;
        }
    }
    void RSI(Nodo *nodo)
    {
        Nodo *Padre = nodo->padre;
        Nodo *P = nodo;
        Nodo *Q = P->derecho;
        Nodo *B = Q->izquierdo;

        if (Padre)
        {
            if (Padre->derecho == nodo)
                Padre->derecho = Q;
            else
                Padre->izquierdo = Q;
        }
        else
        {
            raiz = Q;
        }

        P->derecho = B;
        Q->izquierdo = P;

        P->padre = Q;
        if (B)
            B->padre = P;
        Q->padre = Padre;

        P->fe = 0;
        Q->fe = 0;
    }
    void RSD(Nodo *nodo)
    {
        Nodo *Padre = nodo->padre;
        Nodo *P = nodo;
        Nodo *Q = P->izquierdo;
        Nodo *B = Q->derecho;

        if (Padre)
        {
            if (Padre->derecho == nodo)
                Padre->derecho = Q;
            else
                Padre->izquierdo = Q;
        }
        else
        {
            raiz = Q;
        }

        P->izquierdo = B;
        Q->derecho = P;

        P->padre = Q;
        if (B)
            B->padre = P;
        Q->padre = Padre;

        P->fe = 0;
        Q->fe = 0;
    }
    void RDD(Nodo *nodo)
    {
        Nodo *Padre = nodo->padre;
        Nodo *P = nodo;
        Nodo *Q = P->izquierdo;
        Nodo *R = Q->derecho;
        Nodo *B = R->izquierdo;
        Nodo *C = R->derecho;

        if (Padre)
        {
            if (Padre->derecho == nodo)
                Padre->derecho = R;
            else
                Padre->izquierdo = R;
        }
        else
        {
            raiz = R;
        }

        P->izquierdo = C;
        Q->derecho = B;
        R->izquierdo = Q;
        R->derecho = P;

        R->padre = Padre;
        P->padre = R;
        Q->padre = R;
        if (B)
            B->padre = Q;
        if (C)
            C->padre = P;

        switch (R->fe)
        {
        case -1:
            P->fe = 1;
            Q->fe = 0;
            break;
        case 0:
            P->fe = 0;
            Q->fe = 0;
            break;
        case 1:
            P->fe = 0;
            Q->fe = -1;
            break;
        }
        R->fe = 0;
    }
    void RDI(Nodo *nodo)
    {
        Nodo *Padre = nodo->padre;
        Nodo *P = nodo;
        Nodo *Q = P->derecho;
        Nodo *R = Q->izquierdo;
        Nodo *B = R->izquierdo;
        Nodo *C = R->derecho;

        if (Padre)
        {
            if (Padre->derecho == nodo)
                Padre->derecho = R;
            else
                Padre->izquierdo = R;
        }
        else
        {
            raiz = R;
        }

        P->derecho = B;
        Q->izquierdo = C;
        R->izquierdo = P;
        R->derecho = Q;

        R->padre = Padre;
        P->padre = R;
        Q->padre = R;
        if (B)
            B->padre = P;
        if (C)
            C->padre = Q;

        switch (R->fe)
        {
        case -1:
            P->fe = 0;
            Q->fe = 1;
            break;
        case 0:
            P->fe = 0;
            Q->fe = 0;
            break;
        case 1:
            P->fe = -1;
            Q->fe = 0;
            break;
        }
        R->fe = 0;
    }
    void Podar(Nodo *&nodo)
    {
        if (nodo)
        {
            Podar(nodo->izquierdo);
            Podar(nodo->derecho);
            delete nodo;
            nodo = NULL;
        }
    }
    void auxContador(Nodo *nodo)
    {
        if (nodo)
        {
            contador++;
            auxContador(nodo->izquierdo);
            auxContador(nodo->derecho);
        }
    }
    void auxAltura(Nodo *nodo, int a)
    {
        if (nodo)
        {
            auxAltura(nodo->izquierdo, a + 1);
            auxAltura(nodo->derecho, a + 1);
        }
        else if (a > altura)
        {
            altura = a;
        }
    }
    void inOrden(Nodo *nodo)
    {
        if (nodo)
        {
            inOrden(nodo->izquierdo);
            std::cout << *(nodo->val) << "\n";
            inOrden(nodo->derecho);
        }
    }

public:
    AVL(): raiz(NULL), actual(NULL), contador(0), altura(0) {}
    ~AVL()
    {
        Podar(raiz);
    }
    //le quite el puntero
    T* getRaiz(){
        return raiz;
    }
    void Insertar(T* val)
    {
        if (!raiz)
        {
            //quite new Node(val);
            raiz =new Nodo( val);
        }
        else
        {
            Nodo *padre;
            Nodo *aux = raiz;
            while (aux)
            {
                padre = aux;
                if (*val < *(aux->val))
                    aux = aux->izquierdo;
                else
                    aux = aux->derecho;
            }
            if (*val < *(padre->val))
                padre->izquierdo = new Nodo(val, padre);
            else
                padre->derecho = new Nodo(val, padre);
            Equilibrar(padre, 0, true);
        }
        contador++;
    }
    void Borrar(const int id)
    {
        Nodo *nodo = raiz;
        Nodo *padre = NULL;
        Nodo *nodoBorrar = NULL;
        Nodo *aux = NULL;
        Nodo *nodoEquilibrar = NULL;
        int lado;

        // Buscar el nodo a borrar
        while (nodo && *(nodo->val) != id)
        {
            padre = nodo;
            if (id < *(nodo->val))
            {
                nodo = nodo->izquierdo;
                lado = IZQUIERDO;
            }
            else
            {
                nodo = nodo->derecho;
                lado = DERECHO;
            }
        }

        if (!nodo)
            return; // No se encontró el nodo

        nodoBorrar = nodo;

        if (EsHoja(nodo))
        {
            if (padre)
            {
                if (lado == IZQUIERDO)
                    padre->izquierdo = NULL;
                else
                    padre->derecho = NULL;
            }
            else
            {
                raiz = NULL;
            }
            delete nodo;
        }
        else if (nodo->izquierdo && nodo->derecho)
        {
            padre = nodo;
            nodo = nodo->izquierdo;
            lado = IZQUIERDO;

            while (nodo->derecho)
            {
                padre = nodo;
                nodo = nodo->derecho;
                lado = DERECHO;
            }

            *(nodoBorrar->val) = *(nodo->val);
            if (lado == IZQUIERDO)
                padre->izquierdo = nodo->izquierdo;
            else
                padre->derecho = nodo->izquierdo;
            nodoEquilibrar = padre;
            delete nodo;
        }
        else
        {
            if (nodo->izquierdo)
                aux = nodo->izquierdo;
            else
                aux = nodo->derecho;

            if (padre)
            {
                if (lado == IZQUIERDO)
                    padre->izquierdo = aux;
                else
                    padre->derecho = aux;
            }
            else
            {
                raiz = aux;
            }

            aux->padre = padre;
            nodoEquilibrar = padre;
            delete nodo;
        }

        if (nodoEquilibrar)
            Equilibrar(nodoEquilibrar, lado, false);
        contador--;
    }
    T *Buscar(const int id)
    {
        Nodo *aux = raiz;
        while (aux)
        {
            if (id == (aux->val->getID()))
                return aux->val;
            else if (id < (aux->val->getID()))
                aux = aux->izquierdo;
            else
                aux = aux->derecho;
        }
        return NULL;
    }
    
    
    bool Vacio(Nodo *r)
    {
        return r == NULL; 
   
   
    }



 bool  EsHoja(Nodo *r)
{
    return !r->derecho && !r->izquierdo;
}

const int NumeroNodos()
{
    contador = 0;
    auxContador(raiz);
    return contador;
}
const int AlturaArbol()
{
    altura = 0;
    auxAltura(raiz, 0);
    return altura;
}
int Altura(const int id)
{
    Nodo *nodo = raiz;
    int alturaNodo = 0;
    while (nodo)
    {
        if (id == *(nodo->val))
            return alturaNodo;
        else if (id < *(nodo->val))
            nodo = nodo->izquierdo;
        else
            nodo = nodo->derecho;
        alturaNodo++;
    }
    return -1; // No se encontró el nodo
}

T *&ValorActual()
{
    return actual->val;
}
void Raiz()
{
    actual = raiz;
}


void inOrden()
{
    inOrden(raiz);
    std::cout << "\n\n";
}

};


#endif // AVL_H
