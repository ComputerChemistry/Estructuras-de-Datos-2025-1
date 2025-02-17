#include <iostream>
#include "Pila.hpp"

using std::cout;

#define MAX_TAM 100 
//****************************************
template <typename Tipo>
Pila<Tipo>::Pila() : tope(-1) {}

//***************************************

template <typename Tipo>
void Pila<Tipo>::Apilar(Tipo valor) {
  if (EstaLlena()) throw "Pila esta llena";  // Agregar el punto y coma al final
  ++tope;
  elemento[tope] = valor;  // Asignación correcta
}

//***************************************
template <typename Tipo>
void Pila<Tipo>::Vaciar() {
  tope = -1;
}

//***************************************
//template <typename Tipo>
void Pila<Tipo>::Desapilar() {
  if (EstaVacia()) throw "Pila vacía"; // Corregir el texto
  --tope;
}

//***************************************
template <typename Tipo>
Tipo Pila<Tipo>::ObtenerTope() const {
  if (EstaVacia()) throw "Pila vacía";
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
template <typename Tipo>
void Pila<Tipo>::Imprimir() const {
  for (int i = 0; i <= tope; ++i) {
    std::cout << elemento[i] << ", ";
  }
  std::cout << "\b\b"; // Eliminar la última coma
}
