#include <iostream>
#include "AVL.h"
#include "Usuario.h"
#include "archivo.cpp"
#include <string>
using namespace std;

void Mostrar(Usuario* &usuario, int FE)
{
    cout << "Usuario ID: " << usuario->id << " (" << FE << "), Calificaciones: [" 
         << usuario->calificaciones[0] << ", " 
         << usuario->calificaciones[1] << ", " 
         << usuario->calificaciones[2] << "]" << endl;
}

int main()
{ 
 /*
    AVL Arbol;

    Usuario *usuarios[] = {
        new Usuario(15, 4, 5, 3),
        new Usuario(6, 2, 3, 4),
        new Usuario(18, 5, 1, 2),
        new Usuario(3, 3, 3, 3),
        new Usuario(7, 1, 4, 5),
        new Usuario(17, 2, 2, 2),
        new Usuario(20, 4, 5, 1),
        new Usuario(2, 5, 5, 5),
        new Usuario(4, 2, 1, 3),
        new Usuario(13, 3, 4, 4),
        new Usuario(9, 1, 2, 3)
    };

    for (int i = 0; i < 11; i++)
        Arbol.Insertar(usuarios[i]);

    cout << "InOrden: " << endl;
    Arbol.InOrden(Mostrar);
    cout << endl;
    cout << "PreOrden: " << endl;
    Arbol.PreOrden(Mostrar);
    cout << endl;
    cout << "PostOrden: " << endl;
    Arbol.PostOrden(Mostrar);
    cout << endl;

    Arbol.Borrar(9);

    cout << "InOrden: " << endl;
    Arbol.InOrden(Mostrar);
    cout << endl;
    cout << "PreOrden: " << endl;
    Arbol.PreOrden(Mostrar);
    cout << endl;
    cout << "PostOrden: " << endl;
    Arbol.PostOrden(Mostrar);
    cout << endl;

    int idBuscado = 18;
    Usuario* usuario1 = Arbol.Buscar(idBuscado);
    if (usuario1 != nullptr) {
        cout << "Usuario encontrado: ID=" << usuario1->id << endl;
        cout << "Usuario ID: " << usuario1->id <<" Calificaciones: [" 
         << usuario1->calificaciones[0] << ", " 
         << usuario1->calificaciones[1] << ", " 
         << usuario1->calificaciones[2] << "]" << endl;
    } else {
        cout << "Usuario con ID=" << idBuscado << " no encontrado." << endl;
    }

    int idBuscado2 = 17;
    Usuario* usuario2 = Arbol.Buscar(idBuscado2);
    if (usuario2 != nullptr) {
        cout << "Usuario encontrado: ID=" << usuario2->id << endl;
        cout << "Usuario ID: " << usuario2->id <<" Calificaciones: [" 
         << usuario2->calificaciones[0] << ", " 
         << usuario2->calificaciones[1] << ", " 
         << usuario2->calificaciones[2] << "]" << endl;
    } else {
        cout << "Usuario con ID=" << idBuscado << " no encontrado." << endl;
    }


    cout << "La distancia euclidiana entre el usuario 18 y 17 es: " << Arbol.DistanciaEuclidiana(18,17)<<endl;

    // Liberar memoria
    for (int i = 0; i < 11; i++)
        delete usuarios[i];
     */


std::string nombreArchivo = "text.txt";
    Archivo archivo(nombreArchivo);
    archivo.leerArchivo();
    return 0;
}
