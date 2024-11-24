
#include <iostream>
#include "Grafo.h"

using namespace std;

int main() {
    int op;
    Grafo<> g;
    string origen, destino;
    int peso;

    do {
        system("cls");
        cout << "---------------------ALGORITMO DIJKSTRA------------------" << endl;
        cout << "1. Leer archivo con peso" << endl;
        cout << "2. Insertar arista" << endl;
        cout << "3. Mostrar grafo" << endl;
        cout << "4. Iniciar Padre, Marca y Distancia" << endl;
        cout << "5. Dijkstra" << endl;
        cout << "6. Mostrar todos los caminos de ORIGEN al resto de vertices" << endl;
        cout << "7. Eliminar arista entre dos vertices" << endl;
        cout << "0. Salir" << endl;
        cout << "Ingrese una opcion: ";
        cin >> op;

        switch (op) {
        case 1:
            g.leerArchivo("ValoradoBoliviaTexto.txt");
            break;
        case 2:
            cout << "Ingrese nodo origen: ";
            cin >> origen;
            cout << "Ingrese nodo destino: ";
            cin >> destino;
            cout << "Ingrese peso: ";
            cin >> peso;
            g.insertarArista(origen, destino, peso);
            break;
        case 3:
            g.mostrar();
            break;
        case 4:
            
            break;
        case 5:
            cout << "Ingrese nodo origen: ";
            cin >> origen;
            
            break;
        case 6:
            cout << "Ingrese nodo origen: ";
            cin >> origen;
            g.mostrarCaminos(origen);
            break;
        case 7:
            cout << "Ingrese el nodo origen: ";
            cin >> origen;
            cout << "Ingrese el nodo destino: ";
            cin >> destino;
            g.eliminarArista(origen, destino);
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
