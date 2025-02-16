// Pila.tpp
#include <iostream>
#include "../Headers/Pila.hpp"

using std::cout;
using std::endl;

//****************************************
template <typename Tipo>
Pila<Tipo>::Pila() : numElem(0), tope(nullptr) {}

//****************************************
// Constructor de copia
template <typename Tipo>
Pila<Tipo>::Pila(const Pila<Tipo>& otra) {
    *this = otra;
}

//****************************************
// Operador de asignación
template <typename Tipo>
Pila<Tipo>& Pila<Tipo>::operator=(const Pila<Tipo>& otra) {
    if (this == &otra) return *this;
    
    Vaciar(); // Limpiar la pila actual
    
    Nodo* actual = otra.tope;
    Pila<Tipo> temp;
    while (actual) {
        temp.Apilar(actual->valor);
        actual = actual->siguiente;
    }
    
    actual = temp.tope;
    while (actual) {
        Apilar(actual->valor);
        actual = actual->siguiente;
    }
    
    return *this;
}

//****************************************
template <typename Tipo>
void Pila<Tipo>::Apilar(Tipo valor) {
    Nodo* nuevo = new Nodo;
    nuevo->valor = valor;
    nuevo->siguiente = tope;
    tope = nuevo;
    ++numElem;
}

//****************************************
template <typename Tipo>
void Pila<Tipo>::Vaciar() {
    while (!EstaVacia()) {
        Desapilar();
    }
    tope = nullptr;
}

//****************************************
template <typename Tipo>
Tipo Pila<Tipo>::Desapilar() {
    if (EstaVacia()) {
        throw std::underflow_error("Error: La pila está vacía");
    }
    Nodo* porBorrar = tope;
    Tipo valor = porBorrar->valor;
    tope = tope->siguiente;
    delete porBorrar;
    --numElem;
    return valor;
}

//****************************************
template <typename Tipo>
Tipo Pila<Tipo>::ObtenerTope() const {
    if (EstaVacia()) {
        throw std::underflow_error("Error: La pila está vacía");
    }
    return tope->valor;
}

//****************************************
template <typename Tipo>
bool Pila<Tipo>::EstaVacia() const {
    return tope == nullptr;
}

//****************************************
template <typename Tipo>
int Pila<Tipo>::ObtenerTamanio() const {
    return numElem;
}

//****************************************
template <typename Tipo>
void Pila<Tipo>::Imprimir() const {
    if (EstaVacia()) {
        cout << "Pila vacía" << endl;
        return;
    }
    Nodo* actual = tope;
    while (actual) {
        cout << actual->valor << " ";
        actual = actual->siguiente;
    }
    cout << endl;
}

//****************************************
// Destructor
template <typename Tipo>
Pila<Tipo>::~Pila() {
    Vaciar();
}
