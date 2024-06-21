#include <iostream>
#include "AVL.h"
#include "Usuario.h"
#include "archivo.h"
#include <string>
#include "AlgoritmoRecomendacion.h"
using namespace std;



int main()
{ 
 
   
   /* string nombreArchivo = "ratings_s.csv";

    Archivo archivo(nombreArchivo);
    archivo.leerArchivo();
    Usuario * a = new Usuario(1,"carlos");
     Usuario *b  = new Usuario (2,"juan");
      Usuario *c= new Usuario (3,"pedro");

    AVL<Usuario> arbol;
    
    arbol.Insertar(a);
    arbol.Insertar(b);
    arbol.Insertar(c);
    arbol.inOrden();*/
    AlgoritmoRecomendacion algo=AlgoritmoRecomendacion();
    algo.fillUsers("ratings_s.csv");
   // algo.printAllDataUser();
    algo.numberOfUsers();
    algo.currentUser();
    

    return 0;
}
