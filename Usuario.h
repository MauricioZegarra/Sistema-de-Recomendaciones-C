#ifndef USUARIO_H
#define USUARIO_H

#include <iostream>
#include <string>
#include <unordered_map>

using namespace std;

//clase de Usuarios
class Usuario {
    unordered_map <int, double> vistas;
    unordered_map <int, double> recom;
    string nombre;
    int id;

public:
    Usuario() : id(0), nombre("") {}
    Usuario(int id, string n) : id(id), nombre(n) {}

    void modiVista(int id, double punt) {
        vistas[id] = punt;
    }

    unordered_map <int, double> getVistas() {
        return vistas;
    }

    void modiRecom(int id, double punt) {
        recom[id] = punt;
    }

    unordered_map <int, double> getRecom() {
        return recom;
    }

    void setID(int id) {
        this->id = id;
    }

    int getID() const {
        return id;
    }

    void setNombre(const string& n) {
        nombre = n;
    }

    string getNombre() const {
        return nombre;
    }

    bool operator==(const Usuario& other) const {
        return id == other.id;
    }

    bool operator<(const Usuario& other) const {
        return id < other.id;
    }

    bool operator>(const Usuario& other) const {
        return id > other.id;
    }

    bool operator<=(const Usuario& other) const {
        return id <= other.id;
    }

    bool operator>=(const Usuario& other) const {
        return id >= other.id;
    }
        // Sobrecarga del operador <<
    friend std::ostream& operator<<(std::ostream& os, const Usuario& usuario) {
        os << "ID: " << usuario.id << ", Nombre: " << usuario.nombre;
        return os;
    }
    
    void toString() {
        cout << "ID: " << id << ", Nombre: " << nombre << endl;
        
        cout << "\nEstas son las películas vistas por el usuario " << id << ": " << endl;

        for (const auto& pair : vistas) {
            cout << "Pelicula ID: " << pair.first << ", Puntuación: " << pair.second << endl;
        }

        cout << "\nLe recomendamos estas películas al usuario " << id << ": " << endl;

        for (const auto& pair : recom) {
            cout << "Pelicula ID: " << pair.first << ", Recomendación: " << pair.second << endl;
        }
    }

    void printMoviesRecomend(){
            
    }
};

#endif // USUARIO_H

