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
        

        Pila<Vector> pilaVectores;


        if (pilaVectores.EstaVacia()) 
            cout << "La Pila de Vectores está vacía." << endl;
        else
            cout << "La Pila de Vectores no está vacía." << endl;


        pilaVectores.Apilar(Vector(3, 1.5));
        pilaVectores.Apilar(Vector(5, 0.2));
        pilaVectores.Apilar(Vector(2, 3));
        pilaVectores.Apilar(Vector(4, 3.1));


        pilaVectores.Imprimir();
        cout << "\n\n";


        pilaVectores.Vaciar();
        

        cout << "Capacidad de la pila de Vectores: " << pilaVectores.ObtenerCapacidad() << endl;
        cout << "Tamaño de la pila de Vectores: " << pilaVectores.ObtenerTamanio() << endl;


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


        if (pilaVectores.EstaLlena()) {
            cout << "La pila de Vectores está llena." << endl;
        } else {
            cout << "La pila de Vectores no está llena." << endl;
        }

     
        pilaVectores.Vaciar();
        pilaVectores.Imprimir();

        // ---------------- PRUEBAS CON COMPLEJOS ----------------

        cout << "\n=== Pruebas con Números Complejos ===\n";


        Pila<Complejo> pilaComplejos;


        if (pilaComplejos.EstaVacia()) 
            cout << "La Pila de Complejos está vacía." << endl;
        else
            cout << "La Pila de Complejos no está vacía." << endl;


        pilaComplejos.Apilar(Complejo(3, 1.5));
        pilaComplejos.Apilar(Complejo(5, 0.2));
        pilaComplejos.Apilar(Complejo(2, 3));
        pilaComplejos.Apilar(Complejo(4, 3.1));


        pilaComplejos.Imprimir();
        cout << "\n\n";


        pilaComplejos.Vaciar();
        

        cout << "Capacidad de la pila de Complejos: " << pilaComplejos.ObtenerCapacidad() << endl;
        cout << "Tamaño de la pila de Complejos: " << pilaComplejos.ObtenerTamanio() << endl;


        if (pilaComplejos.EstaVacia()) 
            cout << "La Pila de Complejos está vacía." << endl;
        else
            cout << "La Pila de Complejos no está vacía." << endl;


        try {
            cout << "El tope de la pila de Complejos es: " << pilaComplejos.ObtenerTope() << endl;
        } catch (const std::underflow_error& e) {
            cout << "Error: " << e.what() << endl;
        }

        
        try {
            pilaComplejos.Desapilar();
        } catch (const std::underflow_error& e) {
            cout << "Error: " << e.what() << endl;
        }

        
        if (pilaComplejos.EstaLlena()) {
            cout << "La pila de Complejos está llena." << endl;
        } else {
            cout << "La pila de Complejos no está llena." << endl;
        }

        
        pilaComplejos.Vaciar();
        pilaComplejos.Imprimir();

        // ---------------- PRUEBAS CON POLINOMIOS ----------------

        cout << "\n=== Pruebas con Polinomios ===\n";

        
        Pila<Polinomio> pilaPolinomios;

        
        Polinomio p1({1, 2, 3}); 
        Polinomio p2({0, 1, 4}); 
        Polinomio p3({5, 0, 0, 2}); 

        cout << "Apilando polinomios...\n";
        pilaPolinomios.Apilar(p1);
        pilaPolinomios.Apilar(p2);
        pilaPolinomios.Apilar(p3);

        cout << "Imprimiendo el tope de la pila de polinomios:\n";
        pilaPolinomios.ObtenerTope().Imprimir();

        
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
