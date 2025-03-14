#ifndef ORDEREDLIST_HPP_INCLUDED
#define ORDEREDLIST_HPP_INCLUDED

#include <iostream>

/**
 * @file OrderedList.hpp
 * 
 * @brief Implementación de una lista doblemente enlazada ordenada.
 * 
 * Esta clase implementa una lista doblemente enlazada donde los elementos se 
 * insertan de manera ordenada. Proporciona métodos para agregar, eliminar, 
 * buscar elementos, vaciar la lista, obtener el tamaño, y mezclar dos listas.
 * También permite imprimir la lista en orden ascendente y descendente.
 * 
 * @authors Carlos Eduardo Moreno Vargas, Joan Antonio Lazaro Silva
 * @date 13 de marzo del 2025
 * @course Estructuras de Datos - Tarea 6: Lista ordenada compuesta
 * 
 * @tparam T Tipo de dato almacenado en la lista.
 */
template <typename T>
class OrderedList {
private:
    /**
     * @brief Estructura que representa un nodo en la lista doblemente enlazada.
     */
    struct Node {
        T data; ///< El dato almacenado en el nodo.
        Node* next; ///< Puntero al siguiente nodo en la lista.
        Node* prev; ///< Puntero al nodo anterior en la lista.
        
        /**
         * @brief Constructor para inicializar un nodo con un valor.
         * 
         * @param val El valor que se almacena en el nodo.
         */
        Node(T val) : data(val), next(nullptr), prev(nullptr) {}
    };

    Node* head; ///< Puntero al primer nodo de la lista.
    Node* tail; ///< Puntero al último nodo de la lista.
    size_t size; ///< Tamaño de la lista.

    /**
     * @brief Elimina un nodo de la lista.
     * 
     * @param node El nodo a eliminar.
     */
    void deleteNode(Node* node);

public:
    /**
     * @brief Constructor por defecto que inicializa la lista vacía.
     */
    OrderedList();

    /**
     * @brief Constructor de copia que crea una nueva lista a partir de otra existente.
     * 
     * @param other La lista de la cual se copiará la información.
     */
    OrderedList(const OrderedList& other);

    /**
     * @brief Destructor que elimina todos los nodos de la lista.
     */
    ~OrderedList();

    /**
     * @brief Operador de asignación que asigna una lista a otra.
     * 
     * @param other La lista que se asignará.
     * @return Referencia a la lista actual.
     */
    OrderedList& operator=(const OrderedList& other);

    /**
     * @brief Agrega un elemento a la lista de manera ordenada.
     * 
     * @param value El valor a agregar en la lista.
     */
    void add(const T& value);

    /**
     * @brief Elimina el primer nodo que contiene el valor especificado.
     * 
     * @param value El valor que se eliminará de la lista.
     */
    void remove(const T& value);

    /**
     * @brief Busca un elemento en la lista.
     * 
     * @param value El valor que se buscará en la lista.
     * @return true Si el elemento fue encontrado, false en caso contrario.
     */
    bool find(const T& value) const;

    /**
     * @brief Obtiene el tamaño de la lista.
     * 
     * @return El tamaño de la lista (número de elementos).
     */
    size_t getSize() const;

    /**
     * @brief Verifica si la lista está vacía.
     * 
     * @return true Si la lista está vacía, false en caso contrario.
     */
    bool isEmpty() const;

    /**
     * @brief Elimina todos los elementos de la lista.
     */
    void clear();

    /**
     * @brief Imprime los elementos de la lista en orden ascendente.
     */
    void printAscend() const;

    /**
     * @brief Imprime los elementos de la lista en orden descendente.
     */
    void printDescend() const;

    /**
     * @brief Mezcla dos listas ordenadas, creando una nueva lista ordenada 
     * con los elementos de ambas listas.
     * 
     * @param other La lista que se combinará con la lista actual.
     */
    void merge(const OrderedList& other);
};

#include "../Templates/OrderedList.tpp"

#endif //ORDEREDLIST_HPP_INCLUDED
