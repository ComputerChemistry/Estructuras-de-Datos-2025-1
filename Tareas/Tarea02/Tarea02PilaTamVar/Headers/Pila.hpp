#ifndef PILA_HPP_INCLUDED
#define PILA_HPP_INCLUDED
//#define MAX_TAM 100

#include <iostream>
#include <stdexcept>
#include "../Headers/Vector.hpp"

template <typename Tipo>
class Pila {
public:
    Pila();                      // Constructor
    Pila(const Pila<Tipo>& otra); // Constructor de copia
    Pila<Tipo>& operator=(const Pila<Tipo>& otra); // Operador de asignación
    void Apilar(Tipo valor);      // Método para apilar un valor
    Tipo Desapilar();             // Método para desapilar un valor
    Tipo ObtenerTope() const;     // Método para obtener el valor del tope
    bool EstaVacia() const;       // Método para verificar si la pila está vacía
    bool EstaLlena() const;       // Método para verificar si la pila está llena
    ~Pila();                      // Metodo destructor de la pila
    int ObtenerCapacidad() const;
    int ObtenerTamanio() const;
    void Imprimir() const;        // Método para imprimir los elementos de la pila
    void Vaciar();                // Método para vaciar la pila

private:
    int tope;                      // Índice del tope de la pila
    Tipo* elemento;               // Arreglo para almacenar los elementos de la pila
    void Redimensionar(); 
    int capacidad;
};

#include "../Templates/Pila.tpp"
#endif // PILA_HPP_INCLUDED
