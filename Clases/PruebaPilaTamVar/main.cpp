#include <iostream>
#include "Pila.hpp"
#include "Vector.hpp"  // Cambié a "Vector.hpp" en lugar de "Vector.cpp"

using namespace std;

int main() {
    try {
        // Crear una pila de tipo Vector
        Pila<Vector> miPila;
        // Pila<double> miPila;  // Alternativamente, podrías usar esta línea si deseas una pila de doubles

        // Verificar si la pila está vacía
        if (miPila.EstaVacia()) 
            cout << "La Pila está vacía." << endl;
        else
            cout << "La Pila no está vacía." << endl;

        // Apilar objetos de tipo Vector
        miPila.Apilar(Vector(3, 1.5));
        miPila.Apilar(Vector(5, 0.2));
        miPila.Apilar(Vector(2, 3));
        miPila.Apilar(Vector(4, 3.1));
        miPila.Apilar(Vector(-2));  // Asumí que Vector tiene un constructor que toma un solo valor

        // Imprimir el contenido de la pila
        miPila.Imprimir();
        cout << "\n\n";

        // Vaciar la pila
        miPila.Vaciar();

        // Intentar desapilar elementos después de vaciar (esto debería lanzar una excepción)
        miPila.Desapilar();
        miPila.Desapilar();

        // Vaciar la pila nuevamente (sin elementos) y tratar de imprimir
        miPila.Vaciar();
        miPila.Imprimir();
    } catch (const char *mensaje) {
        // Capturar y mostrar el mensaje de error si ocurre alguna excepción
        cout << "Error: " << mensaje << endl;
    }

    return 0;
}
