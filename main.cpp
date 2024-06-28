#include <iostream>
#include "AVL.h"
#include "Usuario.h"
#include "archivo.h"
#include <string>
#include "AlgoritmoRecomendacion.h"
using namespace std;



int main()
{ 
 
    AlgoritmoRecomendacion algo=AlgoritmoRecomendacion();
    algo.fillUsers("ratings_s.csv");
    algo.numberOfUsers();
    algo.hacerComparaciones();
    
    int id;
    char conf;

    do {
        cout << "Id del usuario que quiere recibir recomendaciones: ";
        cin >> id;
        algo.getAvl().Buscar(id)->toString(); 
        cout << endl;
        cout << "\n¿Seguir? (S/N) -> ";
        cin >> conf;
        conf = toupper(conf);
    }
    while (conf == 'S');
    

    return 0;
}
