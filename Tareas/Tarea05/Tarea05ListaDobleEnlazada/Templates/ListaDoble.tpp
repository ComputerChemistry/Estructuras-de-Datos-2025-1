#ifndef LISTADOBLE_TPP
#define LISTADOBLE_TPP

#include "../Headers/ListaDoble.hpp"

// Constructor
template <typename Tipo>
Lista<Tipo>::Lista() : head(nullptr), tail(nullptr), size(0) {}

// Destructor
template <typename Tipo>
Lista<Tipo>::~Lista() {
    clear();
}

// Constructor de copia
template <typename Tipo>
Lista<Tipo>::Lista(const Lista& other) : head(nullptr), tail(nullptr), size(0) {
    Node* current = other.head;
    while (current) {
        pushBack(current->data);
        current = current->next;
    }
}

// Operador de asignación
template <typename Tipo>
Lista<Tipo>& Lista<Tipo>::operator=(const Lista& other) {
    if (this != &other) {
        clear();
        Node* current = other.head;
        while (current) {
            pushBack(current->data);
            current = current->next;
        }
    }
    return *this;
}

// Función que agrega un valor al frente
template <typename Tipo>
void Lista<Tipo>::pushFront(const Tipo& value) {
    Node* newNode = new Node(value);
    if (isEmpty()) {
        head = tail = newNode;
    } else {
        newNode->next = head;
        head->prev = newNode;
        head = newNode;
    }
    size++;
}

// Función que agrega un valor al final
template <typename Tipo>
void Lista<Tipo>::pushBack(const Tipo& value) {
    Node* newNode = new Node(value);
    if (isEmpty()) {
        head = tail = newNode;
    } else {
        tail->next = newNode;
        newNode->prev = tail;
        tail = newNode;
    }
    size++;
}

// Elimina el primer elemento
template <typename Tipo>
void Lista<Tipo>::popFront() {
    if (!isEmpty()) {
        Node* temp = head;
        head = head->next;
        if (head) {
            head->prev = nullptr;
        } else {
            tail = nullptr;
        }
        delete temp;
        size--;
    }
}

// Elimina el último elemento
template <typename Tipo>
void Lista<Tipo>::popBack() {
    if (!isEmpty()) {
        Node* temp = tail;
        tail = tail->prev;
        if (tail) {
            tail->next = nullptr;
        } else {
            head = nullptr;
        }
        delete temp;
        size--;
    }
}

// Devuelve el primer valor
template <typename Tipo>
Tipo Lista<Tipo>::front() const {
    if (isEmpty()) throw std::out_of_range("Lista vacía");
    return head->data;
}

// Devuelve el último valor
template <typename Tipo>
Tipo Lista<Tipo>::back() const {
    if (isEmpty()) throw std::out_of_range("Lista vacía");
    return tail->data;
}

// Verifica si la lista está vacía
template <typename Tipo>
bool Lista<Tipo>::isEmpty() const {
    return size == 0;
}

// Retorna el tamaño de la lista
template <typename Tipo>
size_t Lista<Tipo>::getSize() const {
    return size;
}

// Limpia la lista
template <typename Tipo>
void Lista<Tipo>::clear() {
    while (!isEmpty()) {
        popFront();
    }
}

// Imprime la lista
template <typename Tipo>
void Lista<Tipo>::print() const {
    Node* current = head;
    while (current) {
        std::cout << current->data << " ";
        current = current->next;
    }
    std::cout << std::endl;
}

// Imprime la lista en orden inverso
template <typename Tipo>
void Lista<Tipo>::printReverse() const {
    Node* current = tail;
    while (current) {
        std::cout << current->data << " ";
        current = current->prev;
    }
    std::cout << std::endl;
}

// Operador [] para acceso por índice
template <typename Tipo>
Tipo& Lista<Tipo>::operator[](size_t index) {
    if (index >= size) throw std::out_of_range("Índice fuera de rango");
    Node* current = head;
    for (size_t i = 0; i < index; ++i) {
        current = current->next;
    }
    return current->data;
}

// Operador [] para acceso constante por índice
template <typename Tipo>
const Tipo& Lista<Tipo>::operator[](size_t index) const {
    if (index >= size) throw std::out_of_range("Índice fuera de rango");
    Node* current = head;
    for (size_t i = 0; i < index; ++i) {
        current = current->next;
    }
    return current->data;
}

// Busca un valor en la lista (agregado)
template <typename Tipo>
bool Lista<Tipo>::contains(const Tipo& value) const {
    Node* current = head;
    while (current) {
        if (current->data == value) return true;
        current = current->next;
    }
    return false;
}

// Encuentra el índice de un valor (agregado)
template <typename Tipo>
size_t Lista<Tipo>::find(const Tipo& value) const {
    Node* current = head;
    size_t index = 0;
    while (current) {
        if (current->data == value) return index;
        current = current->next;
        ++index;
    }
    return -1; // Devuelve -1 si no lo encuentra
}

// Encuentra la posición de un valor en la lista
template <typename Tipo>
size_t Lista<Tipo>::findPosition(const Tipo& value) const {
    Node* current = head;
    size_t index = 0;
    while (current) {
        if (current->data == value) return index;
        current = current->next;
        ++index;
    }
    return -1; // No encontrado
}

// Transfiere los elementos de otra lista
template <typename Tipo>
void Lista<Tipo>::transferFrom(Lista& other) {
    while (!other.isEmpty()) {
        pushBack(other.front());
        other.popFront();
    }
}


// Elimina un elemento en la posición indicada
template <typename Tipo>
void Lista<Tipo>::removeAt(size_t index) {
    if (index >= size) throw std::out_of_range("Índice fuera de rango");
    
    Node* current = head;
    for (size_t i = 0; i < index; ++i) {
        current = current->next;
    }

    // Si es el primer elemento
    if (current == head) {
        popFront();
    }
    // Si es el último elemento
    else if (current == tail) {
        popBack();
    } 
    // Si es un elemento intermedio
    else {
        current->prev->next = current->next;
        current->next->prev = current->prev;
        delete current;
        size--;
    }
}

// Busca un valor en la lista y retorna la posición (similar a find)
template <typename Tipo>
size_t Lista<Tipo>::search(const Tipo& value) const {
    Node* current = head;
    size_t index = 0;
    while (current) {
        if (current->data == value) return index;
        current = current->next;
        ++index;
    }
    return -1; // No encontrado
}

// Ordena la lista
template <typename Tipo>
void Lista<Tipo>::sort() {
    if (isEmpty() || size == 1) return;

    bool swapped;
    do {
        swapped = false;
        Node* current = head;
        while (current && current->next) {
            if (current->data > current->next->data) {
                std::swap(current->data, current->next->data);
                swapped = true;
            }
            current = current->next;
        }
    } while (swapped);
}

// Intercambia el contenido de dos listas
template <typename Tipo>
void Lista<Tipo>::swap(Lista& other) {
    std::swap(head, other.head);
    std::swap(tail, other.tail);
    std::swap(size, other.size);
}

#endif
