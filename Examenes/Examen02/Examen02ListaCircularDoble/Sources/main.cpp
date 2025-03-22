#include "../Headers/DoublyCircularList.hpp"
#include <iostream>
#include <limits>
#include <string>

using namespace std;

int main() {
    int n, k;


    while (true) {
        cout << "Ingresa el numero de jugadores: ";
        cin >> n;
        if (cin.fail() || n <= 1) {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Ingresa un numero valido mayor a 1." << endl;
            continue;
        }
        break;
    }

    // Validar número de rondas
    while (true) {
        cout << "Ingresa el valor para los rounds: ";
        cin >> k;
        if (cin.fail() || k <= 1) {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Ingresa un numero valido mayor a 1." << endl;
            continue;
        }
        break;
    }

    cin.ignore(); 

    DoublyCircularList list;


    for (int i = 1; i <= n; ++i) {
        string name;
        cout << "Ingresa el nombre del jugador " << i << ": ";
        getline(cin, name);
        list.insertNode(name);
    }

    list.startGame(k);

    return 0;
}
