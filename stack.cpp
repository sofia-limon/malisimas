#include <bits/stdc++.h>
using namespace std;

#define ll long long 
#define pll pair<ll,ll>
#define F first
#define S second 
#define Z size()
#define pb push_back
#define bp pop_back
#define fo(x,y,z) for(ll x=y; x<=z; x++)
#define of(x,y,z) for(ll x=y; x>=z; x--)
#define all(n) n.begin(), n.end()
#define lla(n) n.rbegin(), n.rend()
#define arr(x,y,z) x+y, x+y+z

// Función para dibujar la pila
void dibujarPila(const vector<int>& pila, int capacidadMaxima) {
    cout << "\n--- Estado Actual de la Pila ---" << endl;
    for (int i = capacidadMaxima - 1; i >= 0; --i) {//for al reves empezando de 10 por ahora
        if (i < pila.size()) {//mientras sea menor que 10
            cout << "|     " << pila[i] << "     |" << endl;
        } else {
            cout << "|           |" << endl;
        }
        cout << " -------------" << endl;
    }
    cout << " -------------\n" << endl;
}

// Función para mostrar los valores eliminados
//aqui falta simular como se mueven pero nose como :,(
void mostrarValoresEliminados(const vector<int>& valores) {
    cout << "\nValores eliminados: ";
    if (valores.empty()) {
        cout << "Ninguno" << endl;
    } else {
        for (int valor : valores) {
            cout << valor << " ";
        }
        cout << endl;
    }
}

int main() {
    vector<int> pila;
    vector<int> valoresEliminados;
    int opcion, valor;
    const int MAX_ELEMENTOS = 10; //puse por mientras que sea de 10 max

    do {
        cout << "\nMenú de Opciones:" << endl;
        cout << "1. Agregar valor a la pila" << endl;
        cout << "2. Quitar valor de la pila (LIFO)" << endl; //last in, first out 
        cout << "3. Quitar valor como cola (FIFO)" << endl;//first in first out
        cout << "4. Salir" << endl;
        cout << "Seleccione una opción: ";
        cin >> opcion;

        switch (opcion) {
            case 1:
                if (pila.size() < MAX_ELEMENTOS) {
                    cout << "Ingrese el valor para agregar a la pila: ";
                    cin >> valor;
                    pila.pb(valor);//push back: poner al final
                    dibujarPila(pila, MAX_ELEMENTOS);
                    mostrarValoresEliminados(valoresEliminados);
                } else {
                    cout << "La pila ha alcanzado el máximo de " << MAX_ELEMENTOS << " elementos." << endl;
                }
                break;
            case 2:
                if (!pila.empty()) {//si no esta vacia la pila o escalera
                    int valorEliminado = pila.back(); //el ultimo pasa a ser valor eliminado
                    pila.bp();//pop back: eliminar el ultimo
                    valoresEliminados.pb(valorEliminado);//lo pones en el vec de valores eliminados
                    dibujarPila(pila, MAX_ELEMENTOS);
                    mostrarValoresEliminados(valoresEliminados);
                } else {
                    cout << "La pila está vacía, no se puede quitar ningún valor." << endl;
                }
                break;
            case 3:
                if (!pila.empty()) {
                    int valorEliminado = pila.front(); //lo mismo pero ahora es el de enfrente
                    pila.erase(pila.begin());  // Eliminar el primer elemento (FIFO)
                    valoresEliminados.pb(valorEliminado);//esto pa ir guardandolos y luego hacer lo q padilla
                    dibujarPila(pila, MAX_ELEMENTOS);
                    mostrarValoresEliminados(valoresEliminados);
                } else {
                    cout << "La cola está vacía, no se puede quitar ningún valor." << endl;
                }
                break;
            case 4:
                cout << "Saliendo del programa..." << endl;
                break;
            default:
                cout << "Opción no válida. Inténtelo de nuevo." << endl;
        }
    } while (opcion != 4);

    return 0;
}
