#ifndef PILA_HPP_INCLUDED
#define PILA_HPP_INCLUDED

#include <iostream>
#include <stdexcept>

/**
 * \class Pila
 * \brief Implementación de una pila genérica basada en un arreglo dinámico.
 * 
 * Permite operaciones como apilar, desapilar, obtener el tope y verificar si está vacía o llena.
 */
template <typename Tipo>
class Pila {
public:
    /**
     * \brief Constructor por defecto de la pila.
     */
    Pila();
    
    /**
     * \brief Constructor de copia.
     * \param otra Pila a copiar.
     */
    Pila(const Pila<Tipo>& otra);
    
    /**
     * \brief Operador de asignación.
     * \param otra Pila a asignar.
     * \return Referencia a la pila actual modificada.
     */
    Pila<Tipo>& operator=(const Pila<Tipo>& otra);
    
    /**
     * \brief Método para apilar un valor en la pila.
     * \param valor Elemento a apilar.
     */
    void Apilar(Tipo valor);
    
    /**
     * \brief Método para desapilar un valor de la pila.
     * \return Elemento desapilado.
     * \throws std::runtime_error si la pila está vacía.
     */
    Tipo Desapilar();
    
    /**
     * \brief Obtiene el valor del tope de la pila sin desapilarlo.
     * \return Valor del tope.
     * \throws std::runtime_error si la pila está vacía.
     */
    Tipo ObtenerTope() const;
    
    /**
     * \brief Verifica si la pila está vacía.
     * \return true si la pila está vacía, false en caso contrario.
     */
    bool EstaVacia() const;
    
    /**
     * \brief Verifica si la pila está llena.
     * \return true si la pila está llena, false en caso contrario.
     */
    bool EstaLlena() const;
    
    /**
     * \brief Destructor de la pila.
     */
    ~Pila();
    
    /**
     * \brief Obtiene la capacidad actual de la pila.
     * \return Capacidad de la pila.
     */
    int ObtenerCapacidad() const;
    
    /**
     * \brief Obtiene el tamaño actual de la pila (número de elementos almacenados).
     * \return Tamaño de la pila.
     */
    int ObtenerTamanio() const;
    
    /**
     * \brief Imprime los elementos de la pila.
     */
    void Imprimir() const;
    
    /**
     * \brief Vacía la pila eliminando todos sus elementos.
     */
    void Vaciar();

private:
    int numElem; 
    struct Nodo {
        Tipo valor; 
        Nodo* siguiente; 
    }; 
    
    Nodo* tope; // Puntero al tope de la pila
};

#include "../Templates/Pila.tpp"
#endif // PILA_HPP_INCLUDED
