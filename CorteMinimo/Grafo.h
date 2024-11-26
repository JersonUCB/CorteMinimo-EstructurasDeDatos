#pragma once
#include <string>
#include <vector>
#include <queue>
#include <iostream>
#include <fstream>
#include <unordered_map>
#include <sstream>
#include "Nodo.h" 
#include <cstdlib>
#include <ctime>
#include <random>
#include <chrono>
#define TAM 900

using namespace std;

class Grafo {
private:
    unordered_map<string, Nodo<string>> G; // Usar unordered_map
    int tamanioGrafo = 0;
    string aristas[TAM];
    int tamanioArr = -1;
    unordered_map<string, Nodo<string>>::iterator it;
public:
    Grafo() {};
    ~Grafo();

    void limpiar();
    void LeerArchivo();
    void mostrarGrafo();
    void VerticesAleatorio(string& VO, string& VF);
    void Contraer(string Vo, string Vd);
    int getTamanioGrafo();
    int contarAristas();
    Grafo copiaLista();
    void encontrarMenor();
};

inline Grafo::~Grafo() {
}

inline void Grafo::limpiar() {
}

inline void Grafo::LeerArchivo() {
    string numero;
    string Vertice;

    int inicio = 0;
    ifstream archivo("prueba.txt");
    if (!archivo.is_open()) {
        throw runtime_error("No se pudo abrir el archivo");
    }
    while (archivo >> numero) {
        if (numero != "-1") {
            if (inicio == 0) {
                Vertice = numero;
                tamanioGrafo++;
                tamanioArr++;
                aristas[tamanioArr] = numero;
            }
            else {
                Vertice.getVector()->InsertarFin(numero);
            }
            inicio++;
        }
        else {
            inicio = 0;
        }
    }
    archivo.close();
}

inline void Grafo::mostrarGrafo() {
    for (auto it = G.begin(); it != G.end(); it++) {
        cout << "Vertice " << it->first << ": ";
        if (it->second.getVector() != nullptr) {
            it->second.getVector()->printElements();
        }
        cout << endl;
    }

    inline void Grafo::VerticesAleatorio(string & Vo, string & Vd) {
        random_device rd;
        mt19937 gen(rd());

        uniform_int_distribution<> dis(0, tamanioArr);
        int num1 = dis(gen);
        Vd = aristas[num1];
        aristas[num1] = aristas[tamanioArr];
        tamanioArr--;
        uniform_int_distribution<> dis2(0, G[Vd].getVector()->getContador() - 1);
        int num2 = dis2(gen);
        Nodo<string>* aux = G[Vd].getVector()->buscarIesimo(num2);
        Vo = aux->getElemento();
    }

    inline void Grafo::Contraer(string Vo, string Vd) {
        Nodo<string>* i = G[Vd].getVector()->getPrimero();
        while (i != NULL) {
            if (i->getElemento() != Vo) {
                G[Vo].getVector()->InsertarFin(i->getElemento());
                G[i->getElemento()].getVector()->InsertarFin(Vo);
            }
            G[i->getElemento()].getVector()->eliminarDato(Vd);
            G[i->getElemento()].getVector()->disminuircont();
            i = i->getSiguiente();
        }
        G.erase(Vd);
        tamanioGrafo--;
    }

    inline int Grafo::getTamanioGrafo() {
        return tamanioGrafo;
    }

    inline int Grafo::contarAristas() {
        int resp;
        it = G.begin();
        resp = it->second.getVector()->getContador();
        return resp;
    }

    inline Grafo Grafo::copiaLista() {
        Grafo grafoSalida;

        for (int i = 0; i <= tamanioArr; ++i) {
            grafoSalida.aristas[i] = aristas[i];
        }
        grafoSalida.tamanioArr = tamanioArr;

        grafoSalida.tamanioGrafo = tamanioGrafo;

        for (auto it = G.begin(); it != G.end(); ++it) {
            Nodo<string>* aux = it->second.getVector()->getPrimero();
            while (aux != nullptr) {
                grafoSalida.G[it->first].getVector()->InsertarFin(aux->getElemento());
                aux = aux->getSiguiente();
            }
        }

        return grafoSalida;
    }

    inline void Grafo::encontrarMenor() {
        int menor;
        int MinMenor = 0;
        string Vo, Vd;

        for (int i = 0; i < 90000; i++) {
            auto start = std::chrono::high_resolution_clock::now();
            Grafo grafo2 = copiaLista();
            while (grafo2.getTamanioGrafo() > 2) {
                grafo2.VerticesAleatorio(Vo, Vd);
                grafo2.Contraer(Vo, Vd);
            }
            menor = grafo2.contarAristas();
            grafo2.limpiar();
            if (i != 0) {
                cout << "Ejecucion Nro " << i << ": de 90000" << " ->" << " Menor: " << menor << endl;
                if (MinMenor > menor) {
                    MinMenor = menor;
                }
            }
            else {
                MinMenor = menor;
            }
        }
        cout << "Menor de todas las iteraciones: " << MinMenor << endl;
    }
	
