/**
 * @file Pila.hpp
 * @brief Implementación de una pila genérica basada en un arreglo dinámico.
 * \author: Carlos Eduardo Moreno Vargas, Joan Antonio Lazaro Silva
 * \date: 15/02/2025
 * Esta clase define una estructura de pila (stack) genérica, que permite realizar las operaciones
 * fundamentales sobre una pila: apilar, desapilar, obtener el tope, verificar si está vacía o llena,
 * y otras funciones útiles como obtener la capacidad y el tamaño.
 * 
 * La pila está implementada usando una estructura de nodos encadenados.
 */

#ifndef PILA_HPP_INCLUDED
#define PILA_HPP_INCLUDED

#include <iostream>
#include <stdexcept>

/**
 * @class Pila
 * @brief Implementación de una pila genérica basada en nodos.
 * 
 * Esta clase implementa una pila genérica usando nodos, soportando las operaciones básicas
 * como apilar, desapilar y obtener el valor del tope de la pila. La pila también permite
 * verificar si está vacía o llena.
 * 
 * @tparam Tipo El tipo de datos que almacena la pila. Puede ser cualquier tipo de dato.
 */
template <typename Tipo>
class Pila {
public:
    /**
     * @brief Constructor por defecto de la pila.
     * 
     * Inicializa una pila vacía.
     */
    Pila();
    
    /**
     * @brief Constructor de copia.
     * 
     * Crea una nueva pila que es una copia exacta de otra pila.
     * 
     * @param otra Pila a copiar.
     */
    Pila(const Pila<Tipo>& otra);
    
    /**
     * @brief Operador de asignación.
     * 
     * Asigna el contenido de otra pila a la pila actual.
     * 
     * @param otra Pila a asignar.
     * @return Referencia a la pila actual modificada.
     */
    Pila<Tipo>& operator=(const Pila<Tipo>& otra);
    
    /**
     * @brief Método para apilar un valor en la pila.
     * 
     * Agrega un nuevo elemento al tope de la pila.
     * 
     * @param valor Elemento a apilar.
     */
    void Apilar(Tipo valor);
    
    /**
     * @brief Método para desapilar un valor de la pila.
     * 
     * Elimina y retorna el elemento del tope de la pila.
     * Si la pila está vacía, lanza una excepción `std::runtime_error`.
     * 
     * @return Elemento desapilado.
     * @throws std::runtime_error si la pila está vacía.
     */
    Tipo Desapilar();
    
    /**
     * @brief Obtiene el valor del tope de la pila sin desapilarlo.
     * 
     * Devuelve el valor en el tope de la pila sin eliminarlo. Si la pila está vacía,
     * lanza una excepción `std::runtime_error`.
     * 
     * @return Valor del tope.
     * @throws std::runtime_error si la pila está vacía.
     */
    Tipo ObtenerTope() const;
    
    /**
     * @brief Verifica si la pila está vacía.
     * 
     * Devuelve `true` si la pila no contiene elementos, en caso contrario `false`.
     * 
     * @return true si la pila está vacía, false en caso contrario.
     */
    bool EstaVacia() const;
    
    /**
     * @brief Verifica si la pila está llena.
     * 
     * Devuelve `true` si la pila está llena. Depende de la implementación y de la capacidad
     * de la pila. En esta implementación, la pila nunca está llena, ya que utiliza una lista
     * enlazada dinámica.
     * 
     * @return true si la pila está llena, false en caso contrario.
     */
    bool EstaLlena() const;
    
    /**
     * @brief Destructor de la pila.
     * 
     * Libera toda la memoria utilizada por la pila.
     */
    ~Pila();
    
    /**
     * @brief Obtiene la capacidad actual de la pila.
     * 
     * Devuelve la capacidad de la pila, que representa el número máximo de elementos
     * que puede contener. En esta implementación, la capacidad está relacionada con
     * la cantidad de memoria asignada dinámicamente.
     * 
     * @return Capacidad de la pila.
     */
    int ObtenerCapacidad() const;
    
    /**
     * @brief Obtiene el tamaño actual de la pila.
     * 
     * Devuelve el número de elementos almacenados en la pila.
     * 
     * @return Tamaño de la pila.
     */
    int ObtenerTamanio() const;
    
    /**
     * @brief Imprime los elementos de la pila.
     * 
     * Imprime todos los elementos de la pila, comenzando desde el tope hacia la base.
     */
    void Imprimir() const;
    
    /**
     * @brief Vacía la pila eliminando todos sus elementos.
     * 
     * Elimina todos los elementos de la pila y la deja vacía.
     */
    void Vaciar();

private:
    int numElem; ///< Número de elementos en la pila.
    
    /**
     * @struct Nodo
     * @brief Estructura que representa un nodo de la pila.
     * 
     * Cada nodo contiene un valor y un puntero al siguiente nodo, formando una lista enlazada.
     */
    struct Nodo {
        Tipo valor; ///< Valor almacenado en el nodo.
        Nodo* siguiente; ///< Puntero al siguiente nodo en la pila.
    }; 
    
    Nodo* tope; ///< Puntero al nodo en el tope de la pila.
};

#include "../Templates/Pila.tpp"

#endif // PILA_HPP_INCLUDED
