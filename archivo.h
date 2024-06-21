#ifndef ARCHIVO_H
#define ARCHIVO_H

#include <iostream>
#include <fstream>
#include <string>
using namespace std;

class Archivo {

private:
    string nombreArchivo;

public:
    Archivo(string  nombre){
        nombreArchivo= nombre;
    }
    void leerArchivo(){
    std::ifstream archivo(nombreArchivo.c_str());

    if (!archivo.is_open()) {
        std::cerr << "No se pudo abrir el archivo: " << nombreArchivo << std::endl;
        return;
    }

    std::string linea;
    while (std::getline(archivo, linea)) {
        std::cout << "Una línea: " << linea << std::endl;
    }

    archivo.close();
    std::cout << "Archivo leído correctamente." << std::endl;


    }

};

#endif // ARCHIVO_H
