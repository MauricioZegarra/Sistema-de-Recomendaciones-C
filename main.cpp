#include <iostream>

#include "Usuario.h"

#include <string>
#include "AlgoritmoRecomendacion.h"
using namespace std;

int main()
{ 
    AlgoritmoRecomendacion algo;
    algo.fillUsers("ratings_s.csv");
    cout << "Número total de usuarios: " << algo.getAvl().NumeroNodos() << endl;
    algo.hacerComparaciones();
    
    int id;
    char conf;

    do {
        cout << "Id del usuario que quiere recibir recomendaciones: ";
        cin >> id;
        Usuario* user = algo.getAvl().Buscar(id);
        if (user) {
            user->toString();
        } else {
            cout << "Usuario no encontrado. ID buscado: " << id << endl;
            cout << "Número total de usuarios en el árbol: " << algo.getAvl().NumeroNodos() << endl;
        }
        cout << endl;
        cout << "\n¿Seguir? (S/N) -> ";
        cin >> conf;
        conf = toupper(conf);
    } while (conf == 'S');

    return 0;
}
