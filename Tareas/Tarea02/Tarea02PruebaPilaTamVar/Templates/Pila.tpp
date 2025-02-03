// Pila.tpp
#include <iostream>
#include "../Headers/Pila.hpp"

using std::cout;
using std::endl;

//****************************************
template <typename Tipo>
Pila<Tipo>::Pila() : tope(-1) {}

//***************************************
template <typename Tipo>
void Pila<Tipo>::Apilar(Tipo valor) {
    if (EstaLlena()) {
        throw std::overflow_error("Error: La pila está llena");
    }
    elemento[++tope] = valor;
}

//***************************************
template <typename Tipo>
void Pila<Tipo>::Vaciar() {
    tope = -1;
}

//***************************************
template <typename Tipo>
void Pila<Tipo>::Desapilar() {
    if (EstaVacia()) {
        throw std::underflow_error("Error: La pila está vacía");
    }
    --tope;
}

//***************************************
template <typename Tipo>
Tipo Pila<Tipo>::ObtenerTope() const {
    if (EstaVacia()) {
        throw std::underflow_error("Error: La pila está vacía");
    }
    return elemento[tope];
}

//***************************************
template <typename Tipo>
bool Pila<Tipo>::EstaVacia() const {
    return tope == -1;
}

//***************************************
template <typename Tipo>
bool Pila<Tipo>::EstaLlena() const {
    return tope + 1 == MAX_TAM;
}

//***************************************
//Destructor 
template <typename Tipo> 
Pila<Tipo>::~Pila(){
    delete [] elemento;
}
//***************************************
template <typename Tipo>
void Pila<Tipo>::Imprimir() const {
    if (EstaVacia()) {
        cout << "Pila vacía" << endl;
        return;
    }
    for (int i = 0; i <= tope; ++i) {
        cout << elemento[i] << " ";
    }
    cout << endl;
}
