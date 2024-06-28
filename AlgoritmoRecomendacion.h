#ifndef ALGORITMORECOMENDACION_H
#define ALGORITMORECOMENDACION_H
#include "pelicula.h"
#include "Usuario.h"
#include "AVL.h"
#include "archivo.h"
#include <fstream>
#include <sstream>
#include <iostream>
#include <string>
#include <cmath>

class AlgoritmoRecomendacion
{
private:
    AVL<Usuario> avl;

public:
    AlgoritmoRecomendacion(){

    };

    void fillUsers(string filename)
    {

        // Leer datos de la línea
        int userId, itemId, IdTempUser = -1;
        float rating;
        string name;
        long timestamp;
        Usuario *user = nullptr;
        std::ifstream file(filename);
        if (!file.is_open())
        {
            std::cerr << "Error al abrir el archivo: " << filename << std::endl;
            return;
        }

        std::string line;
        while (std::getline(file, line))
        {
            std::istringstream iss(line);
            std::string token;

            if (std::getline(iss, token, ','))
            {
                userId = std::stoi(token);
                if (IdTempUser == -1)
                {
                    IdTempUser = userId;
                    name = "Usuario " + to_string(userId);
                    user = new Usuario(userId, name);
                }
                else if (userId != IdTempUser)
                {
                    avl.Insertar(user);
                    IdTempUser = userId;
                    name = "Usuario " + to_string(userId);
                    user = new Usuario(userId, name);
                }
            }
            if (std::getline(iss, token, ','))
            {
                itemId = std::stoi(token);
            }
            if (std::getline(iss, token, ','))
            {
                rating = std::stof(token);
            }
            if (std::getline(iss, token, ','))
            {
                timestamp = std::stol(token);
            }
            if (userId == IdTempUser && user != nullptr)
            {
                user->modiVista(itemId, rating);
            }

            //
        }
        if (user != nullptr)
        {
            avl.Insertar(user); // Insertar el último usuario en el AVL
        }

        file.close();
    }
    /*
     *LES EXPLICO EN COMO DEBEIA FUNCIONAR EL SISTEMAS DE RECOMENDACION A UN USUARIO
     * SACAR LA DISTACNIA ECLUDIANA ENTRE LAS PELUCLAS QUE VIERON LOS OTROS USARIOS Y CON EL
     * LUEGO MULTPLICA LAS DIATACNAS CON LOS SCORES DELAS OTRAS PEICULAS QUE NO VIO Y DE LA UN 
     * VALOR DE RECOMENDACION.
     * 
    */
    void hacerComparaciones() {

       for (int i = 1; i <= 610; i++) {
           for (int j = 1; j <= 610; j++) {
               if (i != j) {
                   comparar(avl.Buscar(i), avl.Buscar(j));
               }
           }
        }
    }

    void comparar(Usuario *u1, Usuario *u2) {

        unordered_map <int, double> v1 = u1->getVistas();
        unordered_map <int, double> v2 = u2->getVistas();

        double suma = 0;

        for (auto it1 = v1.begin(); it1 != v1.end(); ++it1) {
            auto it2 = v2.find(it1->first);
            if (it2 != v2.end()) {
                suma += (it1->second - it2->second) * (it1->second - it2->second);
            }
            else {
                suma += (it1->second) * (it1->second);
            }
        }
    
        double distEu = sqrt(suma);
        distEu = round(distEu * 10) / 10;
    
        for (auto it2 = v2.begin(); it2 != v2.end(); ++it2) {
            if (v1.find(it2->first) == v1.end()) {
                u1->modiRecom(it2->first, it2->second * (distEu / 10)); 
            }
        }

    }

    AVL<Usuario> getAvl() {
        return avl;
    }

    void printAllDataUser()
    {
        avl.inOrden();
    }
    void numberOfUsers()
    {
        cout << "number of users ->" << avl.NumeroNodos() << "\n";
    }
};

#endif
