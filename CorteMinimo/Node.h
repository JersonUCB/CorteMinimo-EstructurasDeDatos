#pragma once
#include <iostream>
#include <vector>
#include <limits.h>
#include <string>
using namespace std;

template <class T>
class Node {
private:
    string Padre;
    bool Marca;
    vector<T> listAdyacentes; // Lista de adyacentes

public:
    Node() : Padre("-1"), Marca(false) {}

    void setPadre(const string& padre) { Padre = padre; }
    string getPadre() const { return Padre; }

    void setMarca(bool marca) { Marca = marca; }
    bool getMarca() const { return Marca; }

    vector<T>& getListAdyacentes() { return listAdyacentes; }

    void insertarVecino(const T& nodo) {
        listAdyacentes.push_back(nodo);
    }

    void mostrar() const {
        for (const auto& nodo : listAdyacentes) {
            cout << nodo << ",";
        }
        cout << endl;
    }
};
