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
    int counter;
    vector<T> listAdyacentes; // Lista de adyacentes
    
public:
    Node() : Padre("-1"), Marca(false), counter(0) {}

    void setPadre(const string& padre) { Padre = padre; }
    string getPadre() const { return Padre; }

    void setMarca(bool marca) { Marca = marca; }
    bool getMarca() const { return Marca; }


    void setCounter(int contador) { this->counter = contador; }
    int getCounter() const { return counter; }

    const vector<T>& getListAdyacentes() { return listAdyacentes; }

    void insertarVecino(const T& nodo) {
        listAdyacentes.push_back(nodo);
    }

    void mostrar() const {
        for (const auto& [nodo, peso] : listAdyacentes) {
            cout << nodo << " (" << peso << "), ";
        }
        cout << endl;
    }
};
