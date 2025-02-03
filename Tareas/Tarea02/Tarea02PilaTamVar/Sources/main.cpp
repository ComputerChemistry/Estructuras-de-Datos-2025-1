#include <iostream>
#include "../Headers/Pila.hpp"
#include "../Headers/Vector.hpp" 

using namespace std;

int main() {
    try {
        // Crear una pila de tipo Vector
        Pila<Vector> miPila;

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

        // Imprimir el contenido de la pila
        miPila.Imprimir();
        cout << "\n\n";

        // Vaciar la pila
        miPila.Vaciar();
        
	// Verificar capacidad y tamaño después de apilar elementos
	cout << "Capacidad de la pila: " << miPila.ObtenerCapacidad() << endl;
	cout << "Tamaño de la pila: " << miPila.ObtenerTamanio() << endl;


        // Verificar si la pila está vacía después de vaciarla
        if (miPila.EstaVacia()) 
            cout << "La Pila está vacía." << endl;
        else
            cout << "La Pila no está vacía." << endl;

        // Intentar obtener el tope de la pila (esto lanzará una excepción si está vacía)
        try {
            cout << "El tope de la pila es: " << miPila.ObtenerTope() << endl;
        } catch (const std::underflow_error& e) {
            cout << "Error: " << e.what() << endl;
        }

        // Intentar desapilar elementos después de vaciar la pila
        try {
            miPila.Desapilar();
        } catch (const std::underflow_error& e) {
            cout << "Error: " << e.what() << endl;
        }

        // Verificar si la pila está llena
        if (miPila.EstaLlena()) {
            cout << "La pila está llena." << endl;
        } else {
            cout << "La pila no está llena." << endl;
        }

        // Vaciar la pila nuevamente (sin elementos) y tratar de imprimir
        miPila.Vaciar();
        miPila.Imprimir();

    } catch (const char *mensaje) {
        // Capturar y mostrar el mensaje de error si ocurre alguna excepción
        cout << "Error: " << mensaje << endl;
    }

    return 0;
}
