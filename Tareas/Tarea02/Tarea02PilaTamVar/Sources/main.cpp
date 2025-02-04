#include <iostream>
#include "../Headers/Pila.hpp"
#include "../Headers/Vector.hpp" 
#include "../Headers/Complejo.hpp" 
#include "../Headers/Polinomio.hpp" 
#include "../Headers/Matriz.hpp"

using namespace std;

int main() {
    try {
        // ---------------- PRUEBAS CON VECTORES ----------------

        cout << "\n=== Pruebas con Vectores ===\n";
        
        // Crear una pila de tipo Vector
        Pila<Vector> pilaVectores;

        // Verificar si la pila está vacía
        if (pilaVectores.EstaVacia()) 
            cout << "La Pila de Vectores está vacía." << endl;
        else
            cout << "La Pila de Vectores no está vacía." << endl;

        // Apilar objetos de tipo Vector
        pilaVectores.Apilar(Vector(3, 1.5));
        pilaVectores.Apilar(Vector(5, 0.2));
        pilaVectores.Apilar(Vector(2, 3));
        pilaVectores.Apilar(Vector(4, 3.1));

        // Imprimir el contenido de la pila de Vectores
        pilaVectores.Imprimir();
        cout << "\n\n";

        // Vaciar la pila de Vectores
        pilaVectores.Vaciar();
        
        // Verificar capacidad y tamaño después de apilar elementos
        cout << "Capacidad de la pila de Vectores: " << pilaVectores.ObtenerCapacidad() << endl;
        cout << "Tamaño de la pila de Vectores: " << pilaVectores.ObtenerTamanio() << endl;

        // Verificar si la pila está vacía después de vaciarla
        if (pilaVectores.EstaVacia()) 
            cout << "La Pila de Vectores está vacía." << endl;
        else
            cout << "La Pila de Vectores no está vacía." << endl;

     
        try {
            cout << "El tope de la pila de Vectores es: " << pilaVectores.ObtenerTope() << endl;
        } catch (const std::underflow_error& e) {
            cout << "Error: " << e.what() << endl;
        }

     
        try {
            pilaVectores.Desapilar();
        } catch (const std::underflow_error& e) {
            cout << "Error: " << e.what() << endl;
        }

        // Verificar si la pila de Vectores está llena
        if (pilaVectores.EstaLlena()) {
            cout << "La pila de Vectores está llena." << endl;
        } else {
            cout << "La pila de Vectores no está llena." << endl;
        }

     
        pilaVectores.Vaciar();
        pilaVectores.Imprimir();

        // ---------------- PRUEBAS CON COMPLEJOS ----------------

        cout << "\n=== Pruebas con Números Complejos ===\n";

        // Crear una pila de tipo Complejo
        Pila<Complejo> pilaComplejos;

        // Verificar si la pila está vacía
        if (pilaComplejos.EstaVacia()) 
            cout << "La Pila de Complejos está vacía." << endl;
        else
            cout << "La Pila de Complejos no está vacía." << endl;

        // Apilar objetos de tipo Complejo
        pilaComplejos.Apilar(Complejo(3, 1.5));
        pilaComplejos.Apilar(Complejo(5, 0.2));
        pilaComplejos.Apilar(Complejo(2, 3));
        pilaComplejos.Apilar(Complejo(4, 3.1));

        // Imprimir el contenido de la pila de Complejos
        pilaComplejos.Imprimir();
        cout << "\n\n";

        // Vaciar la pila de Complejos
        pilaComplejos.Vaciar();
        
        // Verificar capacidad y tamaño después de apilar elementos
        cout << "Capacidad de la pila de Complejos: " << pilaComplejos.ObtenerCapacidad() << endl;
        cout << "Tamaño de la pila de Complejos: " << pilaComplejos.ObtenerTamanio() << endl;

        // Verificar si la pila está vacía después de vaciarla
        if (pilaComplejos.EstaVacia()) 
            cout << "La Pila de Complejos está vacía." << endl;
        else
            cout << "La Pila de Complejos no está vacía." << endl;

        // Intentar obtener el tope de la pila de Complejos
        try {
            cout << "El tope de la pila de Complejos es: " << pilaComplejos.ObtenerTope() << endl;
        } catch (const std::underflow_error& e) {
            cout << "Error: " << e.what() << endl;
        }

        // Intentar desapilar elementos después de vaciar la pila
        try {
            pilaComplejos.Desapilar();
        } catch (const std::underflow_error& e) {
            cout << "Error: " << e.what() << endl;
        }

        // Verificar si la pila de Complejos está llena
        if (pilaComplejos.EstaLlena()) {
            cout << "La pila de Complejos está llena." << endl;
        } else {
            cout << "La pila de Complejos no está llena." << endl;
        }

        // Vaciar la pila de Complejos y tratar de imprimir
        pilaComplejos.Vaciar();
        pilaComplejos.Imprimir();

        // ---------------- PRUEBAS CON POLINOMIOS ----------------

        cout << "\n=== Pruebas con Polinomios ===\n";

        // Crear una pila de polinomios
        Pila<Polinomio> pilaPolinomios;

        // Apilar algunos polinomios
        Polinomio p1({1, 2, 3}); 
        Polinomio p2({0, 1, 4}); // x + 4x�
        Polinomio p3({5, 0, 0, 2}); // 5 + 2x�

        cout << "Apilando polinomios...\n";
        pilaPolinomios.Apilar(p1);
        pilaPolinomios.Apilar(p2);
        pilaPolinomios.Apilar(p3);

        cout << "Imprimiendo el tope de la pila de polinomios:\n";
        pilaPolinomios.ObtenerTope().Imprimir();

        // Desapilar y operar con los polinomios
        Polinomio polinomioA = pilaPolinomios.Desapilar();
        Polinomio polinomioB = pilaPolinomios.Desapilar();

        cout << "\nSumando los dos polinomios desapilados:\n";
        Polinomio resultado = polinomioA + polinomioB;
        resultado.Imprimir();

    } catch (const char *mensaje) {
        cout << "Error: " << mensaje << endl;
    }

    return 0;
}
