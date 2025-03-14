#ifndef ORDEREDLIST_TPP
#define ORDEREDLIST_TPP

#include "../Headers/OrderedList.hpp"

template <typename T>
OrderedList<T>::OrderedList() : head(nullptr), tail(nullptr), size(0) {}


template <typename T>
OrderedList<T>::OrderedList(const OrderedList& other) : head(nullptr), tail(nullptr), size(0) {
    Node* current = other.head;
    while (current != nullptr) {
        add(current->data);
        current = current->next;
    }
}


template <typename T>
OrderedList<T>::~OrderedList() {
    clear();
}


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


template <typename T>
size_t OrderedList<T>::getSize() const {
    return size;
}


template <typename T>
bool OrderedList<T>::isEmpty() const {
    return size == 0;
}


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


template <typename T>
void OrderedList<T>::printAscend() const {
    Node* current = head;
    while (current != nullptr) {
        std::cout << current->data << " ";
        current = current->next;
    }
    std::cout << std::endl;
}


template <typename T>
void OrderedList<T>::printDescend() const {
    Node* current = tail;
    while (current != nullptr) {
        std::cout << current->data << " ";
        current = current->prev;
    }
    std::cout << std::endl;
}


template <typename T>
void OrderedList<T>::merge(const OrderedList& other) {
    Node* current = other.head;
    while (current != nullptr) {
        add(current->data);
        current = current->next;
    }
}

#endif
