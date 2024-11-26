#pragma once
#include <iostream>
#include <vector>
#include <fstream>
#include "Node.h"
#include <map>

template <class T>
class Grafo {
private:
    map<T, Node<T>> G;

public:
    void leerArchivo(const string& nombreArchivo) {
        ifstream archivo(nombreArchivo);
        if (!archivo.is_open()) {
            cout << "Error al abrir el archivo." << endl;
            return;
        }
        string origen, destino;
        while (archivo >> origen) {
            cout << origen << "->";
            while (destino != "-1")
            {
                archivo >> destino;
                if (destino != "-1") {
                    int ori, desti;
                    ori = stoi(origen);
                    desti = stoi(destino);

                    insertarArista(ori, desti);
                }
                cout << destino << ",";
            }
            destino = "0";
            cout << endl;
        }
        archivo.close();
        cout << "Archivo cargado correctamente." << endl;
        
        cout << endl;
    }
    
    void mostrar() {
        for (auto& [origen, nodo] : G) {
            cout << "Nodo " << origen << ": ";
            for (const auto& vecino : nodo.getListAdyacentes()) {
                cout << vecino << " ";
            }
            cout << endl;
        }
    }

    void insertarArista(const T& origen, const T& destino) {
        G[origen].insertarVecino(destino);
        G[destino].insertarVecino(origen);

    }

    template <typename T>
    T buscarCiclo(T x) {
        while (x != G[to_string(x)].getPadre()) {
            x = G[to_string(x)].getPadre();
        }
        return x;
    }

    template <typename T>
    void inicio(map<T, Node<T>>& grafo) {
        for (auto& [key, nodo] : grafo) {
            nodo.setMarca(false);
            nodo.setPadre(key);
        }
    }

    template <typename T>
    void minCut() {
        while (G.size() > 2) {
            T origen = random<T>(); // Nodo aleatorio
            auto& vecinos = G[to_string(origen)].getListAdyacentes();

            if (vecinos.empty()) {
                cout << "El nodo " << origen << " no tiene vecinos. Eliminandolo del grafo." << endl;
                G.erase(to_string(origen));
                continue;
            }

            // Seleccionar un vecino aleatorio
            T destino = vecinos[rand() % vecinos.size()];

            // Contraer los nodos origen y destino
            contraer<T>(origen, destino);
        }

        // Mostrar el resultado del corte
        cout << "El corte mínimo involucra los nodos restantes:" << endl;
        for (const auto& [nodo, datos] : G) {
            cout << nodo << " -> ";
            for (const auto& vecino : datos.getListAdyacentes()) {
                cout << vecino << " ";
            }
            cout << endl;
        }
    }

    template <typename T>
    void contraer(const T& v1, const T& v2) {
        // Eliminar la conexión entre v1 y v2
        auto& vecinosV1 = G[to_string(v1)].getListAdyacentes();
        auto& vecinosV2 = G[to_string(v2)].getListAdyacentes();

        vecinosV1.erase(remove(vecinosV1.begin(), vecinosV1.end(), v2), vecinosV1.end());
        vecinosV2.erase(remove(vecinosV2.begin(), vecinosV2.end(), v1), vecinosV2.end());

        // Mover los vecinos de v2 a v1, asegurando que no se creen autociclos
        for (const auto& vecino : vecinosV2) {
            if (vecino != v1) { // Evitar autociclo
                vecinosV1.push_back(vecino);
                // Actualizar las conexiones de los vecinos para que apunten a v1 en lugar de v2
                auto& vecinosDelVecino = G[to_string(vecino)].getListAdyacentes();
                replace(vecinosDelVecino.begin(), vecinosDelVecino.end(), v2, v1);
            }
        }

        // Eliminar el nodo v2 del grafo
        G.erase(to_string(v2));
    }

    template <typename T>
    T random() {
        if (G.empty()) {
            cout << "El grafo está vacío." << endl;
            return T();
        }

        int pos = rand() % G.size(); // Seleccionar posición aleatoria
        auto it = G.begin();
        advance(it, pos); // Mover el iterador a la posición seleccionada
        return static_cast<T>(it->first); // Retornar el nombre del nodo
    }

    template <typename T>
    void eliminarAutoCiclo() {
        for (auto& [nodo, datos] : G) {
            auto& listaVecinos = datos.getListAdyacentes();
            listaVecinos.erase(
                remove(listaVecinos.begin(), listaVecinos.end(), nodo),
                listaVecinos.end()
            );
        }
    }



};
