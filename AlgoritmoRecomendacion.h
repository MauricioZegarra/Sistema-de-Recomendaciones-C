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
                PeliculaRegistro p = PeliculaRegistro(itemId, rating);
                user->addPeliculaPuntuacion(p);
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
    void recomedMoviesToOneUser(int id){

     //Usuario *us=avl.Buscar(id);

     // Nodo *root = avl.getRaiz();
      
      //Usuario *

    }
    void currentUser(){
      
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