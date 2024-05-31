#ifndef ARCHIVO_H
#define ARCHIVO_H

#include <iostream>
#include <fstream>
#include <string>

class Archivo {
public:
    Archivo(const std::string& nombre);
    void leerArchivo();

private:
    std::string nombreArchivo;
};

#endif // ARCHIVO_H
