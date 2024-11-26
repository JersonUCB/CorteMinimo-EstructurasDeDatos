
#include <iostream>
#include "Grafo.h"

using namespace std;

int main() {
    int op;
    Grafo<int>* g = new Grafo<int>;
    string v1, v2;
    int dist;
    int total;
    int min = 100000;

    do {
        system("cls");
        cout << "--------------------- ALGORITMO MIN CUT ------------------" << endl;
        cout << "1. Leer de Archivo MIN CUT" << endl;
        cout << "2. Mostrar el Grafo" << endl;
        cout << "3. MinCut" << endl;
        cout << "4. Encontrar el Minimo" << endl;
        cout << "0. salir" << endl;
        cout << "Ingrese una opcion: ";
        cin >> op;

        switch (op) {
        case 1:
            g->leerArchivo("PRUEBA_Min_Cut.txt");
            break;
        case 2:
            g->mostrar();
            break;
        case 3:
            //g.minCut();
            break;
        case 4:
            //cout << "El peso minimo encontrado es: " << g->minCut() << endl;
            break;

        case 0:
            cout << "Saliendo..." << endl;
            break;
        default:
            cout << "Opcion no valida." << endl;
            break;
        }
        system("pause");
    } while (op != 0);

    return 0;
}
