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
    int Distancia;
    vector<pair<string, int>> listAdyacentes; // Lista de adyacentes {Nodo, Peso}

public:
    Node() : Padre("-1"), Marca(false), Distancia(INT_MAX) {}

    void setPadre(const string& padre) { Padre = padre; }
    string getPadre() const { return Padre; }

    void setMarca(bool marca) { Marca = marca; }
    bool getMarca() const { return Marca; }

    void setDistancia(int distancia) { Distancia = distancia; }
    int getDistancia() const { return Distancia; }

    vector<pair<string, int>>& getListAdyacentes() { return listAdyacentes; }

    void insertarVecino(const string& nodo, int peso) {
        listAdyacentes.push_back({ nodo, peso });
    }

    void mostrar() const {
        for (const auto& [nodo, peso] : listAdyacentes) {
            //cout << nodo << " (" << peso << "), ";
            cout << nodo << ",";
        }
        cout << endl;
    }
};
