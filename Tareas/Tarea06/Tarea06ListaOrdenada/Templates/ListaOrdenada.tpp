#ifndef ORDEREDLIST_TPP
#define ORDEREDLIST_TPP

#include "OrderedList.hpp"

// Default constructor
template <typename T>
OrderedList<T>::OrderedList() : head(nullptr), tail(nullptr), size(0) {}

// Copy constructor
template <typename T>
OrderedList<T>::OrderedList(const OrderedList& other) : head(nullptr), tail(nullptr), size(0) {
    Node* current = other.head;
    while (current != nullptr) {
        add(current->data);
        current = current->next;
    }
}

// Destructor
template <typename T>
OrderedList<T>::~OrderedList() {
    clear();
}

// Assignment operator
template <typename T>
OrderedList<T>& OrderedList<T>::operator=(const OrderedList& other) {
    if (this != &other) {
        clear();
        Node* current = other.head;
        while (current != nullptr) {
            add(current->data);
            current = current->next;
        }
    }
    return *this;
}

// Add an element in order
template <typename T>
void OrderedList<T>::add(const T& value) {
    Node* newNode = new Node(value);
    if (isEmpty()) {
        head = tail = newNode;
    } else {
        Node* current = head;
        while (current != nullptr && current->data < value) {
            current = current->next;
        }

        if (current == head) {
            newNode->next = head;
            head->prev = newNode;
            head = newNode;
        } else if (current == nullptr) {
            tail->next = newNode;
            newNode->prev = tail;
            tail = newNode;
        } else {
            newNode->next = current;
            newNode->prev = current->prev;
            if (current->prev) {
                current->prev->next = newNode;
            }
            current->prev = newNode;
        }
    }
    size++;
}

// Remove a value (first occurrence)
template <typename T>
void OrderedList<T>::remove(const T& value) {
    Node* current = head;
    while (current != nullptr && current->data != value) {
        current = current->next;
    }

    if (current != nullptr) {
        deleteNode(current);
        size--;
    }
}

// Private method to delete a node
template <typename T>
void OrderedList<T>::deleteNode(Node* node) {
    if (node->prev != nullptr) {
        node->prev->next = node->next;
    } else {
        head = node->next;
    }

    if (node->next != nullptr) {
        node->next->prev = node->prev;
    } else {
        tail = node->prev;
    }

    delete node;
}

// Find a value
template <typename T>
bool OrderedList<T>::find(const T& value) const {
    Node* current = head;
    while (current != nullptr) {
        if (current->data == value) {
            return true;
        }
        current = current->next;
    }
    return false;
}

// Get the size of the list
template <typename T>
size_t OrderedList<T>::getSize() const {
    return size;
}

// Check if the list is empty
template <typename T>
bool OrderedList<T>::isEmpty() const {
    return size == 0;
}

// Clear the list
template <typename T>
void OrderedList<T>::clear() {
    Node* current = head;
    while (current != nullptr) {
        Node* next = current->next;
        delete current;
        current = next;
    }
    head = tail = nullptr;
    size = 0;
}

// Print the list in ascending order
template <typename T>
void OrderedList<T>::printAscend() const {
    Node* current = head;
    while (current != nullptr) {
        std::cout << current->data << " ";
        current = current->next;
    }
    std::cout << std::endl;
}

// Print the list in descending order
template <typename T>
void OrderedList<T>::printDescend() const {
    Node* current = tail;
    while (current != nullptr) {
        std::cout << current->data << " ";
        current = current->prev;
    }
    std::cout << std::endl;
}

// Merge two ordered lists
template <typename T>
void OrderedList<T>::merge(const OrderedList& other) {
    Node* current = other.head;
    while (current != nullptr) {
        add(current->data);
        current = current->next;
    }
}

#endif
#ifndef ORDEREDLIST_TPP
#define ORDEREDLIST_TPP

#include "OrderedList.hpp"

// Default constructor
template <typename T>
OrderedList<T>::OrderedList() : head(nullptr), tail(nullptr), size(0) {}

// Copy constructor
template <typename T>
OrderedList<T>::OrderedList(const OrderedList& other) : head(nullptr), tail(nullptr), size(0) {
    Node* current = other.head;
    while (current != nullptr) {
        add(current->data);
        current = current->next;
    }
}

// Destructor
template <typename T>
OrderedList<T>::~OrderedList() {
    clear();
}

// Assignment operator
template <typename T>
OrderedList<T>& OrderedList<T>::operator=(const OrderedList& other) {
    if (this != &other) {
        clear();
        Node* current = other.head;
        while (current != nullptr) {
            add(current->data);
            current = current->next;
        }
    }
    return *this;
}

// Add an element in order
template <typename T>
void OrderedList<T>::add(const T& value) {
    Node* newNode = new Node(value);
    if (isEmpty()) {
        head = tail = newNode;
    } else {
        Node* current = head;
        while (current != nullptr && current->data < value) {
            current = current->next;
        }

        if (current == head) {
            newNode->next = head;
            head->prev = newNode;
            head = newNode;
        } else if (current == nullptr) {
            tail->next = newNode;
            newNode->prev = tail;
            tail = newNode;
        } else {
            newNode->next = current;
            newNode->prev = current->prev;
            if (current->prev) {
                current->prev->next = newNode;
            }
            current->prev = newNode;
        }
    }
    size++;
}

// Remove a value (first occurrence)
template <typename T>
void OrderedList<T>::remove(const T& value) {
    Node* current = head;
    while (current != nullptr && current->data != value) {
        current = current->next;
    }

    if (current != nullptr) {
        deleteNode(current);
        size--;
    }
}

// Private method to delete a node
template <typename T>
void OrderedList<T>::deleteNode(Node* node) {
    if (node->prev != nullptr) {
        node->prev->next = node->next;
    } else {
        head = node->next;
    }

    if (node->next != nullptr) {
        node->next->prev = node->prev;
    } else {
        tail = node->prev;
    }

    delete node;
}

// Find a value
template <typename T>
bool OrderedList<T>::find(const T& value) const {
    Node* current = head;
    while (current != nullptr) {
        if (current->data == value) {
            return true;
        }
        current = current->next;
    }
    return false;
}

// Get the size of the list
template <typename T>
size_t OrderedList<T>::getSize() const {
    return size;
}

// Check if the list is empty
template <typename T>
bool OrderedList<T>::isEmpty() const {
    return size == 0;
}

// Clear the list
template <typename T>
void OrderedList<T>::clear() {
    Node* current = head;
    while (current != nullptr) {
        Node* next = current->next;
        delete current;
        current = next;
    }
    head = tail = nullptr;
    size = 0;
}

// Print the list in ascending order
template <typename T>
void OrderedList<T>::printAscend() const {
    Node* current = head;
    while (current != nullptr) {
        std::cout << current->data << " ";
        current = current->next;
    }
    std::cout << std::endl;
}

// Print the list in descending order
template <typename T>
void OrderedList<T>::printDescend() const {
    Node* current = tail;
    while (current != nullptr) {
        std::cout << current->data << " ";
        current = current->prev;
    }
    std::cout << std::endl;
}

// Merge two ordered lists
template <typename T>
void OrderedList<T>::merge(const OrderedList& other) {
    Node* current = other.head;
    while (current != nullptr) {
        add(current->data);
        current = current->next;
    }
}

#endif
#ifndef ORDEREDLIST_TPP
#define ORDEREDLIST_TPP

#include "OrderedList.hpp"

// Default constructor
template <typename T>
OrderedList<T>::OrderedList() : head(nullptr), tail(nullptr), size(0) {}

// Copy constructor
template <typename T>
OrderedList<T>::OrderedList(const OrderedList& other) : head(nullptr), tail(nullptr), size(0) {
    Node* current = other.head;
    while (current != nullptr) {
        add(current->data);
        current = current->next;
    }
}

// Destructor
template <typename T>
OrderedList<T>::~OrderedList() {
    clear();
}

// Assignment operator
template <typename T>
OrderedList<T>& OrderedList<T>::operator=(const OrderedList& other) {
    if (this != &other) {
        clear();
        Node* current = other.head;
        while (current != nullptr) {
            add(current->data);
            current = current->next;
        }
    }
    return *this;
}

// Add an element in order
template <typename T>
void OrderedList<T>::add(const T& value) {
    Node* newNode = new Node(value);
    if (isEmpty()) {
        head = tail = newNode;
    } else {
        Node* current = head;
        while (current != nullptr && current->data < value) {
            current = current->next;
        }

        if (current == head) {
            newNode->next = head;
            head->prev = newNode;
            head = newNode;
        } else if (current == nullptr) {
            tail->next = newNode;
            newNode->prev = tail;
            tail = newNode;
        } else {
            newNode->next = current;
            newNode->prev = current->prev;
            if (current->prev) {
                current->prev->next = newNode;
            }
            current->prev = newNode;
        }
    }
    size++;
}

// Remove a value (first occurrence)
template <typename T>
void OrderedList<T>::remove(const T& value) {
    Node* current = head;
    while (current != nullptr && current->data != value) {
        current = current->next;
    }

    if (current != nullptr) {
        deleteNode(current);
        size--;
    }
}

// Private method to delete a node
template <typename T>
void OrderedList<T>::deleteNode(Node* node) {
    if (node->prev != nullptr) {
        node->prev->next = node->next;
    } else {
        head = node->next;
    }

    if (node->next != nullptr) {
        node->next->prev = node->prev;
    } else {
        tail = node->prev;
    }

    delete node;
}

// Find a value
template <typename T>
bool OrderedList<T>::find(const T& value) const {
    Node* current = head;
    while (current != nullptr) {
        if (current->data == value) {
            return true;
        }
        current = current->next;
    }
    return false;
}

// Get the size of the list
template <typename T>
size_t OrderedList<T>::getSize() const {
    return size;
}

// Check if the list is empty
template <typename T>
bool OrderedList<T>::isEmpty() const {
    return size == 0;
}

// Clear the list
template <typename T>
void OrderedList<T>::clear() {
    Node* current = head;
    while (current != nullptr) {
        Node* next = current->next;
        delete current;
        current = next;
    }
    head = tail = nullptr;
    size = 0;
}

// Print the list in ascending order
template <typename T>
void OrderedList<T>::printAscend() const {
    Node* current = head;
    while (current != nullptr) {
        std::cout << current->data << " ";
        current = current->next;
    }
    std::cout << std::endl;
}

// Print the list in descending order
template <typename T>
void OrderedList<T>::printDescend() const {
    Node* current = tail;
    while (current != nullptr) {
        std::cout << current->data << " ";
        current = current->prev;
    }
    std::cout << std::endl;
}

// Merge two ordered lists
template <typename T>
void OrderedList<T>::merge(const OrderedList& other) {
    Node* current = other.head;
    while (current != nullptr) {
        add(current->data);
        current = current->next;
    }
}

#endif
#ifndef ORDEREDLIST_TPP
#define ORDEREDLIST_TPP

#include "OrderedList.hpp"

// Default constructor
template <typename T>
OrderedList<T>::OrderedList() : head(nullptr), tail(nullptr), size(0) {}

// Copy constructor
template <typename T>
OrderedList<T>::OrderedList(const OrderedList& other) : head(nullptr), tail(nullptr), size(0) {
    Node* current = other.head;
    while (current != nullptr) {
        add(current->data);
        current = current->next;
    }
}

// Destructor
template <typename T>
OrderedList<T>::~OrderedList() {
    clear();
}

// Assignment operator
template <typename T>
OrderedList<T>& OrderedList<T>::operator=(const OrderedList& other) {
    if (this != &other) {
        clear();
        Node* current = other.head;
        while (current != nullptr) {
            add(current->data);
            current = current->next;
        }
    }
    return *this;
}

// Add an element in order
template <typename T>
void OrderedList<T>::add(const T& value) {
    Node* newNode = new Node(value);
    if (isEmpty()) {
        head = tail = newNode;
    } else {
        Node* current = head;
        while (current != nullptr && current->data < value) {
            current = current->next;
        }

        if (current == head) {
            newNode->next = head;
            head->prev = newNode;
            head = newNode;
        } else if (current == nullptr) {
            tail->next = newNode;
            newNode->prev = tail;
            tail = newNode;
        } else {
            newNode->next = current;
            newNode->prev = current->prev;
            if (current->prev) {
                current->prev->next = newNode;
            }
            current->prev = newNode;
        }
    }
    size++;
}

// Remove a value (first occurrence)
template <typename T>
void OrderedList<T>::remove(const T& value) {
    Node* current = head;
    while (current != nullptr && current->data != value) {
        current = current->next;
    }

    if (current != nullptr) {
        deleteNode(current);
        size--;
    }
}

// Private method to delete a node
template <typename T>
void OrderedList<T>::deleteNode(Node* node) {
    if (node->prev != nullptr) {
        node->prev->next = node->next;
    } else {
        head = node->next;
    }

    if (node->next != nullptr) {
        node->next->prev = node->prev;
    } else {
        tail = node->prev;
    }

    delete node;
}

// Find a value
template <typename T>
bool OrderedList<T>::find(const T& value) const {
    Node* current = head;
    while (current != nullptr) {
        if (current->data == value) {
            return true;
        }
        current = current->next;
    }
    return false;
}

// Get the size of the list
template <typename T>
size_t OrderedList<T>::getSize() const {
    return size;
}

// Check if the list is empty
template <typename T>
bool OrderedList<T>::isEmpty() const {
    return size == 0;
}

// Clear the list
template <typename T>
void OrderedList<T>::clear() {
    Node* current = head;
    while (current != nullptr) {
        Node* next = current->next;
        delete current;
        current = next;
    }
    head = tail = nullptr;
    size = 0;
}

// Print the list in ascending order
template <typename T>
void OrderedList<T>::printAscend() const {
    Node* current = head;
    while (current != nullptr) {
        std::cout << current->data << " ";
        current = current->next;
    }
    std::cout << std::endl;
}

// Print the list in descending order
template <typename T>
void OrderedList<T>::printDescend() const {
    Node* current = tail;
    while (current != nullptr) {
        std::cout << current->data << " ";
        current = current->prev;
    }
    std::cout << std::endl;
}

// Merge two ordered lists
template <typename T>
void OrderedList<T>::merge(const OrderedList& other) {
    Node* current = other.head;
    while (current != nullptr) {
        add(current->data);
        current = current->next;
    }
}

#endif
