#ifndef LISTADOBLE_HPP
#define LISTADOBLE_HPP

#include <iostream>
#include <functional>
#include <stdexcept>

/**
 * @file ListaDoble.hpp
 * @brief Implementación de una lista doblemente enlazada como una plantilla de clase.
 * 
 * Esta clase implementa una lista doblemente enlazada que soporta una serie de operaciones como insertar, eliminar,
 * acceder a elementos, buscar elementos, ordenar, intercambiar listas y transferir elementos entre listas.
 * 
 * @authors Carlos Eduardo Moreno Vargas, Joan Antonio Lázaro Silva
 * @date 4 de marzo de 2025
 * @course Estructuras de Datos
 * 
 * @tparam Tipo El tipo de los elementos almacenados en la lista.
 */
template <typename Tipo>
class Lista {
private:
    /**
     * @brief Estructura que representa un nodo de la lista.
     * 
     * Cada nodo contiene un valor de tipo Tipo, un puntero al siguiente nodo y un puntero al nodo anterior.
     */
    struct Node {
        Tipo data; ///< Valor del nodo.
        Node* next; ///< Puntero al siguiente nodo.
        Node* prev; ///< Puntero al nodo anterior.

        /**
         * @brief Constructor de un nodo.
         * 
         * @param value El valor a almacenar en el nodo.
         */
        Node(const Tipo& value) : data(value), next(nullptr), prev(nullptr) {}
    };

    Node* head; ///< Puntero al primer nodo de la lista.
    Node* tail; ///< Puntero al último nodo de la lista.
    size_t size; ///< Número de elementos en la lista.

public:
    /**
     * @brief Constructor por defecto de la lista.
     * Inicializa una lista vacía.
     */
    Lista();

    /**
     * @brief Constructor de copia.
     * Copia el contenido de otra lista en la lista actual.
     * 
     * @param other La lista a copiar.
     */
    Lista(const Lista& other);

    /**
     * @brief Operador de asignación.
     * Asigna el contenido de otra lista a la lista actual.
     * 
     * @param other La lista a asignar.
     * @return Lista& Referencia a la lista actual.
     */
    Lista& operator=(const Lista& other);

    /**
     * @brief Destructor de la lista.
     * Libera toda la memoria ocupada por la lista.
     */
    ~Lista();

    /**
     * @brief Agrega un elemento al principio de la lista.
     * 
     * @param value El valor a agregar.
     */
    void pushFront(const Tipo& value);

    /**
     * @brief Agrega un elemento al final de la lista.
     * 
     * @param value El valor a agregar.
     */
    void pushBack(const Tipo& value);

    /**
     * @brief Inserta un elemento en una posición específica de la lista.
     * 
     * @param index El índice de la posición en la que insertar el elemento.
     * @param value El valor a insertar.
     */
    void insertAt(size_t index, const Tipo& value);

    /**
     * @brief Elimina el primer elemento de la lista.
     */
    void popFront();

    /**
     * @brief Elimina el último elemento de la lista.
     */
    void popBack();

    /**
     * @brief Elimina el elemento en una posición específica de la lista.
     * 
     * @param index El índice del elemento a eliminar.
     */
    void removeAt(size_t index);

    /**
     * @brief Elimina la primera ocurrencia de un valor en la lista.
     * 
     * @param value El valor a eliminar.
     */
    void removeValue(const Tipo& value);

    /**
     * @brief Elimina los elementos que cumplan con una condición.
     * 
     * @param condition Una función que retorna true para los elementos a eliminar.
     */
    void removeIf(std::function<bool(const Tipo&)> condition);

    /**
     * @brief Elimina los elementos duplicados de la lista.
     */
    void removeDuplicates();

    /**
     * @brief Devuelve el primer elemento de la lista.
     * 
     * @return Tipo El primer elemento de la lista.
     */
    Tipo front() const;

    /**
     * @brief Devuelve el último elemento de la lista.
     * 
     * @return Tipo El último elemento de la lista.
     */
    Tipo back() const;

    /**
     * @brief Devuelve el elemento en una posición específica.
     * 
     * @param index El índice del elemento.
     * @return Tipo El valor del elemento en la posición especificada.
     */
    Tipo at(size_t index) const;

    /**
     * @brief Modifica el valor de un elemento en una posición específica.
     * 
     * @param index El índice del elemento a modificar.
     * @param value El nuevo valor.
     */
    void setAt(size_t index, const Tipo& value);

    /**
     * @brief Verifica si la lista está vacía.
     * 
     * @return true Si la lista está vacía.
     * @return false Si la lista tiene elementos.
     */
    bool isEmpty() const;

    /**
     * @brief Obtiene el tamaño de la lista.
     * 
     * @return size_t El número de elementos en la lista.
     */
    size_t getSize() const;

    /**
     * @brief Vacía la lista, eliminando todos los elementos.
     */
    void clear();

    /**
     * @brief Imprime la lista de inicio a fin.
     */
    void print() const;

    /**
     * @brief Imprime la lista de fin a inicio.
     */
    void printReverse() const;

    /**
     * @brief Verifica si un valor está en la lista.
     * 
     * @param value El valor a buscar.
     * @return true Si el valor está en la lista.
     * @return false Si el valor no está en la lista.
     */
    bool contains(const Tipo& value) const;

    /**
     * @brief Busca la primera ocurrencia de un valor en la lista.
     * 
     * @param value El valor a buscar.
     * @return size_t El índice de la primera ocurrencia del valor.
     */
    size_t find(const Tipo& value) const;

    /**
     * @brief Busca la posición de un valor en la lista.
     * 
     * @param value El valor a buscar.
     * @return size_t La posición del valor.
     */
    size_t search(const Tipo& value) const;

    /**
     * @brief Encuentra la posición de un valor en la lista.
     * 
     * @param value El valor a buscar.
     * @return size_t La posición del valor encontrado.
     */
    size_t findPosition(const Tipo& value) const;

    /**
     * @brief Sobrecarga del operador [] para acceso a un elemento de la lista.
     * 
     * @param index El índice del elemento a acceder.
     * @return Tipo& Referencia al elemento en la posición especificada.
     */
    Tipo& operator[](size_t index);

    /**
     * @brief Sobrecarga del operador [] para acceso a un elemento de la lista (versión constante).
     * 
     * @param index El índice del elemento a acceder.
     * @return const Tipo& Referencia constante al elemento en la posición especificada.
     */
    const Tipo& operator[](size_t index) const;

    /**
     * @brief Ordena la lista de menor a mayor.
     */
    void sort();

    /**
     * @brief Intercambia el contenido de la lista con otra lista.
     * 
     * @param other La otra lista con la que se va a intercambiar el contenido.
     */
    void swap(Lista& other);

    /**
     * @brief Transfiere elementos de una lista a otra, desde una posición de inicio hasta una posición final.
     * 
     * @param other La lista desde donde se van a transferir los elementos.
     * @param start La posición de inicio en la lista origen.
     * @param end La posición final en la lista origen.
     */
    void transferFrom(Lista& other, size_t start, size_t end);

    /**
     * @brief Transfiere todos los elementos de una lista a otra desde una posición de inicio.
     * 
     * @param other La lista desde donde se van a transferir los elementos.
     * @param start La posición de inicio en la lista origen.
     */
    void transferFrom(Lista& other, size_t start);

    /**
     * @brief Transfiere todos los elementos de una lista a otra.
     * 
     * @param other La lista desde donde se van a transferir los elementos.
     */
    void transferFrom(Lista& other);
};

#include "../Templates/ListaDoble.tpp"

#endif
