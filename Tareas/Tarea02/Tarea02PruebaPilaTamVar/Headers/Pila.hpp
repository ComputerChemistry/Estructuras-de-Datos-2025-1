#ifndef PILA_HPP_INCLUDED
#define PILA_HPP_INCLUDED
#define MAX_TAM 100

#include "../Headers/Vector.hpp"

   template <typename Tipo>
class Pila{
public:
    Pila();                      // Constructor
    void Apilar(Tipo valor);      // Método para apilar un valor
    void Desapilar();             // Método para desapilar un valor
    Tipo ObtenerTope() const;     // Método para obtener el valor del tope
    bool EstaVacia() const;       // Método para verificar si la pila está vacía
    bool EstaLlena() const;       // Método para verificar si la pila está llena
    ~Pila();                      // Metodo destructor de la pila
    void Imprimir() const;        // Método para imprimir los elementos de la pila
    void Vaciar();                // Método para vaciar la pila

private:
    int tope;                     // Índice del tope de la pila
    Tipo elemento[MAX_TAM];        // Arreglo para almacenar los elementos de la pila
};

#include "../Templates/Pila.tpp"
#endif // PILA_HPP_INCLUDED
