#include "archivo.h"
#include <iostream>
using  namespace std;
Archivo::Archivo(const std::string& nombre) : nombreArchivo(nombre) {}

void Archivo::leerArchivo() {
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
