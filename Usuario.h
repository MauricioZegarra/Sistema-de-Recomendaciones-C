#ifndef USUARIO_H
#define USUARIO_H

#include <vector>
#include <iostream>
#include <string>
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
    vector<PeliculaRegistro> puntuaciones;
    string nombre;
    vector<Pelicula> recomendaciones;
    int id;

public:
    Usuario() : id(0), nombre("") {}
    Usuario(int id, string n) : id(id), nombre(n) {}

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

    void setVectorPeliculas( vector<PeliculaRegistro>array) {
        puntuaciones = array;
    }

    vector<PeliculaRegistro> getVectorPeliculas() const {
        return puntuaciones;
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
    void addPeliculaPuntuacion(PeliculaRegistro p){
        puntuaciones.push_back(p);
    }

    void addPeliculaRecomendada(Pelicula r){
        recomendaciones.push_back(r);
    }

    vector<Pelicula> getRecomendadas(){
        return recomendaciones;
    }
        // Sobrecarga del operador <<
    friend std::ostream& operator<<(std::ostream& os, const Usuario& usuario) {
        os << "ID: " << usuario.id << ", Nombre: " << usuario.nombre;
        return os;
    }
    void printMoviesRecomend(){
        for(size_t i=0;i<recomendaciones.size();i++){
            cout<<"id->"<<recomendaciones[i].getIdPelicula()<<"pelicula"<<"\n";
        }
        cout<<"------------------------------------------------------------\n";
            
    }
};

#endif // USUARIO_H

