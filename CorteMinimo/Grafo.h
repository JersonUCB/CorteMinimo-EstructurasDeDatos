#pragma once
#include <unordered_map>
#include <iostream>
#include <vector>
#include <fstream>
#include "Node.h"

template <class T = string>
class Grafo {
private:
    unordered_map<string, Node<T>> grafo;

public:

    void leerArchivo2(const string& nombreArchivo) {
        ifstream archivo(nombreArchivo);
        if (!archivo.is_open()) {
            cout << "Error al abrir el archivo." << endl;
            return;
        }
        string origen, destino;
        while (archivo >> origen ) {
            cout << origen<<"->";
            while (destino !=  "-1")
            {
                archivo >> destino;
                if (destino != "-1") {
                    insertarArista(origen, destino, 0);
                }
                cout << destino << ",";
            }
            destino = "0";
            cout << endl;
        }
        archivo.close();
        cout << "Archivo cargado correctamente." << endl;
    }

    void insertarArista(const string& origen, const string& destino, int peso) {
        grafo[origen].insertarVecino(destino);
        grafo[destino].insertarVecino(origen);
    }

    void mostrar() const {
        for (const auto& [nombre, nodo] : grafo) {
            cout << nombre << " -> ";
            nodo.mostrar();
        }
    }

    void eliminarDeLista(vector<pair<string, int>>& lista, const string& nodo)
    {
        for (int i = 0; i < lista.size(); i++)
        {
            if (lista[i].first == nodo)
            {
                swap(lista[i], lista.back());
                lista.pop_back();
            }
        }
        cout << "Nodo " << nodo << " no encontrado en la lista de adyacencia." << endl;
    }

    void eliminarArista(const string& origen, const string& destino)
    {
        auto& adyacentesOrigen = grafo[origen].getListAdyacentes();
        eliminarDeLista(adyacentesOrigen, destino);

        auto& adyacentesDestino = grafo[destino].getListAdyacentes();
        eliminarDeLista(adyacentesDestino, origen);

        cout << "Arista entre " << origen << " y " << destino << " eliminada correctamente." << endl;
    }

    void contraer() {

    }

    void MinCut() {

    }
};
