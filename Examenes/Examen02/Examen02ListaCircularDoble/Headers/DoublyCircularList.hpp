#ifndef DOUBLYCIRCULARLIST_HPP_INCLUDED
#define DOUBLYCIRCULARLIST_HPP_INCLUDED
#include <string> 

/**
 * @file DoublyCircularList.hpp
 * @brief Implementación de una lista circular doblemente enlazada con nombres de jugadores.
 * 
 * Este archivo contiene la definición de la estructura Node y la clase DoublyCircularList.
 * La lista circular doble permite insertar y eliminar nodos de forma eficiente,
 * así como simular un juego de eliminación basado en esta estructura.
 * 
 * @author Carlos Eduardo Moreno Vargas
 * @date 2025-1
 * @course Estructuras de Datos 2025-1
 */

/**
 * @struct Node
 * @brief Representa un nodo de la lista circular doble.
 * 
 * Cada nodo contiene un nombre (string) y dos punteros que apuntan al siguiente nodo
 * y al nodo anterior en la lista. Esto permite recorrer la lista de manera bidireccional.
 */
struct Node {
    std::string data;   /**< Nombre del jugador almacenado en el nodo. */
    Node* next;         /**< Puntero al siguiente nodo en la lista. */
    Node* prev;         /**< Puntero al nodo anterior en la lista. */

    /**
     * @brief Constructor del nodo.
     * @param d Nombre del jugador para el nodo.
     * 
     * Este constructor inicializa un nuevo nodo con el nombre dado,
     * y establece los punteros `next` y `prev` a `nullptr`.
     */
    Node(const std::string& d) : data(d), next(nullptr), prev(nullptr) {}
};

/**
 * @class DoublyCircularList
 * @brief Implementación de una lista circular doblemente enlazada.
 * 
 * Esta clase permite insertar, eliminar e imprimir nodos en una lista circular doblemente enlazada.
 * Además, incluye una función para simular un juego de eliminación basado en esta estructura.
 */
class DoublyCircularList {
private:
    Node* head; /**< Puntero al primer nodo de la lista. */

public:
    /**
     * @brief Constructor de la clase DoublyCircularList.
     * 
     * Este constructor inicializa una lista vacía, estableciendo el puntero `head` en `nullptr`.
     * 
     * @see DoublyCircularList::~DoublyCircularList()
     */
    DoublyCircularList();

    /**
     * @brief Destructor de la clase DoublyCircularList.
     * 
     * Este destructor se encarga de liberar la memoria de todos los nodos de la lista
     * cuando la instancia de la lista es destruida.
     */
    ~DoublyCircularList();

    /**
     * @brief Inserta un nuevo nodo al final de la lista circular.
     * 
     * Este método crea un nodo con el nombre dado e inserta el nodo al final de la lista circular.
     * Si la lista está vacía, el nodo se convierte en el primer y último nodo de la lista.
     * 
     * @param name Nombre del jugador que se almacenará en el nodo.
     */
    void insertNode(const std::string& name);

    /**
     * @brief Elimina un nodo específico de la lista.
     * 
     * Este método elimina el nodo especificado de la lista. Actualiza los punteros `next`
     * y `prev` de los nodos adyacentes al nodo a eliminar para mantener la integridad
     * de la lista circular.
     * 
     * @param deleteNode Nodo a eliminar de la lista.
     */
    void deleteNode(Node* deleteNode);

    /**
     * @brief Imprime la lista de jugadores desde el nodo marcado.
     * 
     * Este método recorre la lista a partir del nodo especificado e imprime los nombres de los
     * jugadores en el orden en que aparecen en la lista.
     * 
     * @param marker Nodo desde el cual comenzar a imprimir la lista.
     */
    void printList(Node* marker) const;

    /**
     * @brief Obtiene el primer nodo de la lista (cabeza).
     * 
     * Este método devuelve el puntero al primer nodo de la lista, también conocido como `head`.
     * 
     * @return Puntero al primer nodo de la lista.
     */
    Node* getHead() const;

    /**
     * @brief Inicia el juego de eliminación basado en la lista circular.
     * 
     * Este método simula el juego de eliminación de jugadores. Comienza desde el nodo inicial
     * (la cabeza de la lista) y elimina cada k-ésimo jugador hasta que solo queda uno.
     * Durante el proceso, la lista de jugadores se imprime después de cada eliminación.
     * 
     * @param k Número de rondas o saltos antes de eliminar un jugador.
     */
    void startGame(int k);
};

#endif //DOUBLYCIRCULARLIST_HPP_INCLUDED
