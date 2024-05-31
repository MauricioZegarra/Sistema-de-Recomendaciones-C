#ifndef USUARIO_H
#define USUARIO_H

#include <iostream>

class Usuario {
public:
    Usuario(int id, int cal1, int cal2, int cal3) : id(id) {
        calificaciones[0] = cal1;
        calificaciones[1] = cal2;
        calificaciones[2] = cal3;
    }

    int id;
    int calificaciones[3];
};

#endif // USUARIO_H
