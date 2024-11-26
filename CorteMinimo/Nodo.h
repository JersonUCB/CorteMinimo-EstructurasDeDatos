#pragma once

#include <vector>
#include <iostream>
#include <string>
#include <limits.h>

using namespace std; // Usar todo el espacio de nombres std

// Definición de la clase templada Nodo
template <typename T>
class Nodo {
public:
    Nodo();                                  // Constructor por defecto
    ~Nodo();                                 // Destructor
    vector<T> getVector() const;              // Obtener el vector (copia)
    void setVector(const vector<T>& vec);     // Asignar un vector
    void addElement(const T& element);        // Agregar un elemento al vector
    void printElements() const;               // Imprimir los elementos

private:
    vector<T> vector;                         // Vector de elementos de tipo T
};

// Implementación de métodos

// Constructor por defecto
template <typename T>
Nodo<T>::Nodo() : vector() {}

// Destructor
template <typename T>
Nodo<T>::~Nodo() {}

// Obtener el vector completo
template <typename T>
vector<T> Nodo<T>::getVector() const {
    return vector; // Devuelve una copia
}

// Asignar un vector completo
template <typename T>
void Nodo<T>::setVector(const vector<T>& vec) {
    vector = vec;
}

// Agregar un elemento al vector
template <typename T>
void Nodo<T>::addElement(const T& element) {
    vector.push_back(element);
}

// Imprimir todos los elementos del vector
template <typename T>
void Nodo<T>::printElements() const {
    for (const auto& elem : vector) {
        cout << elem << " ";
    }
    cout << endl;
}


