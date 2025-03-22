#include "../Headers/DoublyCircularList.hpp"
#include <iostream>

using namespace std;

/**
 * @brief Constructor: inicializa la lista como vacía.
 */
DoublyCircularList::DoublyCircularList() : head(nullptr) {}

/**
 * @brief Destructor: libera toda la memoria ocupada por los nodos.
 */
DoublyCircularList::~DoublyCircularList() {
    if (!head) return;

    Node* current = head->next;
    while (current != head) {
        Node* temp = current;
        current = current->next;
        delete temp;
    }
    delete head;
    head = nullptr;
}

/**
 * @brief Inserta un nuevo nodo al final de la lista.
 * 
 * @param name Nombre del jugador a insertar.
 */
void DoublyCircularList::insertNode(const std::string& name) {
    Node* newNode = new Node(name);

    if (!head) {
        head = newNode;
        head->next = head;
        head->prev = head;
    } else {
        Node* tail = head->prev;
        tail->next = newNode;
        newNode->prev = tail;
        newNode->next = head;
        head->prev = newNode;
    }
}

/**
 * @brief Elimina un nodo de la lista.
 * 
 * @param deleteNode Puntero al nodo que se va a eliminar.
 */
void DoublyCircularList::deleteNode(Node* deleteNode) {
    if (!deleteNode || !head) return;

    if (deleteNode == head && head->next == head) {
        delete head;
        head = nullptr;
        return;
    }

    deleteNode->prev->next = deleteNode->next;
    deleteNode->next->prev = deleteNode->prev;

    if (deleteNode == head) {
        head = head->next;
    }

    delete deleteNode;
}

/**
 * @brief Imprime los elementos de la lista desde un nodo dado.
 * 
 * @param marker Nodo desde donde comienza la impresión.
 */
void DoublyCircularList::printList(Node* marker) const {
    if (!marker) return;

    Node* current = marker;
    do {
        cout << current->data;
        current = current->next;
        if (current != marker) cout << " -> ";
    } while (current != marker);
    cout << endl;
}

/**
 * @brief Devuelve el puntero al nodo cabeza de la lista.
 * 
 * @return Puntero al primer nodo.
 */
Node* DoublyCircularList::getHead() const {
    return head;
}

/**
 * @brief Inicia el juego de eliminación (tipo Josephus) basado en saltos.
 * 
 * Elimina cada k-ésimo jugador hasta que queda uno solo.
 * 
 * @param k Número de rondas (saltos) antes de eliminar a un jugador.
 */
void DoublyCircularList::startGame(int k) {
    if (!head || k <= 0) return;

    Node* current = head;

    cout << "\nInicio del juego:" << endl;
    printList(current);

    while (current->next != current) {
        // Saltar k-1 jugadores
        for (int i = 1; i < k; ++i) {
            current = current->next;
        }

        cout << "Eliminado: " << current->data << endl;
        Node* toDelete = current;
        current = current->next; 
        deleteNode(toDelete);

        cout << "Jugadores restantes: ";
        printList(current);
    }

    cout << "\n¡El ganador es: " << current->data << "!" << endl;
}
