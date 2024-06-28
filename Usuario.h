#ifndef USUARIO_H
#define USUARIO_H

#include <vector>
#include <iostream>
#include <string>
#include <unordered_map>
#include "pelicula.h"

using namespace std;

// registro de peliculas
class PeliculaRegistro
{
private:
  int id;
  float voto;
   

public:
    PeliculaRegistro(int id, float v):id(id),voto(voto){}

  void setIdPelicula( int d){
    id=d;
  }
  
 void setVotoPelicula(double v){
    voto = v;
 }

  int getIdPelicula(){
    return id;

  }

  float getVotoPelicula(){
    return voto;
  }

};

//clase de Usuarios
class Usuario {
    unordered_map <int, double> vistas;
    unordered_map <int, double> recom;
    string nombre;
    int id;

public:
    Usuario() : id(0), nombre("") {}
    Usuario(int id, string n) : id(id), nombre(n) {}

    void addVista(int id, double punt) {
        vistas[id] = punt;
    }

    void addRecom(int id, double punt) {
        recom[id] = punt;
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
    void printMoviesRecomend(){
            
    }
};

#endif // USUARIO_H

