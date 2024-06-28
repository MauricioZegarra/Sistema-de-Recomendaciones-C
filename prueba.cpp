#include <iostream>
#include <unordered_map>
#include <cmath>

using namespace std;

void print(const unordered_map<int, double>& map) {
    for (auto it = map.begin(); it != map.end(); ++it) {
        cout << it->first << ", " << it->second << endl;
    }
}

int main() {
    unordered_map<int, double> u1;
    unordered_map<int, double> u2;
    unordered_map<int, double> recom;

    u1[1] = 4.0;
    u1[4] = 1.0;
    u1[5] = 2.0;
    u1[7] = 3.0;
    u1[9] = 2.5;
    u1[8] = 1.5;
    u1[3] = 4.5;

    u2[2] = 1.0;
    u2[4] = 7.0;
    u2[5] = 9.0;

    double suma = 0;

    //u2 busca recomendaciones

    for (auto it2 = u2.begin(); it2 != u2.end(); ++it2) {
        auto it1 = u1.find(it2->first);
        if (it1 != u1.end()) {
            suma += (it1->second - it2->second) * (it1->second - it2->second);
        }
    }

    double distEu = sqrt(suma);

    for (auto it1 = u1.begin(); it1 != u1.end(); ++it1) {
        if (u2.find(it1->first) == u2.end()) {
            recom[it1->first] = it1->second * (distEu / 10); 
        }
    }

    cout << "Usuario modelo: " << endl;
    print(u1);

    cout << "\nUsuario que busca recomendaciones: " << endl;
    print(u2);

    cout << "\nRecomendaciones: " << endl;
    print(recom);

    return 0;
}
